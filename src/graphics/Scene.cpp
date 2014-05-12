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

#include "Scene.hpp"
#include <QDebug>

Scene::Scene(QWidget *parent): 
	QGraphicsScene(parent)
{
}

Scene::~Scene()
{
}


QList<Object *> Scene::collidingFields(QPointF corner, QPointF size) const
{
	QList<Object *> list;
	for (QGraphicsItem *item : QGraphicsScene::items(corner.x(), corner.y(), size.x(), size.y(), Qt::IntersectsItemShape, Qt::AscendingOrder))
		list.push_back(static_cast<ObjectGraphics *>(item)->object());

	return list;
}

void Scene::start()
{
	
}

void Scene::finish()
{

}

void Scene::updatePos()
{
	for (MovingObject *object: movingObjects_) {
		object->updatePos();
	}
	update();
	emit renderView();
}

void Scene::addPlayer(Player *player)
{
	QVector<QString> paths;
	paths.push_back("../textures/andrzej.png");
	PlayerGraphics  *newPlayerGraphics = new PlayerGraphics(&paths, player);
	players_.insert(newPlayerGraphics);
	movingObjects_.insert(newPlayerGraphics);
	QGraphicsScene::addItem(newPlayerGraphics);
}


void Scene::setPlayers(const QSet<Player *> &set)
{
	QVector<QString> paths;
	paths.push_back("../textures/andrzej.png"); //TODO zrobić różne obrazki
	for (Player *p: set) {
		PlayerGraphics  *newPlayerGraphics = new PlayerGraphics(&paths, p);
		players_.insert(newPlayerGraphics);
		movingObjects_.insert(newPlayerGraphics);
		QGraphicsScene::addItem(newPlayerGraphics);
	}
}

QSet< PlayerGraphics* > Scene::players()
{
	return players_;
}


void Scene::setPause(bool )
{

}

void Scene::keyPressEvent(QKeyEvent* event)
{
	if(event->key() == Qt::Key_X){
		for(PlayerGraphics *player : players_ )
			player->player()->changeGravity();
		
	}
		
	QGraphicsScene::keyPressEvent(event);
}




