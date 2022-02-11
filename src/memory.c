/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "../include/common/memory.h"
#include "../include/common/platform.h"
#include <stddef.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, uint8_t length){
	
	int16_t datatoMove[length];
	// Copy to buffer
	my_memcopy(src, datatoMove, length);
	
	// Copy from buffer to destination
	my_memcopy(datatoMove, dst, length);
   
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, uint8_t length){
    //PRINTF("1dst = %d ", *dst);
    for (int dataCount=0; dataCount<length; dataCount++){
        *(dst+dataCount) = *(src+dataCount);
        //PRINTF("DST+dataCount= %d ", (dst+dataCount));
    }
    //PRINTF("2dst = %d \n", *dst);    
    return dst;
}

uint8_t * my_memset(uint8_t * src, uint8_t length, uint8_t value){
    for (int cellCount=0; cellCount<length; cellCount++){
        *(src+cellCount) = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, uint8_t length){
     for (int cellCount=0; cellCount<length; cellCount++){
        *(src+cellCount) = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, uint8_t length){
    uint8_t numberOfSwapOperations = length/2;
    uint8_t temp=0;
    for (int counter=0; counter<numberOfSwapOperations; counter++){
        temp = *(src + counter);
        *(src+counter) = *(src+length-1-counter);
        *(src+length-1-counter) = temp;
    }
    return src;
}

int32_t * reserve_words(uint8_t length){
    if (((int32_t *) malloc(length)) != NULL){
        return ((int32_t *) malloc(length));
    }
    else return NULL;
}

void free_words(uint32_t * src){
    free((void *)src);
}