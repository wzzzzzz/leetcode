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
include CMakeFiles\findNumbers.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\findNumbers.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\findNumbers.dir\flags.make

CMakeFiles\findNumbers.dir\findNumbers.cpp.obj: CMakeFiles\findNumbers.dir\flags.make
CMakeFiles\findNumbers.dir\findNumbers.cpp.obj: ..\findNumbers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/findNumbers.dir/findNumbers.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\findNumbers.dir\findNumbers.cpp.obj /FdCMakeFiles\findNumbers.dir\ /FS -c E:\class\leetcode\project8\findNumbers.cpp
<<

CMakeFiles\findNumbers.dir\findNumbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/findNumbers.dir/findNumbers.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\findNumbers.dir\findNumbers.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\findNumbers.cpp
<<

CMakeFiles\findNumbers.dir\findNumbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/findNumbers.dir/findNumbers.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\findNumbers.dir\findNumbers.cpp.s /c E:\class\leetcode\project8\findNumbers.cpp
<<

# Object files for target findNumbers
findNumbers_OBJECTS = \
"CMakeFiles\findNumbers.dir\findNumbers.cpp.obj"

# External object files for target findNumbers
findNumbers_EXTERNAL_OBJECTS =

findNumbers.exe: CMakeFiles\findNumbers.dir\findNumbers.cpp.obj
findNumbers.exe: CMakeFiles\findNumbers.dir\build.make
findNumbers.exe: CMakeFiles\findNumbers.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable findNumbers.exe"
	"D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\findNumbers.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\x86\mt.exe --manifests  -- D:\vs\2015\VC\bin\link.exe /nologo @CMakeFiles\findNumbers.dir\objects1.rsp @<<
 /out:findNumbers.exe /implib:findNumbers.lib /pdb:E:\class\leetcode\project8\cmake-build-debug\findNumbers.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\findNumbers.dir\build: findNumbers.exe

.PHONY : CMakeFiles\findNumbers.dir\build

CMakeFiles\findNumbers.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\findNumbers.dir\cmake_clean.cmake
.PHONY : CMakeFiles\findNumbers.dir\clean

CMakeFiles\findNumbers.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\class\leetcode\project8 E:\class\leetcode\project8 E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug\CMakeFiles\findNumbers.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\findNumbers.dir\depend

