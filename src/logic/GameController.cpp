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
#include <QDebug>

GameController::GameController(QObject *parent): QObject(parent)
{
	timer_ = new QTimer();
	QObject::connect(timer_, &QTimer::timeout, this, &GameController::timeout);
}

void GameController::setState(GameController::State state)
{
	//TODO
	state_ = state;
}

void GameController::setCollisionDetector(CollisionDetector* collisionDetector)
{
	collisionDetector_ = collisionDetector;
}


void GameController::addPlayer(Player *player)
{
	players_.insert(player);
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
	qreal dx, dy;
	for (Player *player : players_) {
		qDebug() << player->name() << player->position();
		switch (player->state()) {
			case Player::State::Pushing :
			case Player::State::Stuned : {
				break;
			}
			case Player::State::Running : {
				dx = Player::BaseSpeed;
				QList<Object *> list = collisionDetector_->collidingFields(player->position() + QPointF(dx, 0.0),
																							  Player::size());
				qDebug() << list.size();
// 				list.removeOne(player);
// 				qDebug() << list.size();
				if (!list.isEmpty()) {
					for (Object *object : list) {
						qDebug() << "object";
						qDebug() << object << player;
						object->onStep(player);
					}
				} else {
					player->setPosition(player->position() + QPointF(dx, 0.0));
				}
				break;
			}
		}
	}
	emit render();
}

