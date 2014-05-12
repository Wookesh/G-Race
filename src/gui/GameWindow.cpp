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

#include "GameWindow.hpp"
#include "QHBoxLayout"

GameWindow::GameWindow(GameController *gameController, QWidget *parent) : MenuWidget(parent), gameController_(gameController)
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
	MenuWidget::keyPressEvent(event);
}

void GameWindow::setScene(Scene *scene)
{
	currentScene_ = scene;
}

void GameWindow::startGame()
{
	//TODO add view for all players,

	View *view = new View(currentScene_);
	view->setPlayer(*currentScene_->players().begin());
	connect(currentScene_, &Scene::renderView, view, &View::render);
	QHBoxLayout *layout = new QHBoxLayout();
	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(view);
	setLayout(layout);

	gameController_->startGame();
}
