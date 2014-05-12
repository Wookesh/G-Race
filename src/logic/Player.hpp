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

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <QPointF>
#include <QString>
#include <QHash>
#include <QPair>
#include "GRaceCommon.hpp"
#include "Object.hpp"
#include "Field.hpp"
class Player;
#include "Powerup.hpp"

/**
 * Player
 * position is position of top-left corner of player box 
 */

class Player : public Object {
public :
	
	enum class State : qint8 {
		Running,
		Stuned,
		Pushing,
	};
	
	Player(QString name);
	Player(QString name, QPointF position = QPointF(0.0, 0.0));

	QString name() const;
	
	Gravity gravity() const;
	void setGravity(Gravity gravity);
	void changeGravity();
	
	bool isFalling() const;
	void setFalling(bool falling);
	
	State state() const;
	void setState(State state);
	
	qreal bonusSpeed() const;
	void setBonusSpeed(qreal bonusSpeed);
	
    void onStep(Object *object, Direction driection) override;
    virtual void collided(Object *object, Direction direction) override;
    void collided(Powerup *powerup, Direction direction);
	
	 
	void usePowerup(Powerup *powerup);
	void endPowerup(Powerup *powerup);
	Powerup* powerup1();
	void setPowerup1(Powerup *powerup);
	QHash<Powerup*, qint32> &activePowerups();
	
	virtual QPointF size();
	static constexpr qreal MaxSpeed = 16.0;
	static constexpr QPointF Size = QPointF(32.0, 48.0);
    static constexpr qreal BaseSpeed = 2.0;
	
private :
	QString name_;
	Gravity gravity_;
	bool falling_;
	State state_;
	qreal bonusSpead_;
	Powerup *powerup1_;
	QHash<Powerup*, qint32> activePowerups_;
};


#endif
