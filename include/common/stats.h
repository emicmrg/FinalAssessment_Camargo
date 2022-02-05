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
 * @file stats.h 
 * @brief Header file
 *
 * This file got the function prototypes for the first module of the course
 * Introduction to Embedded Systems
 *
 * @author Emilio Camargo
 * @date 01/20/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(unsigned char median, unsigned char mean, unsigned char maximum, unsigned char minimum);
void print_array(unsigned char *arrayData, int arrayLength);
int find_median(unsigned char *arrayData, int arrayLength);
int find_mean(unsigned char *arrayData, int arrayLength);
int find_maximum(unsigned char *arrayData, int arrayLength);
int find_minimum(unsigned char *arrayData, int arrayLength);
void sort_array(unsigned char *arrayData, int arrayLength);

/**
 * @brief Print statistics
 *
 * This function will print the statistics of the given array where the stats are minimum,
 * maximum, median and mean.
 *
 * @param median This will be the median statistic
 * @param mean This will be the mean statistic
 * @param maximum This will be the maximum statistic
 * @param minimum This will be the minimum statistic
 *
 * @return No return because it is a void function
 */

/**
 * @brief Print array
 *
 * Given an array, prints the array to the screen
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return No return because it is a void function
 */

/**
 * @brief Find median
 *
 * This function will receive an array data and a length and needs to return the median
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return result An unsigned char variable for the median value
 */

/**
 * @brief Find mean
 *
 * This function will receive an array data and a length and needs to return the mean
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return result An unsigned char variable for the mean value
 */

/**
 * @brief Find maximum
 *
 * This function will receive an array data and a length and needs to return the maximum
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return result An unsigned char variable for the maximum value
 */

/**
 * @brief Find minimum
 *
 * This function will receive an array data and a length and needs to return the median
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return result An unsigned char variable for the minimum value
 */

/**
 * @brief sort_array
 *
 * Given an array, sorts the array from largest to smallest.
 *
 * @param arrayData This will be the data of the given array
 * @param arrayLength This will be the length of the given array
 *
 * @return No return because it is a void function
 */


#endif /* __STATS_H__ */
