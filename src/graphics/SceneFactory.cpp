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
#include <QString>

SceneFactory::SceneFactory()
{
	
}

QString SceneFactory::test1()
{
	return  QString("##########################\n"
						 "#                        #\n"
						 "#                        #\n"
						 "#               #        #\n"
						 "#                        #\n"
						 "##########################\n");
}

QString SceneFactory::testLong()
{
	return QString("########################################################################################\n"
						"#                                                                                      #\n"
						"#                                                                                      #\n"
						"# 4 3 2 1        @           @                                                         #\n"
						"########################################################################################\n");
}


//FIXME Later
Scene *SceneFactory::createScene(QString map)
{
	if (map.isEmpty() || !map.contains('\n'))
		return nullptr;
	Scene *scene = new Scene();
	QVector<QString> graphics;
	graphics.push_front(QString("../textures/crate.jpg"));
	
	qreal x = 0.0;
	qreal y = 0.0;
	for (QChar c : map) {
		ushort ch  = c.unicode();
		switch (ch) {
			case '#' : {
				FieldGraphics *field = new FieldGraphics(&graphics, new Field());
				field->setPos(x, y);
				field->field()->setPosition(field->pos());
				scene->addItem(field);
				x += Field::Size.x();
				break;
			}
			case '@' : {
				PowerupGraphics *pg = new PowerupGraphics(&graphics, new Powerup(true));
				pg->setPos(x, y);
				pg->powerup()->setPosition(pg->pos());
				scene->addItem(pg);
				x += Field::Size.x();
				break;
			}
			case ' ': {
				x += Field::Size.x();
				break;
			}
			case '\n': {
				x = 0.0;
				y += Field::Size.y();
				break;
			}
			case '1':
			case '2':
			case '3':
			case '4': {
				scene->addStartingPos(QString(ch).toInt(), QPointF(x, y));
				x += Field::Size.x();
				break;
			}
		}
	}

	return scene;
}
