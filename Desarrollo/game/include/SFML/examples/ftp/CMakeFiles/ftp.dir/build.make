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
include examples/ftp/CMakeFiles/ftp.dir/depend.make

# Include the progress variables for this target.
include examples/ftp/CMakeFiles/ftp.dir/progress.make

# Include the compile flags for this target's objects.
include examples/ftp/CMakeFiles/ftp.dir/flags.make

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj: examples/ftp/CMakeFiles/ftp.dir/flags.make
examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj: examples/ftp/CMakeFiles/ftp.dir/includes_CXX.rsp
examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj: examples/ftp/Ftp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj"
	cd /d C:\SFML\examples\ftp && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ftp.dir\Ftp.cpp.obj -c C:\SFML\examples\ftp\Ftp.cpp

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp.dir/Ftp.cpp.i"
	cd /d C:\SFML\examples\ftp && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\SFML\examples\ftp\Ftp.cpp > CMakeFiles\ftp.dir\Ftp.cpp.i

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp.dir/Ftp.cpp.s"
	cd /d C:\SFML\examples\ftp && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\SFML\examples\ftp\Ftp.cpp -o CMakeFiles\ftp.dir\Ftp.cpp.s

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.requires:

.PHONY : examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.requires

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.provides: examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.requires
	$(MAKE) -f examples\ftp\CMakeFiles\ftp.dir\build.make examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.provides.build
.PHONY : examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.provides

examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.provides.build: examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj


# Object files for target ftp
ftp_OBJECTS = \
"CMakeFiles/ftp.dir/Ftp.cpp.obj"

# External object files for target ftp
ftp_EXTERNAL_OBJECTS =

examples/ftp/ftp.exe: examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj
examples/ftp/ftp.exe: examples/ftp/CMakeFiles/ftp.dir/build.make
examples/ftp/ftp.exe: lib/libsfml-network-s.a
examples/ftp/ftp.exe: lib/libsfml-system-s.a
examples/ftp/ftp.exe: examples/ftp/CMakeFiles/ftp.dir/linklibs.rsp
examples/ftp/ftp.exe: examples/ftp/CMakeFiles/ftp.dir/objects1.rsp
examples/ftp/ftp.exe: examples/ftp/CMakeFiles/ftp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\SFML\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ftp.exe"
	cd /d C:\SFML\examples\ftp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ftp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/ftp/CMakeFiles/ftp.dir/build: examples/ftp/ftp.exe

.PHONY : examples/ftp/CMakeFiles/ftp.dir/build

examples/ftp/CMakeFiles/ftp.dir/requires: examples/ftp/CMakeFiles/ftp.dir/Ftp.cpp.obj.requires

.PHONY : examples/ftp/CMakeFiles/ftp.dir/requires

examples/ftp/CMakeFiles/ftp.dir/clean:
	cd /d C:\SFML\examples\ftp && $(CMAKE_COMMAND) -P CMakeFiles\ftp.dir\cmake_clean.cmake
.PHONY : examples/ftp/CMakeFiles/ftp.dir/clean

examples/ftp/CMakeFiles/ftp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\SFML C:\SFML\examples\ftp C:\SFML C:\SFML\examples\ftp C:\SFML\examples\ftp\CMakeFiles\ftp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/ftp/CMakeFiles/ftp.dir/depend

