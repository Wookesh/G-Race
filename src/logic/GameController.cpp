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

#include "GameController.hpp"

GameController::GameController(QObject *parent): QObject(parent)
{
	timer_ = new QTimer();
	QObject::connect(timer_, &QTimer::timeout, this, &GameController::timeout);
}

void GameController::initGame()
{
// 	SceneFactory factory;
// 	QString map("##########\n"
// 					"#        #\n"
// 					"#        #\n"
// 					"##########\n");
// 	scene_ = factory.createScene(map);
// 	players_.insert(new PlayerGraphics(new Player("Andrzej")));
// 	for (PlayerGraphics *player : players_) {
// 		scene_->addItem(player);
// 		player->setPos(64.0, 48.0);
// 	}
}

QGraphicsScene *GameController::scene()
{
	return scene_;
}


void GameController::setState(GameController::State state)
{
	//TODO
	state_ = state;
}

void GameController::addPlayer(Player *player)
{
	//players_.insert(player);
}

GameController::State GameController::state() const
{
	return state_;
}


QSet<Player *> GameController::players() const
{
	return players_;
}

void GameController::startGame()
{
	timer_->start(1000 / Frames);
}

void GameController::stopTimer()
{
	timer_->stop();
}

void GameController::timeout()
{
	for (Player *player : players_) {
		switch (player->state()) {
			case Player::State::Pushing :
			case Player::State::Stuned : {
				break;
			}
			case Player::State::Running : {
				
				break;
			}
		}
	}
	emit render();
}

