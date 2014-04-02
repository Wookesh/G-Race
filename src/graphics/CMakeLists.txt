add_library(graphics
	MovingObject.cpp
	ObjectGraphics.cpp
	PlayerGraphics.cpp
	FieldGraphics.cpp
	Scene.cpp
	SceneFactory.cpp
	View.cpp
	)
qt5_use_modules(graphics Widgets)
target_link_libraries(graphics logic)