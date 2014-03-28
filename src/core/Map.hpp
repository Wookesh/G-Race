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

#ifndef MAP_HPP
#define MAP_HPP
#include "Field.hpp"
#include <QVector>
#include <QPointF>
#include <QRectF>
#include "GRaceCommon.hpp"

class Map {
public :
	Map();
	
	QVector<Field *> operator[](int) const;
	
	int height() const;
	void setHeigth(int);
	
	int width() const;
	void setWidth(int);
	
	const Field *fieldAt(QPointF point) const;
	const Field *neightbour(const Field *field, Direction direction) const;
	
	void generateNextSegment();
	QRectF fieldRect(QPointF point) const;
	
	
	static const int MaxHeight = 48;
	
private :
	int height_;
	int width_;
	QVector<QVector<Field *> > map_;
};

#endif