/*
 * Copyright (c) 2015, Lisong Guo
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright 
 *   notice, this list of conditions and the following disclaimer in the 
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* DCPU-16 Spec is Copyright 2012 Mojang

   The instruction is implemented, according to the reference:
    https://raw.githubusercontent.com/gatesphere/
        demi-16/master/docs/dcpu-specs/dcpu-1-7.txt
*/

/** This class represents the CPU unit in DCPU-16 architecture.
    - It contains 8 registers (A, B, C, X, Y, Z, I, J).
    - 0x10000 words of RAM, each word is 16-bits long.
    - program counter (PC).
    - stack pointer (SP).
    - extra/excess (EX) flag, used as a carry bit for addition/subtraction.
    - interrupt address (IA).
    - all the above registers are a word long (16-bits).
*/

#ifndef __DCPU16_DCPU_h_
#define __DCPU16_DCPU_h_

#define MEM_SIZE 10000      // size of memory

/* A "short" integer (2 bytes) should be able to hold a word. */
typedef short WORD;

#include <cstddef>
#include <iostream>

#include "instruction.h"

class DCPU {

public:
    DCPU();

    /**
     * \brief Allocate a block of memory.
     * \return NULL if the request cannot be met.
     */
    WORD * allocate(WORD size);

    /**
     * Run the instructions that are loaded in the memory.
     */
    void run();

    /**
     * \brief Dump the status of the CPU, including the register values
     *   as well as the memory image.
     */
    void dump(std::ostream & os);

protected:

    /**
     *  Retrieve an instruction starting from the program counter.
     */
    Instruction nextInstruction();

    /**
     *  Retrieve the next WORD from the 'binary' in the memory.
     */
    WORD nextWord();

private:
    WORD _memory[MEM_SIZE];

    // An index pointing to the beginning of the available memory.
    WORD _mi;

    // A pointer pointing to the next WORD of instruction.
    WORD * _mp;

    /*
    // common registers
    short _RA;
    short _RB;
    short _RC;
    short _RX;
    short _RY;
    short _RZ;
    short _RI;
    short _RJ;


    // program counter
    short _PC;
    */

};



#endif // __DCPU16_DCPU_h_


