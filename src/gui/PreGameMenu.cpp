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

#include "PreGameMenu.hpp"
#include "../logic/GRaceCommon.hpp"
#include "../logic/GameController.hpp"
#include "../logic/Player.hpp"
#include <QRadioButton>
#include <QFormLayout>

PreGameMenu::PreGameMenu(QWidget *parent) : MenuWidget(parent), signalMapper(new QSignalMapper(this))
{
	createButtons();
	createLineEdits();
	createLayout();
}

void PreGameMenu::setGameController(GameController *gameController)
{
	gameController_ = gameController;
}

void PreGameMenu::createLayout()
{
	QFormLayout *layout = new QFormLayout();
	layout->setFormAlignment(Qt::AlignCenter);
	for (int i = 0; i < MaxPlayers; ++i) {
		layout->addRow(buttonGroup->button(i + 1), playerNames[i]);
	}
	layout->addRow(playButton);
	setLayout(layout);
}

void PreGameMenu::createButtons()
{
	QPalette pal = palette();
	pal.setColor(QPalette::WindowText, Qt::white);

	buttonGroup = new QButtonGroup(this);
	for (int i = 1; i <= MaxPlayers; ++i) {
		QRadioButton *button = new QRadioButton(QString::number(i));
		button->setPalette(pal);
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, i);
		buttonGroup->addButton(button, i);
	}

	playButton = new MenuButton("Play");
	connect(playButton, &MenuButton::clicked, this, &PreGameMenu::play);

	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(setPlayersNumber(int)));

}

void PreGameMenu::createLineEdits()
{
	for (int i = 1; i <= MaxPlayers; ++i) {
		QLineEdit *lineEdit = new QLineEdit("PlayerName"+QString::number(i));
		lineEdit->setDisabled(true);
		lineEdit->setFixedWidth(200);
		playerNames.push_back(lineEdit);
	}
}

void PreGameMenu::setPlayersNumber(int nr)
{
	playersNumber = nr;
	for (int i = 0; i < playerNames.size(); ++i) {
		playerNames[i]->setDisabled(i >= nr);
	}
}

void PreGameMenu::play()
{
	for (int i = 0; i <  playersNumber; ++i) {
		gameController_->addPlayer(new Player(playerNames[i]->text(), QPointF(0,0)));
	}
	emit playGame();
}
