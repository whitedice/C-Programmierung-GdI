/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "memory.h"
#include <unistd.h>
#include <fcntl.h>


int fd;
int len;

int32_t readFile(char* fn, int8_t** memory) {
    printf("readFile entered\n");
    FILE *fd = fopen(fn, "rb");

    if (fd == NULL)
      return 0;

    fseek(fd, 0L, SEEK_END);
    long len = ftell(fd);
    fseek(fd, 0L, SEEK_SET);

    if (len == 0)
      return len;
    printf("file size %li\n",len);
    *memory = (int8_t*) calloc(len,1);
    fread(*memory, sizeof (char), len, fd);
    fclose(fd);
    for (int i=0; i<len; i++) {
      printf("%i %x\n",i,(*memory)[i]);
    }

    printf("readFile complete\n");
    return len;
}

int32_t readMem(int32_t instruction_pointer, int8_t* memory) {
    int32_t value;
    for (int i = 0; i < 4; i++)
        ((int8_t*) & value)[3 - i] = memory[instruction_pointer + i];
    return value;
}

void writeMem(int32_t address, int32_t value, int8_t* memory) {
    for (int i = 0; i < 4; i++) {
        int8_t temp = ((int8_t*) & value)[3 - i];
        memory[address + i] = temp;
    }
}

void writeFile(int8_t* memory, int32_t size) {
    printf("writeFile entered, write %i bytes\n",size);
    FILE *fd;
    if ((fd=fopen("memory.dump", "wb")) == NULL) {
      printf("Memory Dump not possible. Error opening file.\n");
      exit(1);
    }
    for (int i=0; i<size; i++) {
      printf("%i %x\n",i,memory[i]);
      fwrite((const void *)&(memory[i]), 1 , 1 ,fd);
    }
    fclose(fd);
    printf("writeFile complete\n");
}
