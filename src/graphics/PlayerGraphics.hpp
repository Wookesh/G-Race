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

#ifndef PLAYER_GRAPHICS_HPP
#define PLAYER_GRAPHICS_HPP

#include "ObjectGraphics.hpp"
#include "MovingObject.hpp"
#include "../logic/Player.hpp"


class PlayerGraphics : public ObjectGraphics, public MovingObject {
public :
	explicit PlayerGraphics(QVector<QString> *pathsToImages = 0, Player *player = 0, QGraphicsItem *parent = 0);
	QRectF boundingRect() const override;
	QPointF size() override;
	Player *player();
	virtual Object *object();
	virtual void updatePos() override;
private :
	Player *player_;
};

#endif