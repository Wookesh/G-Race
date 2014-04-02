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

Scene::Scene(QWidget *parent): 
	QGraphicsScene(parent), view_(new QGraphicsView(this))
{
	view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Scene::~Scene()
{
	delete view_;
}


QList< Object* > Scene::collidingFields(QPointF corner, QPointF size) const
{
	QList<Object *> list;
	for(QGraphicsItem *item: QGraphicsScene::items(QRectF(corner, size)))
		list.push_back(static_cast<ObjectGraphics*>(item)->object());

	return list;
}

void Scene::start()
{
	
}

void Scene::finish()
{

}

void Scene::render()
{
	view_->centerOn(mainPlayer_);
	emit doneRender();
}

void Scene::setPlayer(Player *p)
{
	//FIXME chyba nie o taki konstruktor wam chodziło...
// 	MainPlayer_ = PlayerGraphics(QGraphicsItem(), QVector<QString>*, p);
	QVector<QString> paths;
	paths.push_back("../textures/crate.jpg");
	mainPlayer_ = new PlayerGraphics(&paths, p);
}

void Scene::setEnemies(QSet<Player*>* set)
{
	QVector<QString> paths;
	paths.push_back("../textures/crate.jpg"); //TODO zrobić różne obrazki
	for (Player *p: *set){
		enemies_.insert(new PlayerGraphics(&paths, p));}
}
void Scene::setMap(QGraphicsScene* )
{

}

void Scene::setPause(bool )
{

}



