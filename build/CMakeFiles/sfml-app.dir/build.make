# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/clembastaert/Desktop/Code/IN104/repository

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clembastaert/Desktop/Code/IN104/build

# Include any dependencies generated for this target.
include CMakeFiles/sfml-app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfml-app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml-app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml-app.dir/flags.make

CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o: /Users/clembastaert/Desktop/Code/IN104/repository/src/Checkpoint.cpp
CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o: CMakeFiles/sfml-app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o -MF CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o.d -o CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o -c /Users/clembastaert/Desktop/Code/IN104/repository/src/Checkpoint.cpp

CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clembastaert/Desktop/Code/IN104/repository/src/Checkpoint.cpp > CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.i

CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clembastaert/Desktop/Code/IN104/repository/src/Checkpoint.cpp -o CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.s

CMakeFiles/sfml-app.dir/src/example.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/example.cpp.o: /Users/clembastaert/Desktop/Code/IN104/repository/src/example.cpp
CMakeFiles/sfml-app.dir/src/example.cpp.o: CMakeFiles/sfml-app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml-app.dir/src/example.cpp.o"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml-app.dir/src/example.cpp.o -MF CMakeFiles/sfml-app.dir/src/example.cpp.o.d -o CMakeFiles/sfml-app.dir/src/example.cpp.o -c /Users/clembastaert/Desktop/Code/IN104/repository/src/example.cpp

CMakeFiles/sfml-app.dir/src/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/example.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clembastaert/Desktop/Code/IN104/repository/src/example.cpp > CMakeFiles/sfml-app.dir/src/example.cpp.i

CMakeFiles/sfml-app.dir/src/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/example.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clembastaert/Desktop/Code/IN104/repository/src/example.cpp -o CMakeFiles/sfml-app.dir/src/example.cpp.s

CMakeFiles/sfml-app.dir/src/main.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/main.cpp.o: /Users/clembastaert/Desktop/Code/IN104/repository/src/main.cpp
CMakeFiles/sfml-app.dir/src/main.cpp.o: CMakeFiles/sfml-app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml-app.dir/src/main.cpp.o"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml-app.dir/src/main.cpp.o -MF CMakeFiles/sfml-app.dir/src/main.cpp.o.d -o CMakeFiles/sfml-app.dir/src/main.cpp.o -c /Users/clembastaert/Desktop/Code/IN104/repository/src/main.cpp

CMakeFiles/sfml-app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/main.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clembastaert/Desktop/Code/IN104/repository/src/main.cpp > CMakeFiles/sfml-app.dir/src/main.cpp.i

CMakeFiles/sfml-app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/main.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clembastaert/Desktop/Code/IN104/repository/src/main.cpp -o CMakeFiles/sfml-app.dir/src/main.cpp.s

CMakeFiles/sfml-app.dir/src/utils.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/utils.cpp.o: /Users/clembastaert/Desktop/Code/IN104/repository/src/utils.cpp
CMakeFiles/sfml-app.dir/src/utils.cpp.o: CMakeFiles/sfml-app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml-app.dir/src/utils.cpp.o"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml-app.dir/src/utils.cpp.o -MF CMakeFiles/sfml-app.dir/src/utils.cpp.o.d -o CMakeFiles/sfml-app.dir/src/utils.cpp.o -c /Users/clembastaert/Desktop/Code/IN104/repository/src/utils.cpp

CMakeFiles/sfml-app.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/utils.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clembastaert/Desktop/Code/IN104/repository/src/utils.cpp > CMakeFiles/sfml-app.dir/src/utils.cpp.i

CMakeFiles/sfml-app.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/utils.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clembastaert/Desktop/Code/IN104/repository/src/utils.cpp -o CMakeFiles/sfml-app.dir/src/utils.cpp.s

# Object files for target sfml-app
sfml__app_OBJECTS = \
"CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o" \
"CMakeFiles/sfml-app.dir/src/example.cpp.o" \
"CMakeFiles/sfml-app.dir/src/main.cpp.o" \
"CMakeFiles/sfml-app.dir/src/utils.cpp.o"

# External object files for target sfml-app
sfml__app_EXTERNAL_OBJECTS =

sfml-app: CMakeFiles/sfml-app.dir/src/Checkpoint.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/example.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/main.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/utils.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/build.make
sfml-app: /Users/clembastaert/Library/Frameworks/./sfml-audio.framework/Versions/2.5.1/sfml-audio
sfml-app: /Users/clembastaert/Library/Frameworks/./sfml-network.framework/Versions/2.5.1/sfml-network
sfml-app: /Users/clembastaert/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics
sfml-app: /Users/clembastaert/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window
sfml-app: /Users/clembastaert/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
sfml-app: CMakeFiles/sfml-app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sfml-app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml-app.dir/build: sfml-app
.PHONY : CMakeFiles/sfml-app.dir/build

CMakeFiles/sfml-app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml-app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml-app.dir/clean

CMakeFiles/sfml-app.dir/depend:
	cd /Users/clembastaert/Desktop/Code/IN104/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clembastaert/Desktop/Code/IN104/repository /Users/clembastaert/Desktop/Code/IN104/repository /Users/clembastaert/Desktop/Code/IN104/build /Users/clembastaert/Desktop/Code/IN104/build /Users/clembastaert/Desktop/Code/IN104/build/CMakeFiles/sfml-app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml-app.dir/depend
