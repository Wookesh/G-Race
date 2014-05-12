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

#ifndef PRE_GAME_MENU_HPP
#define PRE_GAME_MENU_HPP

#include "MenuWidget.hpp"
#include "MenuButton.hpp"
#include <QSignalMapper>
#include <QButtonGroup>
#include <QLineEdit>

class GameController;
class SceneFactory;

class PreGameMenu : public MenuWidget {
	Q_OBJECT
public:
	explicit PreGameMenu(QWidget *parent = nullptr);

	void setGameController(GameController *gameController);

private:

	GameController *gameController_;

	QSignalMapper *signalMapper;

	MenuButton *playButton;
	QButtonGroup *buttonGroup;
	QVector<QLineEdit *> playerNames;
	int playersNumber;

	void createLayout();
	void createButtons();
	void createLineEdits();
private slots:
	void play();
	void setPlayersNumber(int);
signals:
	void playGame();
};

#endif
