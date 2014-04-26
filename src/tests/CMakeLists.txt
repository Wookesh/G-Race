add_executable(test Tests.cpp)
qt5_use_modules(test Widgets Gui Test)
target_link_libraries(test graphics logic)
add_test(myTest test)