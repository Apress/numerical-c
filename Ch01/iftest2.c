#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Example of an if then else if operation */
int main()
{
     int this_is_a_number;

	printf( "Please enter an integer between 1 and 10:\n " );
    	scanf( "%d", &this_is_a_number );

	if (this_is_a_number <6)
		printf( "This number is less than 6;\n " );


	printf( "Please enter an integer between 10 and 20:\n " );
    	scanf( "%d", &this_is_a_number );

	if (this_is_a_number <16)
	{
		printf( "This number is less than 16\n " );
	}
	else if (this_is_a_number == 20)
		{
			printf( "This number is 20\n " );
		}
		else
		{
			printf( "This number is greater than 15\n " );
		}
     
    return 0;
}