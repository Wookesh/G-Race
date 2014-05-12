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

#ifndef OPTION_MENU_HPP
#define OPTION_MENU_HPP

#include "MenuWidget.hpp"
#include <QLineEdit>
#include <QLabel>
#include <QValidator>
#include "MenuButton.hpp"
#include "../utilities/EnumHelpers.hpp"


EnumClass(GameKeys, quint8,
	Player1Move,
	Player1Power,
	Player2Move,
	Player2Power,
	Player3Move,
	Player3Power,
	Player4Move,
	Player4Power,
	StartGame,
)


const QHash<GameKeys, QString> &GameKeysStrings();


class Config : public QObject {
	Q_OBJECT
public:

	static const Qt::Key None;

	Config(QObject *parent = nullptr);

	const Qt::Key &key(GameKeys gameKey) const;
	void setKey(GameKeys gameKey, Qt::Key key);

	bool isComplete() const;
private:
	void removeKey(Qt::Key key);
	QHash<GameKeys, Qt::Key> config_;
signals:
	void configUpdated();
};

QDataStream &operator<<(QDataStream &out, const Config &config);
QDataStream &operator>>(QDataStream &in, Config &config);


/* KeyInput */


class KeyInput : public QLineEdit {
	Q_OBJECT
public :
	explicit KeyInput(GameKeys gameKey, Config *config, QWidget *parent = nullptr);
protected:
	void mousePressEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *e);
private :
	GameKeys gameKey_;
	Config *config_;
public slots:
	void updateConfig();
};


/* OptionMenu */


class OptionMenu : public MenuWidget {
	Q_OBJECT
public :
	OptionMenu(QWidget *parent = nullptr);
	virtual ~OptionMenu();
	Config *config() const;
protected:
	void mousePressEvent(QMouseEvent *);
	void closeEvent(QCloseEvent *e);
private :

	MenuButton *save_;
	MenuButton *cancel_;
	void createButtons();

	QVector<QPair<QLabel *, KeyInput *>> lineEdits_;
	void createLineEdits();

	void createLayout();

	Config *config_;
	void readConfig();

private slots:
	void save();
signals:
	void saved();
	void canceled();
};

#endif
