#include <QMainWindow>
#include <QAction>
#include <QMenu>

class MainWindow : public QMainWindow {
	Q_OBJECT
public :
	explicit MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
private :
	QAction * exit;
	QMenu * menu;
	void createMenus();
};