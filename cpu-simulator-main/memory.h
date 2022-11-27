/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef MEMORY_HEADER
#define MEMORY_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t readFile(char* fn, int8_t** memory);
int32_t readMem(int32_t instruction_pointer, int8_t* memory);
void writeMem(int32_t address, int32_t value, int8_t* memory);
void writeFile(int8_t* memory, int32_t size);

#endif
