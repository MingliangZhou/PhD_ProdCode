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
CMAKE_SOURCE_DIR = /afs/cern.ch/work/m/mizhou/XeXeCentRel21/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build

# Utility rule file for WorkDirConfdbMerge.

# Include the progress variables for this target.
include CMakeFiles/WorkDirConfdbMerge.dir/progress.make

CMakeFiles/WorkDirConfdbMerge: x86_64-slc6-gcc62-opt/lib/libXeXeCent.confdb
	/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake -E make_directory /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build/x86_64-slc6-gcc62-opt/lib
	/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.5/InstallArea/x86_64-slc6-gcc62-opt/cmake/modules/scripts/mergeFiles.sh /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build/x86_64-slc6-gcc62-opt/lib/WorkDir.confdb /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build/CMakeFiles/WorkDirConfdbMergeFiles.txt

WorkDirConfdbMerge: CMakeFiles/WorkDirConfdbMerge
WorkDirConfdbMerge: CMakeFiles/WorkDirConfdbMerge.dir/build.make

.PHONY : WorkDirConfdbMerge

# Rule to build all files generated by this target.
CMakeFiles/WorkDirConfdbMerge.dir/build: WorkDirConfdbMerge

.PHONY : CMakeFiles/WorkDirConfdbMerge.dir/build

CMakeFiles/WorkDirConfdbMerge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WorkDirConfdbMerge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WorkDirConfdbMerge.dir/clean

CMakeFiles/WorkDirConfdbMerge.dir/depend:
	cd /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/cern.ch/work/m/mizhou/XeXeCentRel21/source /afs/cern.ch/work/m/mizhou/XeXeCentRel21/source /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build /afs/cern.ch/work/m/mizhou/XeXeCentRel21/build/CMakeFiles/WorkDirConfdbMerge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WorkDirConfdbMerge.dir/depend

