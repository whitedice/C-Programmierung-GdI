/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nicolai
 *
 * Created on 13. September 2021, 14:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "alu.h"

/*
 * 
 */
int16_t main(int16_t argc, char** argv) {

	int8_t ALUInput;
	int32_t A, B; // ALU Input Values
	int32_t aluResult; // ALU output values
	bool zero; // ALU output

	bool aluOp1, aluOp0;

/* Add values */
	ALUInput = 0x2;
	A = 30; B = 6;
	aluOp1 = 1; aluOp0 = 0; 
	alu(A, B, aluOp1, aluOp0, ALUInput, &aluResult, &zero);
	printf("Add Result %i\n", aluResult);
	
/* Sub values */
	ALUInput = 0x6;
	A = 4; B = 5;
	aluOp1 = 1; aluOp0 = 0; 
	alu(A, B, aluOp1, aluOp0, ALUInput, &aluResult, &zero);
	printf("Sub Result %i\n", aluResult);

/* Or values */
	ALUInput = 0x1;
	A = 30; B = 5;
	aluOp1 = 1; aluOp0 = 0; 
	alu(A, B, aluOp1, aluOp0, ALUInput, &aluResult, &zero);
	printf("Or Result %i\n", aluResult);

/* And values */
	ALUInput = 0x0;
	A = 30; B = 5;
	aluOp1 = 1; aluOp0 = 0; 
	alu(A, B, aluOp1, aluOp0, ALUInput, &aluResult, &zero);
	printf("And Result %i\n", aluResult);


    return (EXIT_SUCCESS);
}

