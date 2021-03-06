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

#ifndef SCENE_FACTORY_HPP
#define SCENE_FACTORY_HPP
#include "Scene.hpp"

/**
 * SceneFactory
 *  exumpel : 
 *   # -> field
 * 
 *  "#############\n" + 
 *  "#           #\n" +
 *  "#           #\n" +
 *  "#############\n";
 * 
 * scene*
 * QDataStream >>
 * QDataStream <<
 */

class SceneFactory {
public :
	explicit SceneFactory();
	
	static QString test1();
	static QString testLong();
	
	Scene *createScene(QString map);
// 	QDataStream &operator<<(QDataStream &out);
// 	QDataStream &operator>>(QDataStream &in);
};

#endif