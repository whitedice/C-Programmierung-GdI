/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   outputControl.h
 * Author: nicolai
 *
 * Created on 14. September 2021, 11:08
 */

#ifndef OUTPUTCONTROL_H
#define OUTPUTCONTROL_H
#include <stdint.h>
#include <stdbool.h>
void outputControl(int16_t op, bool* regDst, bool* aluSrc, bool* memToReg, \
        bool* regWrite, bool* memRead, bool* memWrite, bool* branch, bool* jump,\
        bool* aluOp0, bool* aluOp1);


#endif /* OUTPUTCONTROL_H */
