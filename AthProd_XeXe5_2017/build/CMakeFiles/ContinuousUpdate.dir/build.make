# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/build

# Utility rule file for ContinuousUpdate.

# Include the progress variables for this target.
include CMakeFiles/ContinuousUpdate.dir/progress.make

CMakeFiles/ContinuousUpdate:
	/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/ctest -D ContinuousUpdate

ContinuousUpdate: CMakeFiles/ContinuousUpdate
ContinuousUpdate: CMakeFiles/ContinuousUpdate.dir/build.make

.PHONY : ContinuousUpdate

# Rule to build all files generated by this target.
CMakeFiles/ContinuousUpdate.dir/build: ContinuousUpdate

.PHONY : CMakeFiles/ContinuousUpdate.dir/build

CMakeFiles/ContinuousUpdate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousUpdate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousUpdate.dir/clean

CMakeFiles/ContinuousUpdate.dir/depend:
	cd /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/source /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/source /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/build /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/build /afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/build/CMakeFiles/ContinuousUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousUpdate.dir/depend

