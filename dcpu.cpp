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


#include "dcpu.h"
#include <sstream>


DCPU::DCPU() : _mi(0), _mp(_memory) {

}


WORD * DCPU::allocate(WORD size) {
    WORD * res = _memory + _mi;
    _mi += size;

    return res;
}


void DCPU::run() {
    // TODO    
    nextInstruction();
}

/**
 *  Read the code in hex into WORD.
 */
WORD DCPU::nextWord() {
    WORD res;

    std::stringstream ss;
    std::string hex_word(reinterpret_cast<char*>(_mp), 4);
    ss << std::hex << hex_word;
    ss >> res;

    // move the pointer to the next word.
    _mp += 1;

    return res;
}

Instruction DCPU::nextInstruction() {
    Instruction nextIstr;
    
    WORD word = nextWord();

    /*  print the instruction in bits.
    std::bitset<16> bits(word);
    std::cout << bits << std::endl;

    std::cout << "word:" << std::hex << word << std::endl;
    std::cout << "mask:" << std::bitset<16>(MASK_5_ONES) << std::endl;
    */

    WORD MASK_5_ONES = 0x1F;
    char opcode = (word & MASK_5_ONES);
    nextIstr.setOpcode(opcode);

    char operandB = ((word >> 5) & MASK_5_ONES);
    nextIstr.setOperandB(operandB);

    WORD MASK_6_ONES = 0x003F;
    char operandA = ((word >> 10) & MASK_6_ONES);
    nextIstr.setOperandA(operandA);

    nextIstr.print(std::cout);

    return nextIstr;
}


void DCPU::dump(std::ostream & os) {
    os << "Memory Image:" << std::endl;
    int LINE_LEN = 80;

    WORD * cur = _memory;
    while( cur < (_memory + _mi) ) {
        os.write(reinterpret_cast<char*>(cur), LINE_LEN * 2);
        os << std::endl;
        cur += LINE_LEN;
    }
}









