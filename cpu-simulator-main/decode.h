/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   decode.h
 * Author: nicolai
 *
 * Created on 14. September 2021, 12:10
 */
#include <stdint.h>
#ifndef DECODE_H
#define DECODE_H

void instructionDecode(uint32_t instruction, uint16_t *op, uint16_t *rs, uint16_t *rt, uint16_t *rd, uint16_t *pcControl, uint32_t *jumpDest);
#endif /* DECODE_H */
