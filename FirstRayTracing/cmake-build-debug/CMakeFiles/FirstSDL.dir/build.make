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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/FirstSDL.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/FirstSDL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstSDL.dir/flags.make

CMakeFiles/FirstSDL.dir/main.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstSDL.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/main.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp"

CMakeFiles/FirstSDL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp" > CMakeFiles/FirstSDL.dir/main.cpp.i

CMakeFiles/FirstSDL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp" -o CMakeFiles/FirstSDL.dir/main.cpp.s

CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o: ../utilitySDL/utilitySDL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp"

CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp" > CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.i

CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp" -o CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.s

CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o: ../gradient/gradient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp"

CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp" > CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.i

CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp" -o CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.s

CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o: ../flyngBox/flyngBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp"

CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp" > CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.i

CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp" -o CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.s

CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o: ../rayTracing/rayTracing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp"

CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp" > CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.i

CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp" -o CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.s

CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o: ../model/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp"

CMakeFiles/FirstSDL.dir/model/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/model/Sphere.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp" > CMakeFiles/FirstSDL.dir/model/Sphere.cpp.i

CMakeFiles/FirstSDL.dir/model/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/model/Sphere.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp" -o CMakeFiles/FirstSDL.dir/model/Sphere.cpp.s

CMakeFiles/FirstSDL.dir/model/object_list.cpp.o: CMakeFiles/FirstSDL.dir/flags.make
CMakeFiles/FirstSDL.dir/model/object_list.cpp.o: ../model/object_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FirstSDL.dir/model/object_list.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstSDL.dir/model/object_list.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp"

CMakeFiles/FirstSDL.dir/model/object_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSDL.dir/model/object_list.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp" > CMakeFiles/FirstSDL.dir/model/object_list.cpp.i

CMakeFiles/FirstSDL.dir/model/object_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSDL.dir/model/object_list.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp" -o CMakeFiles/FirstSDL.dir/model/object_list.cpp.s

# Object files for target FirstSDL
FirstSDL_OBJECTS = \
"CMakeFiles/FirstSDL.dir/main.cpp.o" \
"CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o" \
"CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o" \
"CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o" \
"CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o" \
"CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o" \
"CMakeFiles/FirstSDL.dir/model/object_list.cpp.o"

# External object files for target FirstSDL
FirstSDL_EXTERNAL_OBJECTS =

FirstSDL: CMakeFiles/FirstSDL.dir/main.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/utilitySDL/utilitySDL.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/gradient/gradient.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/flyngBox/flyngBox.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/rayTracing/rayTracing.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/model/Sphere.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/model/object_list.cpp.o
FirstSDL: CMakeFiles/FirstSDL.dir/build.make
FirstSDL: CMakeFiles/FirstSDL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable FirstSDL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FirstSDL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstSDL.dir/build: FirstSDL
.PHONY : CMakeFiles/FirstSDL.dir/build

CMakeFiles/FirstSDL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FirstSDL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FirstSDL.dir/clean

CMakeFiles/FirstSDL.dir/depend:
	cd "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-debug/CMakeFiles/FirstSDL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FirstSDL.dir/depend

