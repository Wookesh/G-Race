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
#include <QDebug>

#include "../graphics/SceneFactory.hpp"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags): QMainWindow(parent, flags)
{
	createGameController();
	createLayout();
	createActions();
	createMenus();
}

void MainWindow::createLayout()
{
	placeholder = new QWidget(this);
	view = new View(currentScene);
	view->setPlayer(*currentScene->players().begin());
	connect(currentScene, &Scene::renderView, view, &View::render);
	setCentralWidget(view);
	gameController->startGame();
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
	SceneFactory *sf = new SceneFactory();
	currentScene = sf->createScene(SceneFactory::testLong());
	Player *player = new Player("Andrzej", QPointF(262.0, 48.0));
	player->setGravity(Gravity::Up);
	gameController->addPlayer(player);
	gameController->setCollisionDetector(currentScene);
	QSet<Player *> players;
	players.insert(player);
	currentScene->setPlayers(players);
	connect(gameController, &GameController::render, currentScene, &Scene::updatePos);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	QMainWindow::mousePressEvent(event);
	
}


