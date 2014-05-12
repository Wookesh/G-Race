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
}

void MainWindow::createLayout()
{
	stackedWidgets = new QStackedWidget(this);
	mainMenu = new Menu(this);
	optionMenu = new OptionMenu(this);
	preGameMenu = new PreGameMenu(this);
	preGameMenu->setGameController(gameController);
	gameWindow = new GameWindow(gameController, this);
	gameWindow->setScene(currentScene);
	connect(mainMenu, &Menu::options, this, &MainWindow::setOptionMenu);
	connect(mainMenu, &Menu::startGame, this, &MainWindow::prepareGame);
	connect(mainMenu, &Menu::exit, this, &MainWindow::close);
	connect(mainMenu, &Menu::exit, optionMenu, &OptionMenu::close);
	connect(optionMenu, &OptionMenu::canceled, this, &MainWindow::setMainMenu);
	connect(optionMenu, &OptionMenu::saved, this, &MainWindow::setMainMenu);
	connect(preGameMenu, &PreGameMenu::playGame, this, &MainWindow::startGame);
	stackedWidgets->addWidget(mainMenu);
	stackedWidgets->addWidget(optionMenu);
	stackedWidgets->addWidget(preGameMenu);
	stackedWidgets->addWidget(gameWindow);
	setCentralWidget(stackedWidgets);
}

void MainWindow::createGameController()
{
	SceneFactory *sf = new SceneFactory();
	gameController = new GameController(this);
	currentScene = sf->createScene(SceneFactory::testLong());
	gameController->setCollisionDetector(currentScene);
	connect(gameController, &GameController::render, currentScene, &Scene::updatePos);
}

void MainWindow::setOptionMenu()
{
	stackedWidgets->setCurrentWidget(optionMenu);
}

void MainWindow::setMainMenu()
{
	stackedWidgets->setCurrentWidget(mainMenu);
}

void MainWindow::prepareGame()
{
	stackedWidgets->setCurrentWidget(preGameMenu);
}

void MainWindow::startGame()
{
	gameWindow->startGame();
	stackedWidgets->setCurrentWidget(gameWindow);
}


