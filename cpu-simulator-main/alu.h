/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef ALU_HEADER
#define ALU_HEADER
#include <stdbool.h>
#include <stdint.h>

void alu(int32_t A, int32_t B, bool aluOp1,  bool aluOp0, int8_t ALUinput, int32_t* aluResult, bool* zero);

#endif
