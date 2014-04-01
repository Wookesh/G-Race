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

#include "ObjectGraphics.hpp"


ObjectGraphics::ObjectGraphics(QGraphicsItem* parent, QVector< QString > *pathsToImages): 
	QGraphicsItem(parent)
{
	for(QString path: *pathsToImages)
	{
		this->pixMaps_.insert(QPixmap(path));
	}
}

void ObjectGraphics::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget, QPixmap pixmap)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(boundingRect(), pixmap, QRectF(0.0, 0.0, pixmap.width(), pixmap.height()));
}


