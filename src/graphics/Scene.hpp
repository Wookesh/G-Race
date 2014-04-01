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

#include "PlayerGraphics.hpp"
#include <QtWidgets/QGraphicsScene>
#include <QSet>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Scene : public QGraphicsScene {
	Q_OBJECT
public :
	explicit Scene(QWidget * parent = 0, Qt::WindowFlags f = 0);
private :
	const PlayerGraphics * MainPlayer_;
	const QSet<const PlayerGraphics *> players_;
public slots :
	void setPause(bool);
	void render(); // renderuje
	void start();
	void finish();
	void setPlayer(Player*);
	void setEnemies(QSet<Player>*);
	void setMap(QGraphicsScene*);
signals :
	void doneRender();
};



#endif