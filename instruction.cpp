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


#include "instruction.h"

Instruction::Instruction(){

}

void Instruction::setOpcode(char opcode) {
    _opcode = opcode;
    _isSpecial = (opcode == 0) ? true : false;
}

void Instruction::setOperandA(char oprA) {
    _operandA = oprA;
}

void Instruction::setOperandB(char oprB) {
    _operandB = oprB;
}

void Instruction::print(std::ostream & os) {

    /* Should convert the char to int, before pipeline to std::hex.
        Otherwise, nothing would be shown. */

    os << std::hex << int(_opcode)   << " ";
    os << std::hex << int(_operandB) << ",";
    os << std::hex << int(_operandA) << std::endl;


    std::string mnemonic;

    if(! _isSpecial ) {
        switch(_opcode) {
            case 0x01:
                mnemonic = "SET"; break;
            case 0x02:
                mnemonic = "ADD"; break;
            case 0x03:
                mnemonic = "SUB"; break;
            case 0x04:
                mnemonic = "MUL"; break;
            case 0x05:
                mnemonic = "MLI"; break;
            case 0x06:
                mnemonic = "DIV"; break;
            case 0x07:
                mnemonic = "DVI"; break;
            case 0x08:
                mnemonic = "MOD"; break;
            case 0x09:
                mnemonic = "MDI"; break;
            case 0x0a:
                mnemonic = "AND"; break;
            case 0x0b:
                mnemonic = "BOR"; break;
            case 0x0c:
                mnemonic = "XOR"; break;
            case 0x0d:
                mnemonic = "SHR"; break;
            case 0x0e:
                mnemonic = "ASR"; break;
            case 0x0f:
                mnemonic = "SHL"; break;
            case 0x10:
                mnemonic = "IFB"; break;
            case 0x11:
                mnemonic = "IFC"; break;
            case 0x12:
                mnemonic = "IFE"; break;
            case 0x13:
                mnemonic = "IFN"; break;
            case 0x14:
                mnemonic = "IFG"; break;
            case 0x15:
                mnemonic = "IFA"; break;
            case 0x16:
                mnemonic = "IFL"; break;
            case 0x17:
                mnemonic = "IFU"; break;
            // NOT DEFINED. 0x18, 0x19
            case 0x1a:
                mnemonic = "ADX"; break;
            case 0x1b:
                mnemonic = "SBX"; break;
            // NOT DEFINED. 0x1c, 0x1d
            case 0x1e:
                mnemonic = "STI"; break;
            case 0x1f:
                mnemonic = "STD"; break;

            default:   // # NOT DEFINED
                mnemonic = "UNK"; break;
        }
    } else {
        // AAAAAA_OOOOO_00000
        switch(_operandB){
            case 0x01:
                mnemonic = "JSR"; break;
            // NOT DEFINED. 0x02 ~ 0x07
            case 0x08:
                mnemonic = "INT"; break;
            case 0x09:
                mnemonic = "IAG"; break;
            case 0x0a:
                mnemonic = "IAS"; break;
            case 0x0b:
                mnemonic = "RFI"; break;
            case 0x0c:
                mnemonic = "IAQ"; break;
            // NOT DEFINED: 0x0d ~ 0x0f
            case 0x10:
                mnemonic = "HWN"; break;
            case 0x11:
                mnemonic = "HWQ"; break;
            case 0x12:
                mnemonic = "HWI"; break;

            default:   // # NOT DEFINED
                mnemonic = "UNK"; break;
        }
    }

    os << mnemonic << std::endl;

}
















