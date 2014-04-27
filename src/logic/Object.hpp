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

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <QPointF>
#include "GRaceCommon.hpp"

class Object {
public :
	Object(QPointF position = QPointF(0.0, 0.0));
	
	QPointF position() const;
	void setPosition(QPointF position);
	
	virtual void onStep(Object *object, Direction) = 0;

    virtual void collided(Object *object, Direction) = 0;
	
	virtual QPointF size();
	static constexpr QPointF Size = QPointF(32.0, 32.0);
protected :
	QPointF position_;
};

#endif
