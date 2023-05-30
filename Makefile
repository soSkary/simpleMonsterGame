# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1299/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1299/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/soskary/VSCode_projects/simpleMonsterGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/soskary/VSCode_projects/simpleMonsterGame

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/1299/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/1299/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/soskary/VSCode_projects/simpleMonsterGame/CMakeFiles /home/soskary/VSCode_projects/simpleMonsterGame//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/soskary/VSCode_projects/simpleMonsterGame/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MonsterGame

# Build rule for target.
MonsterGame: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MonsterGame
.PHONY : MonsterGame

# fast build rule for target.
MonsterGame/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/build
.PHONY : MonsterGame/fast

game.o: game.cpp.o
.PHONY : game.o

# target to build an object file
game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/game.cpp.o
.PHONY : game.cpp.o

game.i: game.cpp.i
.PHONY : game.i

# target to preprocess a source file
game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/game.cpp.i
.PHONY : game.cpp.i

game.s: game.cpp.s
.PHONY : game.s

# target to generate assembly for a file
game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/game.cpp.s
.PHONY : game.cpp.s

gameObject.o: gameObject.cpp.o
.PHONY : gameObject.o

# target to build an object file
gameObject.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/gameObject.cpp.o
.PHONY : gameObject.cpp.o

gameObject.i: gameObject.cpp.i
.PHONY : gameObject.i

# target to preprocess a source file
gameObject.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/gameObject.cpp.i
.PHONY : gameObject.cpp.i

gameObject.s: gameObject.cpp.s
.PHONY : gameObject.s

# target to generate assembly for a file
gameObject.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/gameObject.cpp.s
.PHONY : gameObject.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/main.cpp.s
.PHONY : main.cpp.s

map.o: map.cpp.o
.PHONY : map.o

# target to build an object file
map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/map.cpp.o
.PHONY : map.cpp.o

map.i: map.cpp.i
.PHONY : map.i

# target to preprocess a source file
map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/map.cpp.i
.PHONY : map.cpp.i

map.s: map.cpp.s
.PHONY : map.s

# target to generate assembly for a file
map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/map.cpp.s
.PHONY : map.cpp.s

textureManager.o: textureManager.cpp.o
.PHONY : textureManager.o

# target to build an object file
textureManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/textureManager.cpp.o
.PHONY : textureManager.cpp.o

textureManager.i: textureManager.cpp.i
.PHONY : textureManager.i

# target to preprocess a source file
textureManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/textureManager.cpp.i
.PHONY : textureManager.cpp.i

textureManager.s: textureManager.cpp.s
.PHONY : textureManager.s

# target to generate assembly for a file
textureManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/textureManager.cpp.s
.PHONY : textureManager.cpp.s

vector2D.o: vector2D.cpp.o
.PHONY : vector2D.o

# target to build an object file
vector2D.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/vector2D.cpp.o
.PHONY : vector2D.cpp.o

vector2D.i: vector2D.cpp.i
.PHONY : vector2D.i

# target to preprocess a source file
vector2D.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/vector2D.cpp.i
.PHONY : vector2D.cpp.i

vector2D.s: vector2D.cpp.s
.PHONY : vector2D.s

# target to generate assembly for a file
vector2D.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MonsterGame.dir/build.make CMakeFiles/MonsterGame.dir/vector2D.cpp.s
.PHONY : vector2D.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... MonsterGame"
	@echo "... game.o"
	@echo "... game.i"
	@echo "... game.s"
	@echo "... gameObject.o"
	@echo "... gameObject.i"
	@echo "... gameObject.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... map.o"
	@echo "... map.i"
	@echo "... map.s"
	@echo "... textureManager.o"
	@echo "... textureManager.i"
	@echo "... textureManager.s"
	@echo "... vector2D.o"
	@echo "... vector2D.i"
	@echo "... vector2D.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

