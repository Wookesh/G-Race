#include "MainWindow.hpp"
#include <QApplication>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags): QMainWindow(parent, flags)
{
	exit = new QAction(tr("Exit"),this);
	exit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	connect(exit, SIGNAL(triggered()), qApp, SLOT(quit()));
	createMenus();
}

void MainWindow::createMenus()
{
	menu = menuBar()->addMenu(tr("&Menu"));
	menu->addAction(exit);
}