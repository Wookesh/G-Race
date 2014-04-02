add_library(logic
	Object.cpp
	Player.cpp
	Field.cpp
	GameController.cpp
	CollisionDetector.cpp
	)
qt5_use_modules(logic Core)