# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/digishek/CLionProjects/C8 Emulator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/chip8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/chip8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chip8.dir/flags.make

CMakeFiles/chip8.dir/main.cpp.o: CMakeFiles/chip8.dir/flags.make
CMakeFiles/chip8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chip8.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chip8.dir/main.cpp.o -c "/home/digishek/CLionProjects/C8 Emulator/main.cpp"

CMakeFiles/chip8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chip8.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/digishek/CLionProjects/C8 Emulator/main.cpp" > CMakeFiles/chip8.dir/main.cpp.i

CMakeFiles/chip8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chip8.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/digishek/CLionProjects/C8 Emulator/main.cpp" -o CMakeFiles/chip8.dir/main.cpp.s

# Object files for target chip8
chip8_OBJECTS = \
"CMakeFiles/chip8.dir/main.cpp.o"

# External object files for target chip8
chip8_EXTERNAL_OBJECTS =

chip8: CMakeFiles/chip8.dir/main.cpp.o
chip8: CMakeFiles/chip8.dir/build.make
chip8: CMakeFiles/chip8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chip8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chip8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chip8.dir/build: chip8
.PHONY : CMakeFiles/chip8.dir/build

CMakeFiles/chip8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chip8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chip8.dir/clean

CMakeFiles/chip8.dir/depend:
	cd "/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/digishek/CLionProjects/C8 Emulator" "/home/digishek/CLionProjects/C8 Emulator" "/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug" "/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug" "/home/digishek/CLionProjects/C8 Emulator/cmake-build-debug/CMakeFiles/chip8.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/chip8.dir/depend
