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

#include "memory.h"
/*
#include "alu.h"
#include "registerBank.h"
#include "outputControl.h"
#include "decode.h"
*/
/*
 * 
 */
int16_t main(int16_t argc, char** argv) {

    printf("Welcome to Mips Emulator\n");

    bool terminate = 0;
    uint32_t instruction_pointer;
    int8_t* memory;
    uint32_t memorysize;

   // Read from File into Memory

    if (argc < 2) {
        // printf("Usage : ./cpu <filename>");
        // exit(0);
        memorysize = readFile("test.o", &memory);
    } else {
        memorysize = readFile(argv[1], &memory);
    }

    if (memorysize == 0) {
        printf("File empty or missformed");
        exit(0);
    }
    // Set IP to start of Memory

    //    instruction_pointer = 0x400000; // This would be the default
    instruction_pointer = 0x24;


    // State Variables for Memory Control
    bool IRwrite;

    // CPU main loop

    while (!terminate) {

        // Read from or Write to Memory
        uint32_t instruction = readMem(instruction_pointer, memory);

        if (instruction == 0xFFFFFFFF) {
            terminate = true;
            continue;
        }
        // Decode instruction
        int16_t op; //31-26
        int16_t rs; //25-21
        int16_t rt; //20-16
        int16_t rd; //15-11
        int16_t pcControl; //15-0

        int32_t jumpDest; //25-0

	// Decodes the instruction into the different parts
        instructionDecode(instruction, &op, &rs, &rt, &rd, &pcControl, &jumpDest);

        bool regDst, aluSrc, memToReg, regWrite, memRead, memWrite, branch, jump, aluOp1, aluOp0;

	// calculate control lane settings
        outputControl(op, &regDst, &aluSrc, &memToReg, &regWrite, &memRead, &memWrite, &branch, &jump, &aluOp1, &aluOp0);

        // Read Registers / Mem
        int32_t A, B;
        readRegister(rs, rt, &A, &B);

        // Perform ALU Operation
        int32_t aluResult;
        bool zero;
        
        // in der letzten Version haben wir aluControl / aluInput manuell gesetzt
        // Definieren sie hier die Logik zum Ermitteln von ALU Input
        int16_t aluInput;
       if (!aluOp1 && !aluOp0) // LW & SW
          aluInput = 0x02;
       else 

/*
       ...
       */

        
        if (aluSrc)
            alu(A, pcControl, aluOp1, aluOp0, aluInput, &aluResult, &zero);
        else
            alu(A, B, aluOp1, aluOp0, aluInput, &aluResult, &zero);


        // Write Registers

        if (regWrite) {

            if (regDst == 0)
                rd = rt;
            if (memToReg)
                writeRegister(rd, readMem(aluResult, memory));
            else
                writeRegister(rd, aluResult);
        }

        // Write Memory
        if (memWrite)
            writeMem(aluResult, B, memory);

        // Calculate next IP value
        if (jump) {
            // mask PC
            instruction_pointer &= 0x780000;
            // extend jumpDest to 32 bit (alraedy done)
            // shift left 2 jumpDest
            jumpDest = jumpDest << 2;
            // combine PC and jumpDest
            instruction_pointer |= jumpDest;
        } else if ((zero && branch)) {
            int16_t* test;
            test = (int16_t*) & instruction;

            // 16 to 32 bit extend
            int32_t value = 0;
            value = test[1];

            // sign extend
            if ((test[1] >> 15) == 1)
                value |= 0xFFFF0000;

            // shift left by 2
            value = value << 2;
            instruction_pointer += value;
        } else {
            instruction_pointer += 4;
        }

    }
*/
    writeFile(memory,memorysize);
    return (EXIT_SUCCESS);
}

