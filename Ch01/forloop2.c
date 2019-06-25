#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a forloop */
main() 


{ 

	float this_is_a_number ,  total;
	int i;

	total = 0;

	/* forloop goes round 10 times */

	for(i=0;i<10;i++)
	{
		
    		printf( "Please enter a number:\n " );
    		scanf( "%f", &this_is_a_number );
		total = total + this_is_a_number;

	}
	printf("Total Sum is = %f\n",total); 

 
}