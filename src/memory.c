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
#include "memory.h"

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

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	int i;
 char* sflag;
 char* dflag;
 sflag = (char*)src;
 dflag = (char*)dst;
 for(i=0; i<length; i++){
 if (*(dflag+i) != *(sflag+i)){
          *(dflag+i) = *(sflag+i);
 }
 }
 return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

	int i;
 char* sflag;
 char* dflag;
 sflag = (char*)src;
 dflag = (char*)dst;
 for(i=0; i<length; i++){
          *(dflag+i) = *(sflag+i);
 }
 return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

	int i;
 char* sflag;
 sflag = (char*)src;
 for(i=0; i<length; i++){
 if (*(sflag+i) = value){
          *(dflag+i) = value;
 }
 }
 return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){

	int i;
 char* sflag;
 sflag = (char*)src;
 for(i=0; i<length; i++){
 if (*(sflag+i) != 0){
          *(sflag+i) = 0;
 }
 }
 return src;
}
uint8_t * my_reverse(uint8_t * src, size_t length){

	 int i,j, index;
	 //debugging part of code
	 /*
 char *d1;
 d1=(char*)src;
 */
 for(i=0; i<length-1;i++){
     index = 0;
      for(j=length-i; j>1;j--){
         //debugging part of code
         /*
         printf("BEFORE , j = %d\n", j);
         for(int k=0; k<length; k++){
             printf("%d\n ",(*(d1+k)));
         }
         */
        swap(src, index);
        index++;
        //debugging part of code
        /*
        printf("AFTER\n");
        for(int k=0; k<length; k++){
             printf("%d\n ",(*(d1+k)));
        }
        */
     }
 }
 return src;
}
void swap(uint8_t *a,int index){
    int temp;
    char *p0;
    char *p1;
    p0 = (char*)a;
    p1 = p0+1;
    p0=p0+index; p1=p1+index;
    temp = *p0;
    *p0=*p1;
    *p1=temp;

}

int32_t * reserve_words(size_t length){

	int *ptr;
	ptr = (int32_t*)malloc(length*(sizeof(int32_t)));
}

void free_words(int32_t * src){

	free(src);
}
