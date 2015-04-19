# ============================================================================ #
# @Author:  Lisong Guo <lisong.guo@me.com>
# @Date:    April 18, 2015
# Makefile to compile an emulator, an assembler and a disassembler for DCPU-16
# ============================================================================ #

CC=g++
CFLAGS=-Wall -g

SOURCES=$(shell ls *.cpp)
TARGETS=dcpu16


# Replace the postfix of sources
OBJECTS=$(SOURCES:.c=.o)


# Entrance rule
all: $(TARGETS)


# Wild card matching 
#%.c: 
#	gcc -o $* $*.c 


dcpu16: emulator.cpp
	$(CC) $(CFLAGS) $^ -o $@


# Clean the object files and targets
clean:
	rm -rf *.o $(TARGETS) *.dSYM


# Print the source code to screen
view: $(SOURCES)
	less $^




