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

FieldGraphics::FieldGraphics(Field* field, QGraphicsItem* parent): QGraphicsItem(parent), field_(field)
{
	
}

QRectF FieldGraphics::boundingRect() const
{
	return QRectF(pos(), pos() + (QPointF(Field::Size)) * 2);
}

void FieldGraphics::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	QPixmap pixmap = QPixmap("../textures/crate.jpg");
	painter->drawPixmap(boundingRect(), pixmap, QRectF(0.0, 0.0, 256.0, 256.0));
}

