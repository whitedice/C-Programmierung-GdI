/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   outputControl.c
 * Author: nicolai
 * 
 * Created on 14. September 2021, 11:08
 */

#include "outputControl.h"
#include <stdbool.h>

void outputControl(int16_t op, bool* regDst, bool* aluSrc, bool* memToReg, \
        bool* regWrite, bool* memRead, bool* memWrite, bool* branch, bool* jump,\
        bool* aluOp1, bool* aluOp0) {
    switch (op) {
    // R Format - Case 0
    // 0b ... Anderen
    // Tabelle siehe Handy
    // + jump

        // R-Befehle
        case 0b000000:
            *regDst = 1;
            *aluSrc = 0;
            *memToReg = 0;
            *regWrite = 1;
            *memRead = 0;
            *memWrite = 0;
            *branch = 0;
            *jump = 0;
            *aluOp1 = 1;
            *aluOp0 = 0;
            break;

        // lw
        case 0b110001:
            *regDst = 0;
            *aluSrc = 1;
            *memToReg = 1;
            *regWrite = 1;
            *memRead = 1;
            *memWrite = 0;
            *branch = 0;
            *jump = 0;
            *aluOp1 = 0;
            *aluOp0 = 0;
            break;


        // sw
        case 0b110101:
            //*regDst = 0;
            *aluSrc = 1;
            //*memToReg = 0;
            *regWrite = 0;
            *memRead = 0;
            *memWrite = 1;
            *branch = 0;
            *jump = 0;
            *aluOp1 = 0;
            *aluOp0 = 0;
            break;


        // branch equal
        case 0b001000:
            //*regDst = 0;
            *aluSrc = 0;
            //*memToReg = 0;
            *regWrite = 0;
            *memRead = 0;
            *memWrite = 0;
            *branch = 1;
            *jump = 0;
            *aluOp1 = 0;
            *aluOp0 = 1;
            break;


        // jump
        case 0b000010:
            //*regDst = 0;
            //*aluSrc = 1;
            //*memToReg = 1;
            *regWrite = 0;
            //*memRead = 0;
            *memWrite = 0;
            *branch = 0;
            *jump = 1;
            //*aluOp1 = 0;
            //*aluOp0 = 0;
            break;

    }
}
