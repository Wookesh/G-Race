add_library(core 
	PlayerGraphics.cpp
	Player.cpp
	FieldGraphics.cpp
	Field.cpp
	)

add_library(logic
	GameController.cpp
	)

qt5_use_modules(core Core)
qt5_use_modules(logic Core)