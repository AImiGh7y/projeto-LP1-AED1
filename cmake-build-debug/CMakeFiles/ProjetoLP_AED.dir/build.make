# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Nuno\CLionProjects\ProjetoLP_AED

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetoLP_AED.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ProjetoLP_AED.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetoLP_AED.dir/flags.make

CMakeFiles/ProjetoLP_AED.dir/main.c.obj: CMakeFiles/ProjetoLP_AED.dir/flags.make
CMakeFiles/ProjetoLP_AED.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetoLP_AED.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjetoLP_AED.dir\main.c.obj -c C:\Users\Nuno\CLionProjects\ProjetoLP_AED\main.c

CMakeFiles/ProjetoLP_AED.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoLP_AED.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Nuno\CLionProjects\ProjetoLP_AED\main.c > CMakeFiles\ProjetoLP_AED.dir\main.c.i

CMakeFiles/ProjetoLP_AED.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoLP_AED.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Nuno\CLionProjects\ProjetoLP_AED\main.c -o CMakeFiles\ProjetoLP_AED.dir\main.c.s

CMakeFiles/ProjetoLP_AED.dir/clientes.c.obj: CMakeFiles/ProjetoLP_AED.dir/flags.make
CMakeFiles/ProjetoLP_AED.dir/clientes.c.obj: ../clientes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjetoLP_AED.dir/clientes.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjetoLP_AED.dir\clientes.c.obj -c C:\Users\Nuno\CLionProjects\ProjetoLP_AED\clientes.c

CMakeFiles/ProjetoLP_AED.dir/clientes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoLP_AED.dir/clientes.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Nuno\CLionProjects\ProjetoLP_AED\clientes.c > CMakeFiles\ProjetoLP_AED.dir\clientes.c.i

CMakeFiles/ProjetoLP_AED.dir/clientes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoLP_AED.dir/clientes.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Nuno\CLionProjects\ProjetoLP_AED\clientes.c -o CMakeFiles\ProjetoLP_AED.dir\clientes.c.s

# Object files for target ProjetoLP_AED
ProjetoLP_AED_OBJECTS = \
"CMakeFiles/ProjetoLP_AED.dir/main.c.obj" \
"CMakeFiles/ProjetoLP_AED.dir/clientes.c.obj"

# External object files for target ProjetoLP_AED
ProjetoLP_AED_EXTERNAL_OBJECTS =

ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/main.c.obj
ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/clientes.c.obj
ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/build.make
ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/linklibs.rsp
ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/objects1.rsp
ProjetoLP_AED.exe: CMakeFiles/ProjetoLP_AED.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ProjetoLP_AED.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjetoLP_AED.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetoLP_AED.dir/build: ProjetoLP_AED.exe
.PHONY : CMakeFiles/ProjetoLP_AED.dir/build

CMakeFiles/ProjetoLP_AED.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjetoLP_AED.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjetoLP_AED.dir/clean

CMakeFiles/ProjetoLP_AED.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Nuno\CLionProjects\ProjetoLP_AED C:\Users\Nuno\CLionProjects\ProjetoLP_AED C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug C:\Users\Nuno\CLionProjects\ProjetoLP_AED\cmake-build-debug\CMakeFiles\ProjetoLP_AED.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetoLP_AED.dir/depend

