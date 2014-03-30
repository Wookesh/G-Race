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

#include "Board.hpp"

Board::Board(QWidget * parent, Qt::WindowFlags f): QWidget(parent, f)
{
	
}

void Board::render()
{
	
	scene_->update(scene_->sceneRect());
	view_->centerOn(player_->position());
	view_->show();
	emit doneRender();
}

void Board::setMap(QGraphicsScene* map)
{
	scene_ = map;
}

void Board::setPlayer(Player* player)
{
	player_ = player;
}

void Board::setEnemies(QSet< Player >* enemies)
{
	enemies_ = enemies;
}

void Board::finish()
{

}
void Board::paintEvent(QPaintEvent* event)
{
QWidget::paintEvent(event);
}

void Board::setPause(bool pause)
{

}

void Board::start()
{

}



