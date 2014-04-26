#include <QtTest/QtTest>
#include <QObject>
#include "../logic/GameController.hpp"
#include "../graphics/Scene.hpp"
#include "../graphics/View.hpp"
#include "../graphics/SceneFactory.hpp"

class Tests : public QObject {
	Q_OBJECT
	
private:
	GameController *gameController;
	SceneFactory *sceneFactory;
	Scene *scene;
	View *view;
	
private slots:
	
	void testGravity()
	{
		gameController = new GameController(this);
		sceneFactory = new SceneFactory();
		scene = sceneFactory->createScene("\n");
		Player *player = new Player("Andrzej", QPointF(0.0, 0.0));
		gameController->addPlayer(player);
		gameController->setCollisionDetector(scene);
		QSet<Player *> players;
		players.insert(player);
		scene->setPlayers(players);
		connect(gameController, &GameController::render, scene, &Scene::updatePos);
		gameController->startGame();
		QTest::qWait(500);
		QVERIFY(player->position().x() > 0);
		QVERIFY(player->position().y() > 0);
		player->setGravity(Gravity::Up);
		QTest::qWait(1000);
		QVERIFY(player->position().y() < 0);
	}
	
	void testStop() {
		gameController = new GameController(this);
		sceneFactory = new SceneFactory();
		scene = sceneFactory->createScene("  #\n###\n");
		Player *player = new Player("Andrzej", QPointF(0.0, -16.0));
		gameController->addPlayer(player);
		gameController->setCollisionDetector(scene);
		QSet<Player *> players;
		players.insert(player);
		scene->setPlayers(players);
		connect(gameController, &GameController::render, scene, &Scene::updatePos);
		gameController->startGame();
		QTest::qWait(3000);
		QCOMPARE(player->position(), QPointF(32.0, -16.0));
	}
};

QTEST_MAIN(Tests)
#include "Tests.moc"