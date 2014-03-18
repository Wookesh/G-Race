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

#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <QObject>
#include <QSet>
#include <QTimer>
#include "Player.hpp"
#include "Map.hpp"

class GameController : public QObject {
	Q_OBJECT;
public :
	
	enum class State : qint8 {
		PreGame,
		Active,
		Paused,
		PostGame,
	};
	
	explicit GameController();
	
	State state() const;
	
	void addPlayer(Player *player);
	QSet<const Player *> players() const;
	
	Map map() const;
	void setMap(Map *map);
	
	void reset();
	void startGame();
	
	static const int MaxPlayers = 4;
	
private :
	State state_;
	QTimer timer_;
	QSet<Player *> players_;
	Map *map_;
	bool renderDone_;
	
	void setState(State state);
	
public slots :
	void timeout(); // obsługuje timeout timera
	void renderDone();
signals :
	void setPause(bool paused);
	void render();
	void start();
	void finish();
};




#endif