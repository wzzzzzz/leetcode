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
include CMakeFiles\reverseWords.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\reverseWords.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\reverseWords.dir\flags.make

CMakeFiles\reverseWords.dir\reverseWords.cpp.obj: CMakeFiles\reverseWords.dir\flags.make
CMakeFiles\reverseWords.dir\reverseWords.cpp.obj: ..\reverseWords.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reverseWords.dir/reverseWords.cpp.obj"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\reverseWords.dir\reverseWords.cpp.obj /FdCMakeFiles\reverseWords.dir\ /FS -c E:\class\leetcode\project8\reverseWords.cpp
<<

CMakeFiles\reverseWords.dir\reverseWords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reverseWords.dir/reverseWords.cpp.i"
	D:\vs\2015\VC\bin\cl.exe > CMakeFiles\reverseWords.dir\reverseWords.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\class\leetcode\project8\reverseWords.cpp
<<

CMakeFiles\reverseWords.dir\reverseWords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reverseWords.dir/reverseWords.cpp.s"
	D:\vs\2015\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\reverseWords.dir\reverseWords.cpp.s /c E:\class\leetcode\project8\reverseWords.cpp
<<

# Object files for target reverseWords
reverseWords_OBJECTS = \
"CMakeFiles\reverseWords.dir\reverseWords.cpp.obj"

# External object files for target reverseWords
reverseWords_EXTERNAL_OBJECTS =

reverseWords.exe: CMakeFiles\reverseWords.dir\reverseWords.cpp.obj
reverseWords.exe: CMakeFiles\reverseWords.dir\build.make
reverseWords.exe: CMakeFiles\reverseWords.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\class\leetcode\project8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reverseWords.exe"
	"D:\clion\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\reverseWords.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\x86\mt.exe --manifests  -- D:\vs\2015\VC\bin\link.exe /nologo @CMakeFiles\reverseWords.dir\objects1.rsp @<<
 /out:reverseWords.exe /implib:reverseWords.lib /pdb:E:\class\leetcode\project8\cmake-build-debug\reverseWords.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\reverseWords.dir\build: reverseWords.exe

.PHONY : CMakeFiles\reverseWords.dir\build

CMakeFiles\reverseWords.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\reverseWords.dir\cmake_clean.cmake
.PHONY : CMakeFiles\reverseWords.dir\clean

CMakeFiles\reverseWords.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\class\leetcode\project8 E:\class\leetcode\project8 E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug E:\class\leetcode\project8\cmake-build-debug\CMakeFiles\reverseWords.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\reverseWords.dir\depend

