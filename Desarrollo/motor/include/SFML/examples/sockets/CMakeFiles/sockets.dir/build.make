# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\SFML

# Include any dependencies generated for this target.
include examples/sockets/CMakeFiles/sockets.dir/depend.make

# Include the progress variables for this target.
include examples/sockets/CMakeFiles/sockets.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sockets/CMakeFiles/sockets.dir/flags.make

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/flags.make
examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/includes_CXX.rsp
examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj: examples/sockets/Sockets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sockets.dir\Sockets.cpp.obj -c C:\SFML\examples\sockets\Sockets.cpp

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sockets.dir/Sockets.cpp.i"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\SFML\examples\sockets\Sockets.cpp > CMakeFiles\sockets.dir\Sockets.cpp.i

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sockets.dir/Sockets.cpp.s"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\SFML\examples\sockets\Sockets.cpp -o CMakeFiles\sockets.dir\Sockets.cpp.s

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.requires:

.PHONY : examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.requires

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.provides: examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.requires
	$(MAKE) -f examples\sockets\CMakeFiles\sockets.dir\build.make examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.provides.build
.PHONY : examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.provides

examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.provides.build: examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj


examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/flags.make
examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/includes_CXX.rsp
examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj: examples/sockets/TCP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sockets.dir\TCP.cpp.obj -c C:\SFML\examples\sockets\TCP.cpp

examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sockets.dir/TCP.cpp.i"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\SFML\examples\sockets\TCP.cpp > CMakeFiles\sockets.dir\TCP.cpp.i

examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sockets.dir/TCP.cpp.s"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\SFML\examples\sockets\TCP.cpp -o CMakeFiles\sockets.dir\TCP.cpp.s

examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.requires:

.PHONY : examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.requires

examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.provides: examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.requires
	$(MAKE) -f examples\sockets\CMakeFiles\sockets.dir\build.make examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.provides.build
.PHONY : examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.provides

examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.provides.build: examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj


examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/flags.make
examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj: examples/sockets/CMakeFiles/sockets.dir/includes_CXX.rsp
examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj: examples/sockets/UDP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sockets.dir\UDP.cpp.obj -c C:\SFML\examples\sockets\UDP.cpp

examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sockets.dir/UDP.cpp.i"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\SFML\examples\sockets\UDP.cpp > CMakeFiles\sockets.dir\UDP.cpp.i

examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sockets.dir/UDP.cpp.s"
	cd /d C:\SFML\examples\sockets && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\SFML\examples\sockets\UDP.cpp -o CMakeFiles\sockets.dir\UDP.cpp.s

examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.requires:

.PHONY : examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.requires

examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.provides: examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.requires
	$(MAKE) -f examples\sockets\CMakeFiles\sockets.dir\build.make examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.provides.build
.PHONY : examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.provides

examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.provides.build: examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj


# Object files for target sockets
sockets_OBJECTS = \
"CMakeFiles/sockets.dir/Sockets.cpp.obj" \
"CMakeFiles/sockets.dir/TCP.cpp.obj" \
"CMakeFiles/sockets.dir/UDP.cpp.obj"

# External object files for target sockets
sockets_EXTERNAL_OBJECTS =

examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/build.make
examples/sockets/sockets.exe: lib/libsfml-network-s.a
examples/sockets/sockets.exe: lib/libsfml-system-s.a
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/linklibs.rsp
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/objects1.rsp
examples/sockets/sockets.exe: examples/sockets/CMakeFiles/sockets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sockets.exe"
	cd /d C:\SFML\examples\sockets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sockets.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sockets/CMakeFiles/sockets.dir/build: examples/sockets/sockets.exe

.PHONY : examples/sockets/CMakeFiles/sockets.dir/build

examples/sockets/CMakeFiles/sockets.dir/requires: examples/sockets/CMakeFiles/sockets.dir/Sockets.cpp.obj.requires
examples/sockets/CMakeFiles/sockets.dir/requires: examples/sockets/CMakeFiles/sockets.dir/TCP.cpp.obj.requires
examples/sockets/CMakeFiles/sockets.dir/requires: examples/sockets/CMakeFiles/sockets.dir/UDP.cpp.obj.requires

.PHONY : examples/sockets/CMakeFiles/sockets.dir/requires

examples/sockets/CMakeFiles/sockets.dir/clean:
	cd /d C:\SFML\examples\sockets && $(CMAKE_COMMAND) -P CMakeFiles\sockets.dir\cmake_clean.cmake
.PHONY : examples/sockets/CMakeFiles/sockets.dir/clean

examples/sockets/CMakeFiles/sockets.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\SFML C:\SFML\examples\sockets C:\SFML C:\SFML\examples\sockets C:\SFML\examples\sockets\CMakeFiles\sockets.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sockets/CMakeFiles/sockets.dir/depend

