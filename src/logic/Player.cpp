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

#include "Player.hpp"

Player::Player(QString name) : Object(), name_(name), gravity_(Gravity::Down)
{
	
}

QString Player::name() const
{
	return name_;
}

Gravity Player::gravity() const
{
	return gravity_;
}

void Player::setGravity(Gravity gravity)
{
	gravity_ = gravity;
}

bool Player::isFalling() const
{
	return falling_;
}

void Player::setFalling(bool falling)
{
	falling_ = falling;
}

Player::State Player::state() const
{
	return state_;
}

void Player::setState(Player::State state)
{
	state_ = state;
}

QPointF Player::size()
{
	static QPointF point = QPointF(32.0, 48.0);
	return point;
}


void Player::onStep(Object *object)
{
	object->setPosition(this->position() - QPointF(QPointF(Player::size()).x(), 0.0));
}

qreal Player::bonusSpeed() const
{
	return bonusSpead_;
}

void Player::setBonusSpeed(qreal bonusSpeed)
{
	bonusSpead_ = bonusSpeed;
}
