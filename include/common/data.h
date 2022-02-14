/**
 * @file data.h 
 * @brief Header file
 *
 * This file got the function prototypes for the data part according to 4th module
 * of the Coursera course Introduction to Embedded Systems
 *
 * @author Emilio Camargo
 * @date 02/14/2022
 *
 */

#ifndef __data_H__
#define __data_H__

#include <math.h>

/**
 * @brief Integer to ASCII.
 *
 * Given an integer this function will convert data to an ASCII string.
 *
 * @param data Integer data
 * @param ptr Allocated pointer
 * @param base Power base
 *
 * @return uint8_t
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Move and copy elements in a data array
 *
 * Given an integer this function will convert data to an ASCII string. 
 *
 * @param ptr Allocated pointer
 * @param digits Number of digits in character set
 * @param base Power base
 *
 * @return uint8_t
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif