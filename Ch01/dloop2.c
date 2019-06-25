#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a do loop */
main() 


{ 

	float this_is_a_number ,  total;
	int i;

	total = 0;
	i=0;
	do{
	

    		printf( "Please enter a number:\n " );
    		scanf( "%f", &this_is_a_number );
		total = total + this_is_a_number;
		i++;

	}while( i < 10);
	printf("Total Sum is = %f\n",total); 

 
}