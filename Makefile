# ============================================================================ #
# @Author:  Lisong Guo <lisong.guo@me.com>
# @Date:    April 18, 2015
# Makefile to compile an emulator, an assembler and a disassembler for DCPU-16
# ============================================================================ #

CC=g++
CFLAGS=-Wall -g -c
LDFLAGS=

SOURCES=$(shell ls *.cpp)
TARGETS=dcpu16 asmdc


# Replace the postfix of sources
OBJECTS=$(SOURCES:.cpp=.o)


# Entrance rule
all: $(TARGETS)

# Compile the Emulator
dcpu16: instruction.o dcpu.o emulator.o
	$(CC) $(LDFLAGS) $^ -o $@


# Compile the Assembler
asmdc: assembler.o
	$(CC) $(LDFLAGS) $^ -o $@


# Compile each source file
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


# Clean the object files and targets
clean:
	rm -rf *.o $(TARGETS) *.dSYM


# Print the source code to screen
view: $(SOURCES)
	less $^




