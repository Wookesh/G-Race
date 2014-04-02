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

#include "Field.hpp"
#include "Player.hpp"
#include <QDebug>

Field::Field(bool transparent): transparent_(transparent)
{
	
}

QPointF Field::size()
{
	static QPointF point = QPointF(32.0, 32.0);
	return point;
}

void Field::onStep(Object* object)
{
	qDebug() << object->position();
	object->setPosition(this->position() - QPointF(Player::size().x(), 0.0));
	qDebug() << object->position();
}

bool Field::isTransparent()
{
	return transparent_;
}
