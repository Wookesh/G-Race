add_executable(G-Race main.cpp MainWindow.cpp)
qt5_use_modules(G-Race Widgets Gui)
# target_link_libraries(G-Race board core)
target_link_libraries(G-Race)