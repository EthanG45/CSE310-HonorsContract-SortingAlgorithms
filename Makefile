# build a C++ executable (named below at EXECUTABLE) from the given files
# note it's kind of setup where you can type main followed by the file name to build for, but it's not working perfectly
# the compiler: g++ for C++
CC = g++
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -std=c++11 always use the C++11 standard 
#  -c for linking the object file
CFLAGS = -c -g -Wall -std=c++11
# linker flags go here
LDFLAGS =
# list the files being used here
SOURCES = main.cpp heap.cpp insertion.cpp merge.cpp bubble.cpp quick.cpp timer.cpp
# create objects from given source files
OBJECTS = $(SOURCES:.cpp=.o)
# insert name for executable here
EXECUTABLE = run

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# run 'make clean' to remove the executable and object file
.PHONY: clean
clean: 
	$(RM) $(EXECUTABLE)
	$(RM) $(SOURCES:.cpp=.o)
