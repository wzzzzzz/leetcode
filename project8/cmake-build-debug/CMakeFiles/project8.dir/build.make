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
include CMakeFiles\project8.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\project8.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\project8.dir\flags.make

CMakeFiles\project8.dir\main.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project8.dir/main.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\main.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\main.cpp
<<

CMakeFiles\project8.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/main.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\main.cpp
<<

CMakeFiles\project8.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/main.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\main.cpp.s /c E:\class\leetcode\project8\main.cpp
<<

CMakeFiles\project8.dir\test2.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\test2.cpp.obj: ..\test2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project8.dir/test2.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\test2.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\test2.cpp
<<

CMakeFiles\project8.dir\test2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/test2.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\test2.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\test2.cpp
<<

CMakeFiles\project8.dir\test2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/test2.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\test2.cpp.s /c E:\class\leetcode\project8\test2.cpp
<<

CMakeFiles\project8.dir\reconstructMatrix.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\reconstructMatrix.cpp.obj: ..\reconstructMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project8.dir/reconstructMatrix.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\reconstructMatrix.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\reconstructMatrix.cpp
<<

CMakeFiles\project8.dir\reconstructMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/reconstructMatrix.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\reconstructMatrix.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\reconstructMatrix.cpp
<<

CMakeFiles\project8.dir\reconstructMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/reconstructMatrix.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\reconstructMatrix.cpp.s /c E:\class\leetcode\project8\reconstructMatrix.cpp
<<

CMakeFiles\project8.dir\subtractProductAndSum.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\subtractProductAndSum.cpp.obj: ..\subtractProductAndSum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project8.dir/subtractProductAndSum.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\subtractProductAndSum.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\subtractProductAndSum.cpp
<<

CMakeFiles\project8.dir\subtractProductAndSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/subtractProductAndSum.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\subtractProductAndSum.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\subtractProductAndSum.cpp
<<

CMakeFiles\project8.dir\subtractProductAndSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/subtractProductAndSum.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\subtractProductAndSum.cpp.s /c E:\class\leetcode\project8\subtractProductAndSum.cpp
<<

CMakeFiles\project8.dir\groupThePeople.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\groupThePeople.cpp.obj: ..\groupThePeople.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project8.dir/groupThePeople.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\groupThePeople.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\groupThePeople.cpp
<<

CMakeFiles\project8.dir\groupThePeople.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/groupThePeople.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\groupThePeople.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\groupThePeople.cpp
<<

CMakeFiles\project8.dir\groupThePeople.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/groupThePeople.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\groupThePeople.cpp.s /c E:\class\leetcode\project8\groupThePeople.cpp
<<

CMakeFiles\project8.dir\getDecimalValue.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\getDecimalValue.cpp.obj: ..\getDecimalValue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project8.dir/getDecimalValue.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\getDecimalValue.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\getDecimalValue.cpp
<<

CMakeFiles\project8.dir\getDecimalValue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/getDecimalValue.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\getDecimalValue.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\getDecimalValue.cpp
<<

CMakeFiles\project8.dir\getDecimalValue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/getDecimalValue.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\getDecimalValue.cpp.s /c E:\class\leetcode\project8\getDecimalValue.cpp
<<

CMakeFiles\project8.dir\sequentialDigits.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\sequentialDigits.cpp.obj: ..\sequentialDigits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project8.dir/sequentialDigits.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\sequentialDigits.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\sequentialDigits.cpp
<<

CMakeFiles\project8.dir\sequentialDigits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/sequentialDigits.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\sequentialDigits.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\sequentialDigits.cpp
<<

CMakeFiles\project8.dir\sequentialDigits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/sequentialDigits.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\sequentialDigits.cpp.s /c E:\class\leetcode\project8\sequentialDigits.cpp
<<

CMakeFiles\project8.dir\maxSideLength.cpp.obj: CMakeFiles\project8.dir\flags.make
CMakeFiles\project8.dir\maxSideLength.cpp.obj: ..\maxSideLength.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project8.dir/maxSideLength.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project8.dir\maxSideLength.cpp.obj /FdCMakeFiles\project8.dir\ /FS -c E:\class\leetcode\project8\maxSideLength.cpp
<<

CMakeFiles\project8.dir\maxSideLength.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project8.dir/maxSideLength.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\project8.dir\maxSideLength.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\maxSideLength.cpp
<<

CMakeFiles\project8.dir\maxSideLength.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project8.dir/maxSideLength.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project8.dir\maxSideLength.cpp.s /c E:\class\leetcode\project8\maxSideLength.cpp
<<

# Object files for target project8
project8_OBJECTS = \
"CMakeFiles\project8.dir\main.cpp.obj" \
"CMakeFiles\project8.dir\test2.cpp.obj" \
"CMakeFiles\project8.dir\reconstructMatrix.cpp.obj" \
"CMakeFiles\project8.dir\subtractProductAndSum.cpp.obj" \
"CMakeFiles\project8.dir\groupThePeople.cpp.obj" \
"CMakeFiles\project8.dir\getDecimalValue.cpp.obj" \
"CMakeFiles\project8.dir\sequentialDigits.cpp.obj" \
"CMakeFiles\project8.dir\maxSideLength.cpp.obj"

# External object files for target project8
project8_EXTERNAL_OBJECTS =

project8.exe: CMakeFiles\project8.dir\main.cpp.obj
project8.exe: CMakeFiles\project8.dir\test2.cpp.obj
project8.exe: CMakeFiles\project8.dir\reconstructMatrix.cpp.obj
project8.exe: CMakeFiles\project8.dir\subtractProductAndSum.cpp.obj
project8.exe: CMakeFiles\project8.dir\groupThePeople.cpp.obj
project8.exe: CMakeFiles\project8.dir\getDecimalValue.cpp.obj
project8.exe: CMakeFiles\project8.dir\sequentialDigits.cpp.obj
project8.exe: CMakeFiles\project8.dir\maxSideLength.cpp.obj
project8.exe: CMakeFiles\project8.dir\build.make
project8.exe: CMakeFiles\project8.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable project8.exe"
	"D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\project8.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\x86\mt.exe --manifests  -- D:\vs\2015\VC\bin\link.exe /nologo @CMakeFiles\project8.dir\objects1.rsp @<<
 /out:project8.exe /implib:project8.lib /pdb:E:\class\leetcode\project8\cmake-build-debug\project8.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\project8.dir\build: project8.exe

.PHONY : CMakeFiles\project8.dir\build

CMakeFiles\project8.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project8.dir\cmake_clean.cmake
.PHONY : CMakeFiles\project8.dir\clean

CMakeFiles\project8.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\class\leetcode\project8 E:\class\leetcode\project8 E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug\CMakeFiles\project8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\project8.dir\depend

