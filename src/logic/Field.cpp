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
#include <QDebug>


constexpr QPointF Field::Size;

Field::Field(bool transparent): transparent_(transparent)
{
	
}

QPointF Field::size()
{
	return Size;
}

void Field::onStep(Object *object, Direction dir)
{
	qDebug() << "Field " << this->position();
	switch (dir) {
		case Direction::Right : {
			object->setPosition(QPointF(this->position().x() - object->size().x() , object->position().y()));
			break;
		}
		case Direction::Down : {
			object->setPosition(QPointF(object->position().x() , this->position().y() - object->size().y()));
            object->collided(this, dir);
			break;
		}
		case Direction::Up : {
			object->setPosition(QPointF(object->position().x() , this->position().y() + this->size().y()));
            object->collided(this, dir);
			break;
		}
	}
	
	
// 	object->setPosition(object->position());
	qDebug() << object->position();
}

void Field::collided(Object *object, Direction)
{

}


bool Field::isTransparent()
{
	return transparent_;
}
