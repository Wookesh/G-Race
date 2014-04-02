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


ObjectGraphics::ObjectGraphics(QVector< QString >* pathsToImages, QGraphicsItem* parent): 
	QGraphicsItem(parent)
{
	for(QString path: *pathsToImages)
	{
		//NOTE chyba chodziło o to
		this->pixMaps_.push_back(QPixmap(path));
	}
	this->currentPixMap_ = &(pixMaps_.first());
}

void ObjectGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	//TODO
 	painter->drawPixmap(boundingRect(), *currentPixMap_, boundingRect());
}

Object *ObjectGraphics::object()
{
	return object_;
}

QRectF ObjectGraphics::boundingRect() const
{
	//FIXME co to?
// 	return QRectF(Player::size().x(), Player::size().y() + QPointF(Player::size()) * 2);
	return QRectF(object_->position(), object_->size());
}