# @file Makefile
# @author Isaac McKnew and Jose Jaime
# @date 2026-02-28
# @brief Makefile for Image Stacker project
# Makefile for compiling an Image Stacker project

# Compiler
CC = g++

# Target Executable Name
TARGET = test

# Compile with all error and warnings
CFLAGS = -c -Wall -Wextra

# Default Target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): main.o stacker.o
	$(CC) -o $(TARGET) main.o stacker.o

# Compile main.cpp into main.o
main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) main.cpp

# Compile stacker.cpp into stacker.h
stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGS) stacker.cpp

# Clean up compiled files
clean:
	$(RM) $(TARGET) *.o *~
