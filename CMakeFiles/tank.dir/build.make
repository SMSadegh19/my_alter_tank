# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/57/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/57/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sadegh/tank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sadegh/tank

# Include any dependencies generated for this target.
include CMakeFiles/tank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tank.dir/flags.make

CMakeFiles/tank.dir/src/logic.c.o: CMakeFiles/tank.dir/flags.make
CMakeFiles/tank.dir/src/logic.c.o: src/logic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sadegh/tank/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tank.dir/src/logic.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tank.dir/src/logic.c.o   -c /home/sadegh/tank/src/logic.c

CMakeFiles/tank.dir/src/logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tank.dir/src/logic.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sadegh/tank/src/logic.c > CMakeFiles/tank.dir/src/logic.c.i

CMakeFiles/tank.dir/src/logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tank.dir/src/logic.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sadegh/tank/src/logic.c -o CMakeFiles/tank.dir/src/logic.c.s

CMakeFiles/tank.dir/src/physics.c.o: CMakeFiles/tank.dir/flags.make
CMakeFiles/tank.dir/src/physics.c.o: src/physics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sadegh/tank/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tank.dir/src/physics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tank.dir/src/physics.c.o   -c /home/sadegh/tank/src/physics.c

CMakeFiles/tank.dir/src/physics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tank.dir/src/physics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sadegh/tank/src/physics.c > CMakeFiles/tank.dir/src/physics.c.i

CMakeFiles/tank.dir/src/physics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tank.dir/src/physics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sadegh/tank/src/physics.c -o CMakeFiles/tank.dir/src/physics.c.s

CMakeFiles/tank.dir/src/tank.c.o: CMakeFiles/tank.dir/flags.make
CMakeFiles/tank.dir/src/tank.c.o: src/tank.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sadegh/tank/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tank.dir/src/tank.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tank.dir/src/tank.c.o   -c /home/sadegh/tank/src/tank.c

CMakeFiles/tank.dir/src/tank.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tank.dir/src/tank.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sadegh/tank/src/tank.c > CMakeFiles/tank.dir/src/tank.c.i

CMakeFiles/tank.dir/src/tank.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tank.dir/src/tank.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sadegh/tank/src/tank.c -o CMakeFiles/tank.dir/src/tank.c.s

CMakeFiles/tank.dir/src/view.c.o: CMakeFiles/tank.dir/flags.make
CMakeFiles/tank.dir/src/view.c.o: src/view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sadegh/tank/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/tank.dir/src/view.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tank.dir/src/view.c.o   -c /home/sadegh/tank/src/view.c

CMakeFiles/tank.dir/src/view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tank.dir/src/view.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sadegh/tank/src/view.c > CMakeFiles/tank.dir/src/view.c.i

CMakeFiles/tank.dir/src/view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tank.dir/src/view.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sadegh/tank/src/view.c -o CMakeFiles/tank.dir/src/view.c.s

# Object files for target tank
tank_OBJECTS = \
"CMakeFiles/tank.dir/src/logic.c.o" \
"CMakeFiles/tank.dir/src/physics.c.o" \
"CMakeFiles/tank.dir/src/tank.c.o" \
"CMakeFiles/tank.dir/src/view.c.o"

# External object files for target tank
tank_EXTERNAL_OBJECTS =

tank: CMakeFiles/tank.dir/src/logic.c.o
tank: CMakeFiles/tank.dir/src/physics.c.o
tank: CMakeFiles/tank.dir/src/tank.c.o
tank: CMakeFiles/tank.dir/src/view.c.o
tank: CMakeFiles/tank.dir/build.make
tank: CMakeFiles/tank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sadegh/tank/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable tank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tank.dir/build: tank

.PHONY : CMakeFiles/tank.dir/build

CMakeFiles/tank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tank.dir/clean

CMakeFiles/tank.dir/depend:
	cd /home/sadegh/tank && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sadegh/tank /home/sadegh/tank /home/sadegh/tank /home/sadegh/tank /home/sadegh/tank/CMakeFiles/tank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tank.dir/depend

