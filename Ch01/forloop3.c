#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a nested forloop */
main() 


{ 

	float this_is_a_number ,  total;
	int i,j;

	total = 0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<2;j++)
		{

    			printf( "Please enter a number:\n " );
    			scanf( "%f", &this_is_a_number );
			total = total + this_is_a_number;
		}

	}
	printf("Total Sum is = %f\n",total); 

 
}