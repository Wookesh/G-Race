add_library(graphics
	ObjectGraphics.cpp
	PlayerGraphics.cpp
	FieldGraphics.cpp
	Scene.cpp
	View.cpp
	)
qt5_use_modules(graphics Widgets)
target_link_libraries(graphics logic)