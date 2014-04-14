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

#include "FieldGraphics.hpp"

FieldGraphics::FieldGraphics(QVector< QString >* pathsToImages, Field* field, QGraphicsItem* parent):
	ObjectGraphics(pathsToImages, parent), field_(field)
{
	
}


Field *FieldGraphics::field()
{
	return field_;
}

Object *FieldGraphics::object()
{
	return field_;
}

QPointF FieldGraphics::size()
{
	return Field::size();
}

QRectF FieldGraphics::boundingRect() const
{
	return QRectF(QPointF(0.0, 0.0), Field::size());
}

QPainterPath FieldGraphics::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}





