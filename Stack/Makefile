# Define the compiler
CC = g++

# Define flags for compilation (feel free to add optimization flags like -O2)
CFLAGS = -Wall 

# Define the location of your library header file
LIBDIR = ../Libs/Node

# Define the source and object files
SRCS = stack.cpp
OBJS = $(SRCS:.cpp=.o)

# Define the library object file (assuming node.cpp compiles to node.o)
LIBOBJ = $(LIBDIR)/node.o 

# Define the target (executable name)
TARGET = stack

# Rule to compile source files into object files
%.o: %.cpp $(LIBDIR)/node.h
	$(CC) $(CFLAGS) -c -I$(LIBDIR) $< -o $@

# Rule to link object files and library object file into the executable
$(TARGET): $(OBJS) $(LIBOBJ)
	$(CC) $(CFLAGS) $(OBJS) $(LIBOBJ) -o $(TARGET)

# Rule to run the executable
run:
	./$(TARGET)

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
