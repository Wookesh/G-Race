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

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include "../logic/GameController.hpp"
#include <QMouseEvent>
#include "../graphics/PlayerGraphics.hpp"
#include "../graphics/FieldGraphics.hpp"
#include <QGraphicsView>

class MainWindow : public QMainWindow {
	Q_OBJECT
public :
	explicit MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
protected:
	void mousePressEvent(QMouseEvent * event);
private :
	
	GameController * gameController;
	PlayerGraphics * pg;
	FieldGraphics * field;
	QGraphicsView * view;
	
	QWidget * placeholder;
	QAction * exit;
	QMenu * menu;
	void createMenus();
	void createActions();
	void createLayout();
	void createGameController();
};