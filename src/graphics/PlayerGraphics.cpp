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

#include "PlayerGraphics.hpp"
#include <QDebug>

PlayerGraphics::PlayerGraphics(QVector<QString> *pathsToImages, Player *player, QGraphicsItem *parent): 
		ObjectGraphics(pathsToImages, parent), player_(player)
{
	setPos(player->position());
}

QPointF PlayerGraphics::size()
{
    return player_->size();
}


QRectF PlayerGraphics::boundingRect() const
{
	return QRectF(QPointF(0.0, 0.0), player_->size());
}	

Player *PlayerGraphics::player()
{
	return player_;
}
/*
QPointF size() 
{
	return player_->size();
}*/

Object *PlayerGraphics::object()
{
	return player_;
}

void PlayerGraphics::updatePos()
{
	setPos(player_->position());
}


