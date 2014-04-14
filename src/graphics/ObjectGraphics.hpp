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

#ifndef OBJECT_GRAPHICS_HPP
#define OBJECT_GRAPHICS_HPP

#include <QVector>
#include <QString>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include "../logic/Object.hpp"

class ObjectGraphics : public QGraphicsItem {
public :
	ObjectGraphics(QVector<QString> *pathsToImages = 0, QGraphicsItem *parent = 0);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual QPointF size();
	virtual Object *object();
	virtual QRectF boundingRect() const override;
	virtual QPainterPath shape() const override;
protected:
	QVector<QPixmap> pixMaps_;
	Object *object_;
	QPixmap *currentPixMap_; //raczej temp
};

#endif