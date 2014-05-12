/* G-Race
 * Copyright (C) 2014 Łukasz Piesewicz, Tomasz Wawreniuk, Maja Zalewska, Michał Kiełek
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "OptionMenu.hpp"
#include "../logic/GRaceCommon.hpp"
#include <QFormLayout>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QDir>
#include <QFile>


const QHash<GameKeys, QString> &GameKeysStrings()
{
	static const QHash<GameKeys, QString> gameKeysStrings = QHash<GameKeys, QString>({
				{GameKeys::Player1Move,  "Player 1 Move"},
				{GameKeys::Player1Power, "Player 1 Power"},
				{GameKeys::Player2Move,  "Player 2 Move"},
				{GameKeys::Player2Power, "Player 2 Power"},
				{GameKeys::Player3Move,  "Player 3 Move"},
				{GameKeys::Player3Power, "Player 3 Power"},
				{GameKeys::Player4Move,  "Player 4 Move"},
				{GameKeys::Player4Power, "Player 4 Power"},
				{GameKeys::StartGame,    "Start Game"},
	});
	return gameKeysStrings;
}

/* Config */


const Qt::Key Config::None = Qt::Key_unknown;

Config::Config(QObject *parent) : QObject(parent)
{
	for (GameKeys gameKey : GameKeys::labels())
		config_[gameKey] = None;
}

const Qt::Key &Config::key(GameKeys gameKey) const
{
	return config_[gameKey];
}

void Config::setKey(GameKeys gameKey, Qt::Key key)
{
	removeKey(key);
	config_[gameKey] = key;
	emit configUpdated();
}

void Config::removeKey(Qt::Key key)
{
	for (GameKeys gameKey : GameKeys::labels())
		if (config_[gameKey] == key)
			config_[gameKey] = None;
}

bool Config::isComplete() const
{
	for (GameKeys gameKey : GameKeys::labels())
		if (config_[gameKey] == None)
			return false;

	return true;
}

QDataStream &operator<<(QDataStream &out, const Config &config)
{
	for (GameKeys gameKey : GameKeys::labels())
		out << gameKey << toUnderlying(config.key(gameKey));
	return out;
}

QDataStream &operator>>(QDataStream &in, Config &config)
{
	Qt::Key key;
	for (GameKeys gameKey : GameKeys::labels()) {
		in >> gameKey >> toUnderlyingRef(key);
		config.setKey(gameKey, key);
	}
	return in;
}


/* KeyInput */


KeyInput::KeyInput(GameKeys gameKey, Config *config, QWidget *parent) : QLineEdit(parent), gameKey_(gameKey), config_(config)
{
	updateConfig();
}

void KeyInput::mousePressEvent(QMouseEvent *e)
{
	setText("");
	config_->setKey(gameKey_, Config::None);
	QLineEdit::mousePressEvent(e);
}

void KeyInput::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Return) {
		parentWidget()->setFocus();
	} else {
		config_->setKey(gameKey_, static_cast<Qt::Key>(e->key()));
		setText(e->text().toUpper());
	}
}


void KeyInput::updateConfig()
{
	if (config_->key(gameKey_) != Config::None)
		setText(QKeySequence(config_->key(gameKey_)).toString());
	else
		setText("");
}


/* OptionMenu */


OptionMenu::OptionMenu(QWidget *parent) : MenuWidget(parent), config_(new Config())
{
	readConfig();
	createButtons();
	createLineEdits();
	createLayout();
}

OptionMenu::~OptionMenu()
{
}

void OptionMenu::mousePressEvent(QMouseEvent *e)
{
	setFocus();
	MenuWidget::mousePressEvent(e);
}

void OptionMenu::closeEvent(QCloseEvent *e)
{
	save();
	e->accept();
}

void OptionMenu::createLayout()
{
	QFormLayout *layout = new QFormLayout();
	layout->setFormAlignment(Qt::AlignCenter);
	for (QPair<QLabel *, QLineEdit *> p : lineEdits_) {
		layout->addRow(p.first, p.second);
	}
	layout->addRow(cancel_, save_);
	setLayout(layout);
}

void OptionMenu::createLineEdits()
{
	QPalette pal = palette();
	pal.setColor(QPalette::WindowText, Qt::white);

	for (GameKeys gameKey : GameKeys::labels()) {
		QLabel *label = new QLabel(GameKeysStrings()[gameKey]);
		label->setPalette(pal);
		KeyInput *lineEdit = new KeyInput(gameKey, config_);
		lineEdit->setMaxLength(1);
		lineEdit->setFixedWidth(100);
		connect(config_, &Config::configUpdated, lineEdit, &KeyInput::updateConfig);
		lineEdits_.push_back({label, lineEdit});
	}
}

void OptionMenu::createButtons()
{
	save_ = new MenuButton("Save");
	connect(save_, &MenuButton::clicked, this, &OptionMenu::save);

	cancel_ = new MenuButton("Cancel");
	connect(cancel_, &MenuButton::clicked, this, &OptionMenu::canceled);
}

void OptionMenu::readConfig()
{
	QDir dir = QDir::home();
	if (dir.cd(".G-Race")) {
		QFile data(dir.filePath("config.grace"));
		if (data.open(QIODevice::ReadOnly)) {
			QDataStream stream(&data);
			stream >> (*config_);
			return;
		}
	}

	config_->setKey(GameKeys::Player1Move, Qt::Key_X);
	config_->setKey(GameKeys::Player1Power, Qt::Key_C);
	config_->setKey(GameKeys::Player2Move, Qt::Key_Q);
	config_->setKey(GameKeys::Player2Power, Qt::Key_W);
	config_->setKey(GameKeys::Player3Move, Qt::Key_O);
	config_->setKey(GameKeys::Player3Power, Qt::Key_P);
	config_->setKey(GameKeys::Player4Move, Qt::Key_N);
	config_->setKey(GameKeys::Player4Power, Qt::Key_M);
	config_->setKey(GameKeys::StartGame, Qt::Key_Return);
}

void OptionMenu::save()
{
	if (config_->isComplete()) {
		QDir dir = QDir::home();
		if (!dir.cd(".G-Race")) {
			dir.mkdir(".G-Race");
			dir.cd(".G-Race");
		}
		QFile data(dir.filePath("config.grace"));
		data.open(QIODevice::WriteOnly);
		QDataStream stream(&data);
		stream << *config_;

	}
	emit saved();
}
