# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "D:\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\VSObj\Servers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\VSObj\Servers\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Servers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Servers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Servers.dir/flags.make

CMakeFiles/Servers.dir/main.obj: CMakeFiles/Servers.dir/flags.make
CMakeFiles/Servers.dir/main.obj: CMakeFiles/Servers.dir/includes_CXX.rsp
CMakeFiles/Servers.dir/main.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\VSObj\Servers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Servers.dir/main.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Servers.dir\main.obj -c E:\VSObj\Servers\main.cpp

CMakeFiles/Servers.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Servers.dir/main.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\VSObj\Servers\main.cpp > CMakeFiles\Servers.dir\main.i

CMakeFiles/Servers.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Servers.dir/main.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\VSObj\Servers\main.cpp -o CMakeFiles\Servers.dir\main.s

CMakeFiles/Servers.dir/SqlLinker.obj: CMakeFiles/Servers.dir/flags.make
CMakeFiles/Servers.dir/SqlLinker.obj: CMakeFiles/Servers.dir/includes_CXX.rsp
CMakeFiles/Servers.dir/SqlLinker.obj: ../SqlLinker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\VSObj\Servers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Servers.dir/SqlLinker.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Servers.dir\SqlLinker.obj -c E:\VSObj\Servers\SqlLinker.cpp

CMakeFiles/Servers.dir/SqlLinker.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Servers.dir/SqlLinker.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\VSObj\Servers\SqlLinker.cpp > CMakeFiles\Servers.dir\SqlLinker.i

CMakeFiles/Servers.dir/SqlLinker.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Servers.dir/SqlLinker.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\VSObj\Servers\SqlLinker.cpp -o CMakeFiles\Servers.dir\SqlLinker.s

CMakeFiles/Servers.dir/Socks.obj: CMakeFiles/Servers.dir/flags.make
CMakeFiles/Servers.dir/Socks.obj: CMakeFiles/Servers.dir/includes_CXX.rsp
CMakeFiles/Servers.dir/Socks.obj: ../Socks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\VSObj\Servers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Servers.dir/Socks.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Servers.dir\Socks.obj -c E:\VSObj\Servers\Socks.cpp

CMakeFiles/Servers.dir/Socks.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Servers.dir/Socks.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\VSObj\Servers\Socks.cpp > CMakeFiles\Servers.dir\Socks.i

CMakeFiles/Servers.dir/Socks.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Servers.dir/Socks.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\VSObj\Servers\Socks.cpp -o CMakeFiles\Servers.dir\Socks.s

# Object files for target Servers
Servers_OBJECTS = \
"CMakeFiles/Servers.dir/main.obj" \
"CMakeFiles/Servers.dir/SqlLinker.obj" \
"CMakeFiles/Servers.dir/Socks.obj"

# External object files for target Servers
Servers_EXTERNAL_OBJECTS =

Servers.exe: CMakeFiles/Servers.dir/main.obj
Servers.exe: CMakeFiles/Servers.dir/SqlLinker.obj
Servers.exe: CMakeFiles/Servers.dir/Socks.obj
Servers.exe: CMakeFiles/Servers.dir/build.make
Servers.exe: CMakeFiles/Servers.dir/linklibs.rsp
Servers.exe: CMakeFiles/Servers.dir/objects1.rsp
Servers.exe: CMakeFiles/Servers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\VSObj\Servers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Servers.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Servers.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Servers.dir/build: Servers.exe

.PHONY : CMakeFiles/Servers.dir/build

CMakeFiles/Servers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Servers.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Servers.dir/clean

CMakeFiles/Servers.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\VSObj\Servers E:\VSObj\Servers E:\VSObj\Servers\cmake-build-debug E:\VSObj\Servers\cmake-build-debug E:\VSObj\Servers\cmake-build-debug\CMakeFiles\Servers.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Servers.dir/depend

