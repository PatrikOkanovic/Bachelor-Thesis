# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/GAonemax.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GAonemax.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GAonemax.dir/flags.make

CMakeFiles/GAonemax.dir/main.cpp.o: CMakeFiles/GAonemax.dir/flags.make
CMakeFiles/GAonemax.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GAonemax.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAonemax.dir/main.cpp.o -c /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/main.cpp

CMakeFiles/GAonemax.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAonemax.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/main.cpp > CMakeFiles/GAonemax.dir/main.cpp.i

CMakeFiles/GAonemax.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAonemax.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/main.cpp -o CMakeFiles/GAonemax.dir/main.cpp.s

CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o: CMakeFiles/GAonemax.dir/flags.make
CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o: ../OneMaxEvalOp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o -c /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/OneMaxEvalOp.cpp

CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/OneMaxEvalOp.cpp > CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.i

CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/OneMaxEvalOp.cpp -o CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.s

# Object files for target GAonemax
GAonemax_OBJECTS = \
"CMakeFiles/GAonemax.dir/main.cpp.o" \
"CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o"

# External object files for target GAonemax
GAonemax_EXTERNAL_OBJECTS =

GAonemax: CMakeFiles/GAonemax.dir/main.cpp.o
GAonemax: CMakeFiles/GAonemax.dir/OneMaxEvalOp.cpp.o
GAonemax: CMakeFiles/GAonemax.dir/build.make
GAonemax: ../../../release/libECF.a
GAonemax: CMakeFiles/GAonemax.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GAonemax"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GAonemax.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GAonemax.dir/build: GAonemax

.PHONY : CMakeFiles/GAonemax.dir/build

CMakeFiles/GAonemax.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GAonemax.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GAonemax.dir/clean

CMakeFiles/GAonemax.dir/depend:
	cd /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release /home/patrik/FER/3.godina/2.semestar/Zavrsni/ECF_1.4.2/examples/GAonemax/cmake-build-release/CMakeFiles/GAonemax.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GAonemax.dir/depend

