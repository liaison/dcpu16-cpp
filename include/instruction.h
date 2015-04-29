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

/* DCPU-16 Spec is Copyright 2012 Mojang */

/** This class represents an instruction in DCPU-16 architecture.
  - An instruction in DCPU-16 is 1-3 words long and is fully defined
    by its first word.
    
  - For a BASIC instruction, the lower 5 bits of the first word in the
    instruction is the opcode O, and the remaining 11 bits are splitted
    into a 5-bits value B and a 6-bits value A.
  
  - B is always handled by the processor after A, which is at the lower bits.
 
  - The format of a basic instruction looks like:  AAAAAABBBBBOOOOO.

  - Special instructions have low five bits unset, are constructed as
    AAAAAAOOOOO00000: where AAAAAA is a 6-bits operand and OOOOO is the
    5-bits opcode.
*/

#ifndef __DCPU16_INSTRUCTION_h_
#define __DCPU16_INSTRUCTION_h_

#include <iostream>

class Instruction {

public:
    Instruction();

    void setOpcode(char opcode, bool isSpecial);
    
    void setOperandA(char oprA);

    void setOperandB(char oprB);

    /* Print out the instruction in its mnemonic form. */
    void print(std::ostream & os);

private:
    bool _isSpecial;

    char _opcode;
    char _operandA;
    char _operandB;

};


#endif // __DCPU16_INSTRUCTION_h_




