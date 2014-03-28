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

void GameController::setMap(Map* map)
{
	map_ = map;
}

void GameController::setState(GameController::State state)
{
	//TODO
	state_ = state;
}

void GameController::addPlayer(Player *player)
{
	players_.insert(player);
}

GameController::State GameController::state() const
{
	return state_;
}

Map *GameController::map() const
{
	return map_;
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
	for (Player * player : players_) {
		qreal dx, dy = 0.0;
		qreal speedx = baseSpeed + player->bonusSpeed();
		qreal speedy = baseSpeed;
		const Field *field = nullptr;
		QPointF point;
		QRectF rect;
		switch (player->state()) {
			case Player::State::Pushing :
			case Player::State::Stuned : {
				dx = 0.0;
				break;
			}
			case Player::State::Running : {
				point = player->position() + QPointF(speedx, 0.0);
				field = map_->neightbour(map_->fieldAt(point), Direction::Right);
				rect = map_->fieldRect(player->position()); 
				if (rect.contains(point)) {
					dx = speedx;
				} else {
					if (field->isTransparent()) {
						dx = speedx;
					} else {
						dx = rect.right();
					}
				}
				break;
			}
		}
// 		if (player->isFalling()) {
// 			point = player->position() + QPointF(0.0, speedy);
// 			field = map_->neightbour(map_->fieldAt(point), 
// 									player->gravity() == Gravity::Down ? Direction::Up : Direction::Down);
// 			rect = map_->fieldRect(player->position()); 
// 			if (rect.contains(point)) {
// 				dy = speedy;
// 			} else {
// 				if (field->isTransparent()) {
// 					dy = speedy;
// 				} else {
// 					dy = player->gravity() == Gravity::Down ? rect.bottom() - Player::Size.y() : rect.top();
// 				}
// 			}
// 		} else {
// 			dy = 0.0;
// 		}
		player->setPosition(player->position() + QPointF(dx, dy));
	}
	emit render();
}

