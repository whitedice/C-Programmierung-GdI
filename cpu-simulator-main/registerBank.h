/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef REGISTERBANK_HEADER
#define REGISTERBANK_HEADER
#include <stdint.h>

void readRegister(int16_t readRegister1, int16_t readRegister2, int32_t* A, int32_t* B);
void writeRegister(int16_t number, int32_t value);
#endif
