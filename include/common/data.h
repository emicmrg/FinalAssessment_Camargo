#ifndef __data_H__
#define __data_H__

#include <math.h>
//#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

int32_t powerFunction(int32_t number, uint8_t power);

#endif