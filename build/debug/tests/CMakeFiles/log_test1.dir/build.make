# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ccc/cmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccc/cmuduo/build/debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/log_test1.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/log_test1.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/log_test1.dir/flags.make

tests/CMakeFiles/log_test1.dir/Log_test1.cc.o: tests/CMakeFiles/log_test1.dir/flags.make
tests/CMakeFiles/log_test1.dir/Log_test1.cc.o: ../../tests/Log_test1.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ccc/cmuduo/build/debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/log_test1.dir/Log_test1.cc.o"
	cd /home/ccc/cmuduo/build/debug/tests && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/log_test1.dir/Log_test1.cc.o -c /home/ccc/cmuduo/tests/Log_test1.cc

tests/CMakeFiles/log_test1.dir/Log_test1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log_test1.dir/Log_test1.cc.i"
	cd /home/ccc/cmuduo/build/debug/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ccc/cmuduo/tests/Log_test1.cc > CMakeFiles/log_test1.dir/Log_test1.cc.i

tests/CMakeFiles/log_test1.dir/Log_test1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log_test1.dir/Log_test1.cc.s"
	cd /home/ccc/cmuduo/build/debug/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ccc/cmuduo/tests/Log_test1.cc -o CMakeFiles/log_test1.dir/Log_test1.cc.s

tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.requires:
.PHONY : tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.requires

tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.provides: tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/log_test1.dir/build.make tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.provides.build
.PHONY : tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.provides

tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.provides.build: tests/CMakeFiles/log_test1.dir/Log_test1.cc.o

# Object files for target log_test1
log_test1_OBJECTS = \
"CMakeFiles/log_test1.dir/Log_test1.cc.o"

# External object files for target log_test1
log_test1_EXTERNAL_OBJECTS =

bin/log_test1: tests/CMakeFiles/log_test1.dir/Log_test1.cc.o
bin/log_test1: lib/libmuduo_base.a
bin/log_test1: tests/CMakeFiles/log_test1.dir/build.make
bin/log_test1: tests/CMakeFiles/log_test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/log_test1"
	cd /home/ccc/cmuduo/build/debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/log_test1.dir/build: bin/log_test1
.PHONY : tests/CMakeFiles/log_test1.dir/build

tests/CMakeFiles/log_test1.dir/requires: tests/CMakeFiles/log_test1.dir/Log_test1.cc.o.requires
.PHONY : tests/CMakeFiles/log_test1.dir/requires

tests/CMakeFiles/log_test1.dir/clean:
	cd /home/ccc/cmuduo/build/debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/log_test1.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/log_test1.dir/clean

tests/CMakeFiles/log_test1.dir/depend:
	cd /home/ccc/cmuduo/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccc/cmuduo /home/ccc/cmuduo/tests /home/ccc/cmuduo/build/debug /home/ccc/cmuduo/build/debug/tests /home/ccc/cmuduo/build/debug/tests/CMakeFiles/log_test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/log_test1.dir/depend

