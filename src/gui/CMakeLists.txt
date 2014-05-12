add_executable(G-Race
	main.cpp 
	MainWindow.cpp
	MenuButton.cpp
	MenuWidget.cpp
	Menu.cpp
	OptionMenu.cpp
	PreGameMenu.cpp
	GameWindow.cpp
	)

qt5_use_modules(G-Race Widgets Gui)
target_link_libraries(G-Race graphics logic)
