# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/pi/src/workspace/stereo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/src/workspace/stereo/build

# Include any dependencies generated for this target.
include CMakeFiles/stereo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stereo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stereo.dir/flags.make

CMakeFiles/stereo.dir/main.cpp.o: CMakeFiles/stereo.dir/flags.make
CMakeFiles/stereo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/src/workspace/stereo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stereo.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stereo.dir/main.cpp.o -c /home/pi/src/workspace/stereo/main.cpp

CMakeFiles/stereo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stereo.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/src/workspace/stereo/main.cpp > CMakeFiles/stereo.dir/main.cpp.i

CMakeFiles/stereo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stereo.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/src/workspace/stereo/main.cpp -o CMakeFiles/stereo.dir/main.cpp.s

CMakeFiles/stereo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/stereo.dir/main.cpp.o.requires

CMakeFiles/stereo.dir/main.cpp.o.provides: CMakeFiles/stereo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/stereo.dir/build.make CMakeFiles/stereo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/stereo.dir/main.cpp.o.provides

CMakeFiles/stereo.dir/main.cpp.o.provides.build: CMakeFiles/stereo.dir/main.cpp.o


CMakeFiles/stereo.dir/light_tracking.cpp.o: CMakeFiles/stereo.dir/flags.make
CMakeFiles/stereo.dir/light_tracking.cpp.o: ../light_tracking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/src/workspace/stereo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stereo.dir/light_tracking.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stereo.dir/light_tracking.cpp.o -c /home/pi/src/workspace/stereo/light_tracking.cpp

CMakeFiles/stereo.dir/light_tracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stereo.dir/light_tracking.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/src/workspace/stereo/light_tracking.cpp > CMakeFiles/stereo.dir/light_tracking.cpp.i

CMakeFiles/stereo.dir/light_tracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stereo.dir/light_tracking.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/src/workspace/stereo/light_tracking.cpp -o CMakeFiles/stereo.dir/light_tracking.cpp.s

CMakeFiles/stereo.dir/light_tracking.cpp.o.requires:

.PHONY : CMakeFiles/stereo.dir/light_tracking.cpp.o.requires

CMakeFiles/stereo.dir/light_tracking.cpp.o.provides: CMakeFiles/stereo.dir/light_tracking.cpp.o.requires
	$(MAKE) -f CMakeFiles/stereo.dir/build.make CMakeFiles/stereo.dir/light_tracking.cpp.o.provides.build
.PHONY : CMakeFiles/stereo.dir/light_tracking.cpp.o.provides

CMakeFiles/stereo.dir/light_tracking.cpp.o.provides.build: CMakeFiles/stereo.dir/light_tracking.cpp.o


# Object files for target stereo
stereo_OBJECTS = \
"CMakeFiles/stereo.dir/main.cpp.o" \
"CMakeFiles/stereo.dir/light_tracking.cpp.o"

# External object files for target stereo
stereo_EXTERNAL_OBJECTS =

stereo: CMakeFiles/stereo.dir/main.cpp.o
stereo: CMakeFiles/stereo.dir/light_tracking.cpp.o
stereo: CMakeFiles/stereo.dir/build.make
stereo: CMakeFiles/stereo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/src/workspace/stereo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stereo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stereo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stereo.dir/build: stereo

.PHONY : CMakeFiles/stereo.dir/build

CMakeFiles/stereo.dir/requires: CMakeFiles/stereo.dir/main.cpp.o.requires
CMakeFiles/stereo.dir/requires: CMakeFiles/stereo.dir/light_tracking.cpp.o.requires

.PHONY : CMakeFiles/stereo.dir/requires

CMakeFiles/stereo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stereo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stereo.dir/clean

CMakeFiles/stereo.dir/depend:
	cd /home/pi/src/workspace/stereo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/src/workspace/stereo /home/pi/src/workspace/stereo /home/pi/src/workspace/stereo/build /home/pi/src/workspace/stereo/build /home/pi/src/workspace/stereo/build/CMakeFiles/stereo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stereo.dir/depend

