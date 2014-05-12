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
#include <QDebug>



constexpr QPointF Player::Size;

Player::Player(QString name, QPointF position) : Object(position), name_(name), gravity_(Gravity::Down), falling_(true),
																 state_(State::Running), bonusSpead_(0.0), powerup1_(nullptr)
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
void Player::changeGravity()
{
    if(!isFalling()){
		if(gravity() == Gravity::Down)
			setGravity(Gravity::Up);
		else
			setGravity(Gravity::Down);
		setFalling(true);
    }
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
	return Size;
}


void Player::onStep(Object *object, Direction dir)
{
	qDebug() << "onStep";
	object->setPosition(this->position() - QPointF(QPointF(Player::size()).x(), 0.0));
}

void Player::collided(Object *object, Direction direction)
{
    switch (direction) {
        case Direction::Down : {
            if (gravity() == Gravity::Down)
                setFalling(false);
            break;
        }
        case Direction::Up : {
            if (gravity() == Gravity::Up)
                setFalling(false);
            break;
        }
		case Direction::Left :
			break;
		case Direction::Right :
			break;
			
    }
}

void Player::collided(Powerup* powerup, Direction direction)
{
	if(powerup1() == nullptr) {
		if(powerup->instant())
			usePowerup(powerup);
		else
			setPowerup1(powerup);
	}
}

void Player::setPowerup1(Powerup* powerup)
{
	powerup1_ = powerup;
}


qreal Player::bonusSpeed() const
{
	return bonusSpead_;
}

void Player::setBonusSpeed(qreal bonusSpeed)
{
	bonusSpead_ = bonusSpeed;
}




void Player::usePowerup(Powerup * powerup)
{
	if(powerup != nullptr) {
		powerup->apply(this);
		activePowerups()[powerup]  = powerup->time();
		
	}

}

void Player::endPowerup(Powerup* powerup)
{
	setPowerup1(nullptr);
	powerup->deapply(this);
}


Powerup* Player::powerup1()
{
	return powerup1_;
}

QHash<Powerup*, qint32>& Player::activePowerups()
{
	return activePowerups_;
}
