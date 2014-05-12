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
	collisionDetector_->addPlayer(player);
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
// 		qDebug() << "przed powerupami";
		for(Powerup* powerup : player->activePowerups().keys()){
			qDebug() << "skonczy sie za : " << player->activePowerups()[powerup] ;
			if(player->activePowerups()[powerup] > 0)
				player->activePowerups()[powerup] = player->activePowerups()[powerup] - 1;
			else
				player->endPowerup(powerup);
		}
		
// 		qDebug() << "i po powerupamach";
		
		qDebug() << player->name() << player->position() <<player->bonusSpeed();
		switch (player->state()) {
			case Player::State::Pushing :
			case Player::State::Stuned : {
				break;
			}
			case Player::State::Running : {
				dx = Player::BaseSpeed + player->bonusSpeed();
				QPointF newPos = player->position() + QPointF(dx, 0.0);
				QList<Object *> list = collisionDetector_->collidingFields(newPos, player->size());
//                 qDebug() << "Objects collided on move right : " << list.size();
				list.removeOne(player);
				if (!list.isEmpty()) {
					for (Object *object : list) {
						object->onStep(player, Direction::Right);
					}
				} else {
					player->setPosition(player->position() + QPointF(dx, 0.0));
				}
				break;
			}
		}
		dy = Player::BaseSpeed + player->bonusSpeed();
		if(player->gravity() == Gravity::Up)
			dy = -dy;
		QPointF newPos = player->position() + QPointF(0.0, dy);
		QList<Object *> list = collisionDetector_->collidingFields(newPos, player->size());
//         qDebug() << "Objects collided on fall : " << list.size();
		list.removeOne(player);
		if (!list.isEmpty()) {
			for (Object *object : list) {
				object->onStep(player, player->gravity() == Gravity::Down ? Direction::Down : Direction::Up);
			}
		} else {
			player->setFalling(true);
			player->setPosition(player->position() + QPointF(0.0, dy));
		}
		
	}
	emit render();
}

