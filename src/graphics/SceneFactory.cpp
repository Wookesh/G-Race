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

#include "SceneFactory.hpp"
#include "FieldGraphics.hpp"
#include <QDebug>

SceneFactory::SceneFactory()
{
	
}


//FIXME Later
Scene *SceneFactory::createScene(QString map)
{
	if (map.isEmpty() || !map.contains('\n'))
		return nullptr;
	Scene *scene = new Scene();
	
	qreal x = 0.0;
	qreal y = 0.0;
// 	qreal length = map.indexOf('\n') * QPointF(Field::Size).x();
// 	qreal height = map.lastIndexOf('\n') * QPointF(Field::Size).y() / length;
// 	scene->setSceneRect(QRectF(0.0, 0.0, length, height));
	for (QChar c : map) {
		ushort ch  = c.unicode();
		switch (ch) {
			case '#' : {
				FieldGraphics *field = new FieldGraphics(new Field());
				field->setPos(x, y);
				qDebug() << field->boundingRect();
				scene->addItem(field);
				x += QPointF(Field::Size).x();
				break;
			}
			case ' ': {
				x += QPointF(Field::Size).x();
				break;
			}
			case '\n': {
				x = 0.0;
				y += QPointF(Field::Size).y();
				break;
			}
		}
		qDebug() << x << y;
	}

	return scene;
}
