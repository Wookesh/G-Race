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

#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include "MenuWidget.hpp"
#include "../logic/Player.hpp"
#include "../logic/GameController.hpp"

#include "../graphics/View.hpp"
#include "../graphics/Scene.hpp"
#include "../graphics/SceneFactory.hpp"

class GameWindow : public MenuWidget {
public:
	GameWindow(GameController *gameController, QWidget *parent = nullptr);

	void setScene(Scene *scene);
protected:
	void keyPressEvent(QKeyEvent *event);
private:
	Scene *currentScene_;

	GameController *gameController_;
	QSet<Player *> players_;
public slots:
	void startGame();
};

#endif
