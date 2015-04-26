# ============================================================================ #
# @Author:  Lisong Guo <lisong.guo@me.com>
# @Date:    April 18, 2015
# Makefile to compile an emulator, an assembler and a disassembler for DCPU-16
# ============================================================================ #

OBJ_DIR=obj
BIN_DIR=bin
INCLUDE=include

TARGETS=dcpu16 asmdc
SOURCES=$(shell ls *.cpp)

CC=g++
CFLAGS=-Wall -g -c -I $(INCLUDE)
LDFLAGS=


# Replace the postfix of sources
OBJECTS=$(SOURCES:.cpp=.o)


# Entrance rule
all: $(TARGETS)

# Compile the Emulator
dcpu16: dcpu.o emulator.o instruction.o
	$(CC) $(LDFLAGS) $(OBJ_DIR)/$(shell echo $^ | sed -e 's/ / $(OBJ_DIR)\//g') -o $(BIN_DIR)/$@


# Compile the Assembler
asmdc: assembler.o
	$(CC) $(LDFLAGS) $(OBJ_DIR)/$^ -o $(BIN_DIR)/$@


# Compile each source file
.cpp.o:
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@


# Clean the object files and targets
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/* $(OBJ_DIR)/*.dSYM


# Print the source code to screen
view: $(SOURCES)
	less $^




