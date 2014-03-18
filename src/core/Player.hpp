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
#include "GRaceCommon.hpp"

class Player {
public :
	Player(QString name);
	Player(const Player &other);
	
	QString name() const;
	QPointF position() const;
	void setPosition(QPointF position);
	
	Gravity gravity() const;
	void setGravity(Gravity gravity);
private :
	QString name_;
	Gravity gravity_;
	QPointF position_;
};


#endif