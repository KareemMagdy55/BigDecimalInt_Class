# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BigDecimalInt_Class.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BigDecimalInt_Class.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BigDecimalInt_Class.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigDecimalInt_Class.dir/flags.make

CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj: CMakeFiles/BigDecimalInt_Class.dir/flags.make
CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj: ../main.cpp
CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj: CMakeFiles/BigDecimalInt_Class.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj -MF CMakeFiles\BigDecimalInt_Class.dir\main.cpp.obj.d -o CMakeFiles\BigDecimalInt_Class.dir\main.cpp.obj -c "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\main.cpp"

CMakeFiles/BigDecimalInt_Class.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigDecimalInt_Class.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\main.cpp" > CMakeFiles\BigDecimalInt_Class.dir\main.cpp.i

CMakeFiles/BigDecimalInt_Class.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigDecimalInt_Class.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\main.cpp" -o CMakeFiles\BigDecimalInt_Class.dir\main.cpp.s

# Object files for target BigDecimalInt_Class
BigDecimalInt_Class_OBJECTS = \
"CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj"

# External object files for target BigDecimalInt_Class
BigDecimalInt_Class_EXTERNAL_OBJECTS =

BigDecimalInt_Class.exe: CMakeFiles/BigDecimalInt_Class.dir/main.cpp.obj
BigDecimalInt_Class.exe: CMakeFiles/BigDecimalInt_Class.dir/build.make
BigDecimalInt_Class.exe: CMakeFiles/BigDecimalInt_Class.dir/linklibs.rsp
BigDecimalInt_Class.exe: CMakeFiles/BigDecimalInt_Class.dir/objects1.rsp
BigDecimalInt_Class.exe: CMakeFiles/BigDecimalInt_Class.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BigDecimalInt_Class.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BigDecimalInt_Class.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigDecimalInt_Class.dir/build: BigDecimalInt_Class.exe
.PHONY : CMakeFiles/BigDecimalInt_Class.dir/build

CMakeFiles/BigDecimalInt_Class.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BigDecimalInt_Class.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BigDecimalInt_Class.dir/clean

CMakeFiles/BigDecimalInt_Class.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class" "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class" "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug" "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug" "C:\Users\Mohamed reyad\Documents\BigDecimalInt_Class\cmake-build-debug\CMakeFiles\BigDecimalInt_Class.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BigDecimalInt_Class.dir/depend
