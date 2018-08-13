# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shadow/Documents/cpp_indie_studio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shadow/Documents/cpp_indie_studio

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/shadow/Documents/cpp_indie_studio/CMakeFiles /home/shadow/Documents/cpp_indie_studio/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/shadow/Documents/cpp_indie_studio/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named bomberman

# Build rule for target.
bomberman: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bomberman
.PHONY : bomberman

# fast build rule for target.
bomberman/fast:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/build
.PHONY : bomberman/fast

srcs/Bomb.o: srcs/Bomb.cpp.o

.PHONY : srcs/Bomb.o

# target to build an object file
srcs/Bomb.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Bomb.cpp.o
.PHONY : srcs/Bomb.cpp.o

srcs/Bomb.i: srcs/Bomb.cpp.i

.PHONY : srcs/Bomb.i

# target to preprocess a source file
srcs/Bomb.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Bomb.cpp.i
.PHONY : srcs/Bomb.cpp.i

srcs/Bomb.s: srcs/Bomb.cpp.s

.PHONY : srcs/Bomb.s

# target to generate assembly for a file
srcs/Bomb.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Bomb.cpp.s
.PHONY : srcs/Bomb.cpp.s

srcs/Entity.o: srcs/Entity.cpp.o

.PHONY : srcs/Entity.o

# target to build an object file
srcs/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Entity.cpp.o
.PHONY : srcs/Entity.cpp.o

srcs/Entity.i: srcs/Entity.cpp.i

.PHONY : srcs/Entity.i

# target to preprocess a source file
srcs/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Entity.cpp.i
.PHONY : srcs/Entity.cpp.i

srcs/Entity.s: srcs/Entity.cpp.s

.PHONY : srcs/Entity.s

# target to generate assembly for a file
srcs/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Entity.cpp.s
.PHONY : srcs/Entity.cpp.s

srcs/Game.o: srcs/Game.cpp.o

.PHONY : srcs/Game.o

# target to build an object file
srcs/Game.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Game.cpp.o
.PHONY : srcs/Game.cpp.o

srcs/Game.i: srcs/Game.cpp.i

.PHONY : srcs/Game.i

# target to preprocess a source file
srcs/Game.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Game.cpp.i
.PHONY : srcs/Game.cpp.i

srcs/Game.s: srcs/Game.cpp.s

.PHONY : srcs/Game.s

# target to generate assembly for a file
srcs/Game.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Game.cpp.s
.PHONY : srcs/Game.cpp.s

srcs/Lib.o: srcs/Lib.cpp.o

.PHONY : srcs/Lib.o

# target to build an object file
srcs/Lib.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Lib.cpp.o
.PHONY : srcs/Lib.cpp.o

srcs/Lib.i: srcs/Lib.cpp.i

.PHONY : srcs/Lib.i

# target to preprocess a source file
srcs/Lib.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Lib.cpp.i
.PHONY : srcs/Lib.cpp.i

srcs/Lib.s: srcs/Lib.cpp.s

.PHONY : srcs/Lib.s

# target to generate assembly for a file
srcs/Lib.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Lib.cpp.s
.PHONY : srcs/Lib.cpp.s

srcs/Map.o: srcs/Map.cpp.o

.PHONY : srcs/Map.o

# target to build an object file
srcs/Map.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Map.cpp.o
.PHONY : srcs/Map.cpp.o

srcs/Map.i: srcs/Map.cpp.i

.PHONY : srcs/Map.i

# target to preprocess a source file
srcs/Map.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Map.cpp.i
.PHONY : srcs/Map.cpp.i

srcs/Map.s: srcs/Map.cpp.s

.PHONY : srcs/Map.s

# target to generate assembly for a file
srcs/Map.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Map.cpp.s
.PHONY : srcs/Map.cpp.s

srcs/Music.o: srcs/Music.cpp.o

.PHONY : srcs/Music.o

# target to build an object file
srcs/Music.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Music.cpp.o
.PHONY : srcs/Music.cpp.o

srcs/Music.i: srcs/Music.cpp.i

.PHONY : srcs/Music.i

# target to preprocess a source file
srcs/Music.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Music.cpp.i
.PHONY : srcs/Music.cpp.i

srcs/Music.s: srcs/Music.cpp.s

.PHONY : srcs/Music.s

# target to generate assembly for a file
srcs/Music.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Music.cpp.s
.PHONY : srcs/Music.cpp.s

srcs/MyEventReceiver.o: srcs/MyEventReceiver.cpp.o

.PHONY : srcs/MyEventReceiver.o

# target to build an object file
srcs/MyEventReceiver.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/MyEventReceiver.cpp.o
.PHONY : srcs/MyEventReceiver.cpp.o

srcs/MyEventReceiver.i: srcs/MyEventReceiver.cpp.i

.PHONY : srcs/MyEventReceiver.i

# target to preprocess a source file
srcs/MyEventReceiver.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/MyEventReceiver.cpp.i
.PHONY : srcs/MyEventReceiver.cpp.i

srcs/MyEventReceiver.s: srcs/MyEventReceiver.cpp.s

.PHONY : srcs/MyEventReceiver.s

# target to generate assembly for a file
srcs/MyEventReceiver.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/MyEventReceiver.cpp.s
.PHONY : srcs/MyEventReceiver.cpp.s

srcs/Player.o: srcs/Player.cpp.o

.PHONY : srcs/Player.o

# target to build an object file
srcs/Player.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Player.cpp.o
.PHONY : srcs/Player.cpp.o

srcs/Player.i: srcs/Player.cpp.i

.PHONY : srcs/Player.i

# target to preprocess a source file
srcs/Player.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Player.cpp.i
.PHONY : srcs/Player.cpp.i

srcs/Player.s: srcs/Player.cpp.s

.PHONY : srcs/Player.s

# target to generate assembly for a file
srcs/Player.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Player.cpp.s
.PHONY : srcs/Player.cpp.s

srcs/Time.o: srcs/Time.cpp.o

.PHONY : srcs/Time.o

# target to build an object file
srcs/Time.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Time.cpp.o
.PHONY : srcs/Time.cpp.o

srcs/Time.i: srcs/Time.cpp.i

.PHONY : srcs/Time.i

# target to preprocess a source file
srcs/Time.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Time.cpp.i
.PHONY : srcs/Time.cpp.i

srcs/Time.s: srcs/Time.cpp.s

.PHONY : srcs/Time.s

# target to generate assembly for a file
srcs/Time.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Time.cpp.s
.PHONY : srcs/Time.cpp.s

srcs/Window.o: srcs/Window.cpp.o

.PHONY : srcs/Window.o

# target to build an object file
srcs/Window.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Window.cpp.o
.PHONY : srcs/Window.cpp.o

srcs/Window.i: srcs/Window.cpp.i

.PHONY : srcs/Window.i

# target to preprocess a source file
srcs/Window.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Window.cpp.i
.PHONY : srcs/Window.cpp.i

srcs/Window.s: srcs/Window.cpp.s

.PHONY : srcs/Window.s

# target to generate assembly for a file
srcs/Window.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/Window.cpp.s
.PHONY : srcs/Window.cpp.s

srcs/main.o: srcs/main.cpp.o

.PHONY : srcs/main.o

# target to build an object file
srcs/main.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/main.cpp.o
.PHONY : srcs/main.cpp.o

srcs/main.i: srcs/main.cpp.i

.PHONY : srcs/main.i

# target to preprocess a source file
srcs/main.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/main.cpp.i
.PHONY : srcs/main.cpp.i

srcs/main.s: srcs/main.cpp.s

.PHONY : srcs/main.s

# target to generate assembly for a file
srcs/main.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/srcs/main.cpp.s
.PHONY : srcs/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... bomberman"
	@echo "... rebuild_cache"
	@echo "... list_install_components"
	@echo "... install/local"
	@echo "... install"
	@echo "... srcs/Bomb.o"
	@echo "... srcs/Bomb.i"
	@echo "... srcs/Bomb.s"
	@echo "... srcs/Entity.o"
	@echo "... srcs/Entity.i"
	@echo "... srcs/Entity.s"
	@echo "... srcs/Game.o"
	@echo "... srcs/Game.i"
	@echo "... srcs/Game.s"
	@echo "... srcs/Lib.o"
	@echo "... srcs/Lib.i"
	@echo "... srcs/Lib.s"
	@echo "... srcs/Map.o"
	@echo "... srcs/Map.i"
	@echo "... srcs/Map.s"
	@echo "... srcs/Music.o"
	@echo "... srcs/Music.i"
	@echo "... srcs/Music.s"
	@echo "... srcs/MyEventReceiver.o"
	@echo "... srcs/MyEventReceiver.i"
	@echo "... srcs/MyEventReceiver.s"
	@echo "... srcs/Player.o"
	@echo "... srcs/Player.i"
	@echo "... srcs/Player.s"
	@echo "... srcs/Time.o"
	@echo "... srcs/Time.i"
	@echo "... srcs/Time.s"
	@echo "... srcs/Window.o"
	@echo "... srcs/Window.i"
	@echo "... srcs/Window.s"
	@echo "... srcs/main.o"
	@echo "... srcs/main.i"
	@echo "... srcs/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

