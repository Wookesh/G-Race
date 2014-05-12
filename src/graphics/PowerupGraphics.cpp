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

#include "PowerupGraphics.hpp"

PowerupGraphics::PowerupGraphics(QVector< QString >* pathsToImages, Powerup* Powerup, QGraphicsItem* parent):
    ObjectGraphics(pathsToImages, parent), powerup_(Powerup)
{

}


Powerup *PowerupGraphics::powerup()
{
    return powerup_;
}

Object *PowerupGraphics::object()
{
    return powerup_;
}

QPointF PowerupGraphics::size()
{
    return powerup_->size();
}

QRectF PowerupGraphics::boundingRect() const
{
    return QRectF(QPointF(0.0, 0.0), powerup_->size());
}

QPainterPath PowerupGraphics::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}





