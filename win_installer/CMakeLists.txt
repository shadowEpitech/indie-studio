cmake_minimum_required(VERSION 3.7.1)

project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
	set(CMAKE_CXX_FLAGS -L.)
	INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/includes)
	INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/win_installer/includes)
	link_directories(irrKlang-1.6.0/bin/win32-gcc)
	link_libraries(opengl32)
	link_libraries(glu32)
	add_executable(bomberman_install
			includes/Game.hpp
			srcs/Game.cpp
			win_installer/srcs/Windows.cpp
			win_installer/includes/Windows.hpp
			includes/Music.hpp
			includes/Window.hpp
			srcs/Window.cpp
			includes/Entity.hpp
			includes/Map.hpp
			includes/Lib.hpp
			includes/MyEventReceiver.hpp
			srcs/Music.cpp
			srcs/MyEventReceiver.cpp
			srcs/Entity.cpp
			srcs/Lib.cpp
			srcs/Map.cpp
			includes/Player.hpp
			srcs/Time.cpp
			includes/Time.hpp
			srcs/Player.cpp
			win_installer/srcs/main.cpp
			win_installer/srcs/Installer.cpp
			win_installer/includes/Installer.hpp
			rc/bomberman_install.rc)
	target_link_libraries(bomberman_install
			${OPENGL32_LIBRAIRIES}
			${GLU32_LIBRAIRIES}
			${IRRLICHT_LIBRARIES}
			${IRRKLANG_LIBRARIES}
			"irrKlang.dll"
			"Irrlicht.dll"
			)
	add_executable(bomberman
			includes/Game.hpp
			srcs/Game.cpp
			includes/Music.hpp
			includes/Window.hpp
			srcs/Window.cpp
			includes/Entity.hpp
			includes/Map.hpp
			includes/Lib.hpp
			includes/MyEventReceiver.hpp
			srcs/Music.cpp
			srcs/MyEventReceiver.cpp
			srcs/Entity.cpp
			srcs/Lib.cpp
			srcs/Map.cpp
			includes/Player.hpp
			srcs/Time.cpp
			includes/Time.hpp
			srcs/Player.cpp
			srcs/main.cpp
			rc/bomberman.rc)
	target_link_libraries(bomberman
			${OPENGL32_LIBRAIRIES}
			${GLU32_LIBRAIRIES}
			${IRRLICHT_LIBRARIES}
			${IRRKLANG_LIBRARIES}
			"irrKlang.dll"
			"Irrlicht.dll"
			)
	add_custom_command(TARGET bomberman
			POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bomberman> Bomberman)
endif(WIN32)

if (UNIX)

	set(CMAKE_SOURCE_DIR build)

	find_package(X11 REQUIRED)
	find_package(GLUT REQUIRED)
	find_package(ZLIB REQUIRED)
	find_package(OpenGL REQUIRED)
	find_package(Threads REQUIRED)

	link_libraries("Xxf86vm")
	link_libraries(Irrlicht)

	include_directories(${PROJECT_SOURCE_DIR}/includes)

	link_directories(irrlicht-1.8.4/lib/Linux)
	link_directories(irrKlang-64bit-1.6.0/bin/linux-gcc-64)

	add_executable(bomberman
			includes/Music.hpp
			srcs/Music.cpp
			includes/Entity.hpp
			includes/Map.hpp
			includes/Lib.hpp
			includes/MyEventReceiver.hpp
			srcs/MyEventReceiver.cpp
			srcs/Entity.cpp
			srcs/Lib.cpp
			srcs/Map.cpp
			srcs/main.cpp
			srcs/Window.cpp
			srcs/Game.cpp
			includes/Game.hpp
			includes/Player.hpp
			srcs/Player.cpp
			srcs/Time.cpp
			includes/Time.hpp)

	target_link_libraries(bomberman
			${X11_LIBRARIES}
			${GLUT_LIBRARY}
			${ZLIB_LIBRARIES}
			${OPENGL_LIBRARIES}
			"libIrrlicht.a"
			"libIrrKlang.so")

install(TARGETS bomberman DESTINATION /usr/bin)

install(FILES
	irrlicht-1.8.4/lib/Linux/libIrrlicht.a
	irrKlang-64bit-1.6.0/bin/linux-gcc-64/libIrrKlang.so
	DESTINATION lib)
install(DIRECTORY
	assets
	irrlicht-1.8.4
	DESTINATION /usr/share)
endif(UNIX)
