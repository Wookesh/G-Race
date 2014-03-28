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

#ifndef BOARD_HPP
#define BOARD_HPP

#include "../core/Map.hpp"
#include "../core/Player.hpp"

#include <QWidget>
#include <QPaintEvent>
#include <QSet>

class Board : public QWidget {
	Q_OBJECT
public :
	explicit Board(const Map * map, QWidget * parent = 0, Qt::WindowFlags f = 0);
private :
	const Map * map_;
	const Player * player_;
	const QSet<const Player *> enemies_;
public slots :
	void setPause(bool);
	void render(); // renderuje
	void start();
	void finish();
	void setPlayer(Player *);
	void setEnemies(QSet<Player *>);
signals :
	void doneRender();
};



#endif
