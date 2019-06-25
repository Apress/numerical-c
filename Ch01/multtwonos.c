#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*  multiply two floating point numbers */

int main()
{
    float this_is_a_number1 , this_is_a_number2 , total;

   	 printf( "Please enter a number:\n " );
  	  scanf( "%f", &this_is_a_number1 );
   	 printf( "You entered %f\n", this_is_a_number1 );
    
	printf( "Please enter another number: \n" );
   	 scanf( "%f", &this_is_a_number2 );
  	  printf( "You entered %f\n", this_is_a_number2 );
    
	total = this_is_a_number1 * this_is_a_number2;
	printf( "product is %f\n", total );
	
    return 0;
}
