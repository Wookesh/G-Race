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

#ifndef POWERUP_HPP
#define POWERUP_HPP
#include "Object.hpp"
class Powerup;
#include "Player.hpp"



class Powerup : public Object {
public :
	explicit Powerup(bool instant = false);
	
	virtual void onStep(Object *object, Direction);
    void collided(Object *object, Direction);
	virtual QPointF size();
	static constexpr QPointF Size = Object::Size;
	
	virtual void apply(Player* player);
	virtual void deapply(Player* player);
	virtual bool instant();
	virtual bool used();
	void setUsed(bool used);
	virtual qint32 time();
private:
	bool instant_;
	bool used_;
	qint32 time_ = 3 * Frames;
};

#endif
