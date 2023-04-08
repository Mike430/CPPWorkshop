clang -g -Wall -std=c++14 main.cpp -o executable.exe
rem clang -g -D ENABLE_MIKES_DIRTY_SECRET -Wall -std=c++14 main.cpp -o executable.exe


rem text in at start
rem compile - text to IR (intermediate representation) -> .o .a .out .obj files
rem linker - takes the IR files and stitches the program together from all libraries
rem assembler - turns the asm into machine code (0x324809 - HEX CODE) -> outputs a final .exe or .dll or .lib file

rem ^ this is on a per compliation unit bases - which is why unity builds are so quick