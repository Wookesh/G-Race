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

#include "MainWindow.hpp"
#include <QApplication>
#include <QMenuBar>

#include <QGraphicsScene>
#include <QGraphicsView>
#include "../core/PlayerGraphics.hpp"
#include "../core/FieldGraphics.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags): QMainWindow(parent, flags)
{
	createLayout();
	createActions();
	createMenus();
}

void MainWindow::createLayout()
{
	placeholder = new QWidget(this);
	
	pg = new PlayerGraphics(new Player("Andrzej"));
	field = new FieldGraphics(new Field());
	
	QGraphicsScene *scene = new QGraphicsScene();
	scene->addItem(pg);
	scene->addItem(field);
	scene->setSceneRect(-600.0, -400.0, 1200.0, 800.0);
	view = new QGraphicsView(scene);
	
	setCentralWidget(view);
}

void MainWindow::createActions()
{
	exit = new QAction(tr("Exit"), this);
	exit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	connect(exit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createMenus()
{
	menu = menuBar()->addMenu(tr("&Menu"));
	menu->addAction(exit);
}

void MainWindow::createGameController()
{
	gameController = new GameController(this);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	pg->moveBy(10.0, 10.0);
	qDebug() << pg->pos() << field->pos();
	QMainWindow::mousePressEvent(event);
	
}


