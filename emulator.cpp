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

/* A DCPU-16 Emulator */

#include <iostream>
#include <fstream>
#include <cstring>

#include "instruction.h"
#include "dcpu.h"

using namespace std;

/**
 *  Load a file that contains DCPU-16 binary instruction into the
 *   memory of the DCPU16 virtual machine.
 */
bool load_binary(WORD * memory, string path) {

    std::ifstream file;
    file.open(path, ios::in); // open the 'binary' as text file.

    if(! file.is_open()) {
        std::cerr << "Cannot open the binary '" << path << "'" << std::endl;
        return false;
    }

    std::cout << "Load the binary '" << path << "'..." << std::endl;

    string line;
    while(getline(file, line)) {
        std::cout << line << std::endl;
        memcpy(memory, line.c_str(), line.size());
        memory += line.size();
    }

    file.close();
    return true;
}

int main(int argc, char * argv[]) 
{
    Instruction istr;
    std::auto_ptr<DCPU> dcpu(new DCPU());

    std::cout << "Start the DCPU16 virtual machine..." << std::endl;

    WORD * buf = dcpu->allocate(1000);

    load_binary(buf, argv[1]);

    dcpu->dump(std::cout);

    dcpu->run();
}


















