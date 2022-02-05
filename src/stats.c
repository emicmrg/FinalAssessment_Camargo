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
 * @file stats.c 
 * @brief Analyze an array of unsigned char
 *
 * This code will analyze an array and get some statistics such as minimum, maximum, median and mean.
 * In addition, the original array will be printed and reorder from the 
 * large to small value and then, printed too.
 *
 * @author Emilio Camargo
 * @date 01/20/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char medianM=0, meanM=0, maximumM=0, minimumM=0;
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);

  medianM = find_median(test, SIZE);
  meanM = find_mean(test, SIZE);
  maximumM = find_maximum(test, SIZE);
  minimumM = find_minimum(test, SIZE);

  print_statistics(medianM, meanM, maximumM, minimumM);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char median, unsigned char mean, unsigned char maximum, unsigned char minimum){
  printf("----STATISTICS----\n");
  printf("Median = %d\n", median);
  printf("Mean = %d\n", mean);
  printf("Minimum = %d\n", minimum);
  printf("Maximum = %d\n", maximum);
}

void print_array(unsigned char *arrayData, int arrayLength){
  int i=0;
  printf("----ORIGINAL ARRAY----");
  for(i; i<arrayLength; i++){
    if((i%8)==0){
      printf("\n");
    }
    printf("%d, ", arrayData[i]);
  }
  printf("\n");
}

int find_median(unsigned char *arrayData, int arrayLength){
  unsigned char median=0;
  
  if((arrayLength%2)==0){
    median = (arrayData[arrayLength/2]+arrayData[(arrayLength/2)-1])/2;
  } else{
    median = arrayData[(arrayLength/2)];
  }
	return median;
}

int find_mean(unsigned char *arrayData, int arrayLength){
  unsigned char mean=0;
  int i=0, suma=0;
  for(i; i<arrayLength; i++){
    suma += arrayData[i];
  }
  mean = suma/arrayLength;
	return mean;
}

int find_maximum(unsigned char *arrayData, int arrayLength){
  unsigned char maximum=0;
  
  maximum = arrayData[arrayLength-arrayLength];

	return maximum;
}

int find_minimum(unsigned char *arrayData, int arrayLength){
  unsigned char minimum=0;
  
  minimum = arrayData[arrayLength-1];

	return minimum;
}

void sort_array(unsigned char *arrayData, int arrayLength){
  int i=39, j=39, pivote=0;
  printf("----SORT ARRAY----");
  for(i; i>=0; i--){
    for(j=39; j>=0; j--){
      if(arrayData[i]<arrayData[j]){
        pivote = arrayData[i];
        arrayData[i] = arrayData[j];
        arrayData[j] = pivote;
      }
    }
  }
  for(i=0; i<arrayLength; i++){
    if((i%8)==0){
      printf("\n");
    }
    printf("%d, ", arrayData[i]);
  }
  printf("\n");
}
