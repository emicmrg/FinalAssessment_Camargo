#include "../include/common/memory.h"
#include "../include/common/data.h"
#include "../include/common/platform.h"
#include <stdint.h>
#include <stddef.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t negativeFlag= 0;
  uint8_t contador= 0;
  uint8_t asignarNum= 0;  
  
  if (data < 0){
    negativeFlag = 1;
    data = data*-1;
  }
  while (data != 0){
    asignarNum = data % base;
    *(ptr + contador)= (asignarNum > 9) ? (asignarNum - 10) + 'a' : asignarNum + '0';
    contador++;
    data= data / base;
  }
  if (negativeFlag){
    *(ptr + contador) = '-';
    contador++;
  }
  contador++;
  *(ptr + contador) = '\0'; 
  my_reverse(ptr, (contador - 1));
  
  return contador;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int32_t numero = 0;
  uint8_t negativeFlag = 0;

  if(*ptr == '-'){
    negativeFlag = 1;
    ptr++;
    digits--;
  }

  digits--;

  for(int i = 0; i < digits; i++){
    numero = numero * base + *ptr - '0';
    ptr++;
  }
  if(negativeFlag){
    numero = -numero;
  }

  return numero;
}