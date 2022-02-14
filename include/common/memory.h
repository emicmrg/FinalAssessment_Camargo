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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
//#define NULL (0)

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move and copy elements in a data array
 *
 * Given a pointer from source and destination and int value of length,
 * this will move and copy the address from the source to destination. 
 *
 * @param src Source pointer
 * @param dst Destination pointer
 * @param length Length of bytes to move from src to dst
 *
 * @return uint8_t
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, uint8_t length);

/**
 * @brief Move and copy elements in a data array
 *
 * Given a pointer from source and destination and int value of length,
 * this will move and copy the address from the source to destination while
 * handling overlap of source and destination. 
 *
 * @param src Source pointer
 * @param dst Destination pointer
 * @param length Length of bytes to move from src to dst
 *
 * @return uint8_t
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, uint8_t length);

/**
 * @brief Set given memory locations
 *
 * This function will take a pointer to a source memory location and 
 * set with a given value. 
 *
 * @param src Source pointer
 * @param length Length in bytes
 * @param value Value to set all given memory locations
 *
 * @return uint8_t
 */
uint8_t * my_memset(uint8_t * src, uint8_t length, uint8_t value);

/**
 * @brief Set with zero memory allocations
 *
 * Given a pointer to a char data set and a length in bytes,
 * clear means to set to zero. 
 *
 * @param src Source pointer
 * @param length Length in bytes
 *
 * @return uint8_t
 */
uint8_t * my_memzero(uint8_t * src, uint8_t length);

/**
 * @brief Reverse order of bytes
 *
 * Given a pointer and a length in bytes, this function will reverse
 * the order of all the bytes. 
 *
 * @param src Source pointer
 * @param length Length of bytes
 *
 * @return uint8_t
 */
uint8_t * my_reverse(uint8_t * src, uint8_t length);

/**
 * @brief Reserve space in dynamic memory
 *
 * This function takes number of words to allocate in dynamic memory 
 *
 * @param length Length of bytes
 *
 * @return uint8_t
 */
int32_t * reserve_words(uint8_t length);

/**
 * @brief Free space in dynamic memory
 *
 * This function free the taken number of words allocated in dynamic memory  
 *
 * @param src Source pointer
 *
 * @return void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
