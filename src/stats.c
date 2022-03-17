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
 * @brief this file contains all the functions for stats.h file
 *
 * using this file we can perform all the tasks specified in the stats.h file such as sorting an array and much more
 *
 * @author Shashwat Shashank
 * @date 20 Feb, 2022
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
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */

void find_maximum(unsigned char a[SIZE]){
int temp, i = 0;
 if (a[0] > a[1])
        temp = a[0];
            else
            temp = a[1];
    for( i = 2; i < SIZE; i++){
        if (a[i] > temp)
            temp = a[i];
    }
    printf("Maximum: %d\n", temp);
}

void find_minimum(unsigned char a[SIZE]){
int temp, i = 0;
 if (a[0] < a[1])
        temp = a[0];
            else
            temp = a[1];
    for( i = 2; i < SIZE; i++){
        if (a[i] < temp)
            temp = a[i];
    }
    printf("Minimum: %d\n", temp);
}

void find_mean(unsigned char a[SIZE]){
int num, i = 0;

for (i=0; i<SIZE; i++){
    num += a[i];
}
i = num/SIZE;
printf("Mean: %d\n", i);
}
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sort_array(unsigned char array[], int length){
    int m, arr[SIZE];
    for(m = 0; m<SIZE; m++){
        arr[m] = array[m];
}
	int i, j;
	for(i=0; i<length-1;  i++){
		if (arr[i]<arr[i+1]){
            swap(&arr[i], &arr[i+1]);
			i = -1;
			}
	}
	printf("Sorted array:[");
	for(j = 0; j<length-1; j++){
        printf("%d, ", arr[j]);
	}
	printf("%d]\n", arr[j]);

}

void find_median(unsigned char array[], int length){
    int temp, k;
    int l, arr[SIZE];
    for(l = 0; l<SIZE; l++){
        arr[l] = array[l];
}
    int i, j;
	for(i=0; i<length-1;  i++){
		if (arr[i]<arr[i+1]){
            swap(&arr[i], &arr[i+1]);
			i = -1;
			}
	}

    if (length % 2 == 0){
        k = length/2;
        temp = (arr[k-1]+arr[k])/2;
        printf("Median: %d\n", temp);
    }
    else{
        k = (length-1)/2;
        printf("Median:[%d]\n", arr[k]);
    }

}

void print_statistics(unsigned char test[], int length){
    find_maximum(test);
    find_minimum(test);
    find_mean(test);
    sort_array(test, SIZE);
    find_median(test, SIZE);

}
void print_array(unsigned char array[], int length){
    int i;
    printf("Main array: [");
    for (i = 0; i<length-1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[i]);
}



