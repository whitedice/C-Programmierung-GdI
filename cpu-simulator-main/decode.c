/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   decode.c
 * Author: nicolai
 * 
 * Created on 14. September 2021, 12:10
 */
#include <stdint.h>

void instructionDecode(uint32_t instruction, uint16_t *op, uint16_t *rs, uint16_t *rt, uint16_t *rd, uint16_t *pcControl, uint32_t *jumpDest) {
    //        int16_t op; //31-26
    //        int16_t rs; //25-21
    //        int16_t rt; //20-16
    //        int16_t rd; //15-11
    //        int16_t pcControl; //15-0
    //        int16_t jumpDest; //25-0

    *op = (instruction>>26);
    *rs = (instruction<<6)>>27;
    *rt = (instruction<<11)>>27;
    *rs = (instruction<<16)>>27;

    *pcControl = (instruction<<16)>>16;
    *jumpDest = (instruction<<6)>>6;
}