#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a forloop (setting the forloop limit)*/
main() 

{ 

	float this_is_a_number ,  total;
	int i,forlimit;

	total = 0;
	printf( "Please enter forloop limit:\n " );
    		scanf( "%d", &forlimit );/* entered limit stored in forlimit */
	for(i=0;i<forlimit;i++)
	{

    		printf( "Please enter a number:\n " );
    		scanf( "%f", &this_is_a_number );
		total = total + this_is_a_number;

	}
	printf("Total Sum is = %f\n",total); 

 
}
