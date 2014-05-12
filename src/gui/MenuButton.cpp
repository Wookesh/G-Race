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

/* MenuButton */

#include "MenuButton.hpp"
#include <QApplication>
#include <QPainter>

const QPixmap &MenuButton::pixmap()
{
	static const QPixmap pixmap_("../textures/button1.png");
	return pixmap_;
}

const QPixmap &MenuButton::pixmapFull()
{
	static const QPixmap pixmap_("../textures/buttonClicked.png");
	return pixmap_;
}

MenuButton::MenuButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
	setFixedSize(400, 100);
}

void MenuButton::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	if (!isDown())
		painter.drawPixmap((width() - pixmap().width()) / 2, 0 , pixmap());
	else
		painter.drawPixmap((width() - pixmapFull().width()) / 2, 0, pixmapFull());
	QFont font = QApplication::font();
	font.setPointSize(30);
	painter.setFont(font);
	painter.setPen(Qt::white);
	painter.drawText(rect(), Qt::AlignCenter, text());
}

void MenuButton::mousePressEvent(QMouseEvent *e)
{
	QPushButton::mousePressEvent(e);
}

void MenuButton::mouseReleaseEvent(QMouseEvent *e)
{
	QPushButton::mouseReleaseEvent(e);
}
