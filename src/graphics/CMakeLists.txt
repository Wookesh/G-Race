add_library(graphics
	PlayerGraphics.cpp
	FieldGraphics.cpp
	Scene.cpp
	)
qt5_use_modules(graphics Widgets)
target_link_libraries(graphics logic)