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

#include "Powerup.hpp"
#include <QDebug>


constexpr QPointF Powerup::Size;

Powerup::Powerup(bool instant): instant_(instant)
{
	
}

QPointF Powerup::size()
{
	return Size;
}

void Powerup::onStep(Object *object, Direction dir)
{
	object->collided(this, dir);
}

void Powerup::collided(Object *object, Direction)
{

}


bool Powerup::instant()
{
	return instant_;
}
void Powerup::apply(Player* player)
{
	player->setBonusSpeed(5.0);
}

void Powerup::deapply(Player* player)
{
	player->setBonusSpeed(0.0);
}

qint32 Powerup::time()
{
	return time_;
}



