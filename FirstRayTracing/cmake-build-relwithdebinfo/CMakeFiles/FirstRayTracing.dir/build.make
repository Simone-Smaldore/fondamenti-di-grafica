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
CMAKE_BINARY_DIR = "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo"

# Include any dependencies generated for this target.
include CMakeFiles/FirstRayTracing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/FirstRayTracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstRayTracing.dir/flags.make

CMakeFiles/FirstRayTracing.dir/main.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstRayTracing.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/main.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp"

CMakeFiles/FirstRayTracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp" > CMakeFiles/FirstRayTracing.dir/main.cpp.i

CMakeFiles/FirstRayTracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/main.cpp" -o CMakeFiles/FirstRayTracing.dir/main.cpp.s

CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o: ../utilitySDL/utilitySDL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp"

CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp" > CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.i

CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/utilitySDL/utilitySDL.cpp" -o CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.s

CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o: ../gradient/gradient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp"

CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp" > CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.i

CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/gradient/gradient.cpp" -o CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.s

CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o: ../flyngBox/flyngBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp"

CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp" > CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.i

CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/flyngBox/flyngBox.cpp" -o CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.s

CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o: ../rayTracing/rayTracing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp"

CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp" > CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.i

CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/rayTracing/rayTracing.cpp" -o CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.s

CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o: ../model/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp"

CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp" > CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.i

CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/Sphere.cpp" -o CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.s

CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o: ../model/object_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp"

CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp" > CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.i

CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/object_list.cpp" -o CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.s

CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o: ../model/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/camera.cpp"

CMakeFiles/FirstRayTracing.dir/model/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/model/camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/camera.cpp" > CMakeFiles/FirstRayTracing.dir/model/camera.cpp.i

CMakeFiles/FirstRayTracing.dir/model/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/model/camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/camera.cpp" -o CMakeFiles/FirstRayTracing.dir/model/camera.cpp.s

CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o: CMakeFiles/FirstRayTracing.dir/flags.make
CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o: ../model/plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o -c "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/plane.cpp"

CMakeFiles/FirstRayTracing.dir/model/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstRayTracing.dir/model/plane.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/plane.cpp" > CMakeFiles/FirstRayTracing.dir/model/plane.cpp.i

CMakeFiles/FirstRayTracing.dir/model/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstRayTracing.dir/model/plane.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/model/plane.cpp" -o CMakeFiles/FirstRayTracing.dir/model/plane.cpp.s

# Object files for target FirstRayTracing
FirstRayTracing_OBJECTS = \
"CMakeFiles/FirstRayTracing.dir/main.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o" \
"CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o"

# External object files for target FirstRayTracing
FirstRayTracing_EXTERNAL_OBJECTS =

FirstRayTracing: CMakeFiles/FirstRayTracing.dir/main.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/utilitySDL/utilitySDL.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/gradient/gradient.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/flyngBox/flyngBox.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/rayTracing/rayTracing.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/model/Sphere.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/model/object_list.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/model/camera.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/model/plane.cpp.o
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/build.make
FirstRayTracing: CMakeFiles/FirstRayTracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable FirstRayTracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FirstRayTracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstRayTracing.dir/build: FirstRayTracing
.PHONY : CMakeFiles/FirstRayTracing.dir/build

CMakeFiles/FirstRayTracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FirstRayTracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FirstRayTracing.dir/clean

CMakeFiles/FirstRayTracing.dir/depend:
	cd "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo" "/Users/Simone/Desktop/Universita/Fondamenti Di Grafica/ProgettiGitHub/FirstRayTracing/cmake-build-relwithdebinfo/CMakeFiles/FirstRayTracing.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FirstRayTracing.dir/depend

