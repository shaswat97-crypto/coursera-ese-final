#include<stdlib.h>
#include<stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

	//meat of code
	//conversion of decimal to any base
	int k=0, i, index, j, length;
	if(base != 10){
	while(data>0){
	
		*(ptr+k) = data%base;
		data = data/base;
		k++;
	}
	length = k;
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
        swap(ptr, index);
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
	}
	*(ptr+k) = '\0';//setting last byte as null terminator
	return k;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

	int32_t data = 0;
	uint8_t i = digits-2;
	uint8_t temp = (uint8_t)base;
	base = 1;
	/* Checking for a Null pointer */
	if(!ptr)
		return -1;
	/* String to Integer conversion except last character ( MSB ) */
	while( i > 0 ) {
		data += *(ptr + i ) * ( base ) ;
		i = i - 1;
		base*= temp;
	}

	/* Last Character check for -ve sign */
	if(temp == 10 && *(ptr + i) == '-')
		data = -data;
	else
		data += *(ptr + i) * ( base );

	return data;
