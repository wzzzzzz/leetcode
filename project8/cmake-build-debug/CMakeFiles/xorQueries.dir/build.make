# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\class\leetcode\project8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\class\leetcode\project8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\xorQueries.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\xorQueries.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\xorQueries.dir\flags.make

CMakeFiles\xorQueries.dir\xorQueries.cpp.obj: CMakeFiles\xorQueries.dir\flags.make
CMakeFiles\xorQueries.dir\xorQueries.cpp.obj: ..\xorQueries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xorQueries.dir/xorQueries.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\xorQueries.dir\xorQueries.cpp.obj /FdCMakeFiles\xorQueries.dir\ /FS -c E:\class\leetcode\project8\xorQueries.cpp
<<

CMakeFiles\xorQueries.dir\xorQueries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xorQueries.dir/xorQueries.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\xorQueries.dir\xorQueries.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\xorQueries.cpp
<<

CMakeFiles\xorQueries.dir\xorQueries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xorQueries.dir/xorQueries.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\xorQueries.dir\xorQueries.cpp.s /c E:\class\leetcode\project8\xorQueries.cpp
<<

# Object files for target xorQueries
xorQueries_OBJECTS = \
"CMakeFiles\xorQueries.dir\xorQueries.cpp.obj"

# External object files for target xorQueries
xorQueries_EXTERNAL_OBJECTS =

xorQueries.exe: CMakeFiles\xorQueries.dir\xorQueries.cpp.obj
xorQueries.exe: CMakeFiles\xorQueries.dir\build.make
xorQueries.exe: CMakeFiles\xorQueries.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xorQueries.exe"
	"D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\xorQueries.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\x86\mt.exe --manifests  -- D:\vs\2015\VC\bin\link.exe /nologo @CMakeFiles\xorQueries.dir\objects1.rsp @<<
 /out:xorQueries.exe /implib:xorQueries.lib /pdb:E:\class\leetcode\project8\cmake-build-debug\xorQueries.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\xorQueries.dir\build: xorQueries.exe

.PHONY : CMakeFiles\xorQueries.dir\build

CMakeFiles\xorQueries.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\xorQueries.dir\cmake_clean.cmake
.PHONY : CMakeFiles\xorQueries.dir\clean

CMakeFiles\xorQueries.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\class\leetcode\project8 E:\class\leetcode\project8 E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug\CMakeFiles\xorQueries.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\xorQueries.dir\depend
