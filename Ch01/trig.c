#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/* Illustration of the common trigonometric functions */

int main()
{
	#define PI 3.14159265

	float angle , radianno , answer;

	/* The cosine function */  

	printf( "cosine function:\n " );
    	printf( "Please enter angle in degrees:\n " );
    	scanf( "%f", &angle );
   	 printf( "You entered %f\n", angle );
	radianno = angle*(2*PI/360);
	answer = cos(radianno);
	printf( "cos of %f is %f\n",angle, answer );
  
	/* The sine function */  

	printf( "sine function:\n " );
    	printf( "Please enter angle in degrees:\n " );
    	scanf( "%f", &angle );
   	 printf( "You entered %f\n", angle );
	radianno = angle*(2*PI/360);
	answer = sin(radianno);
	printf( "sin of %f is %f\n",angle, answer );
    
	/* The tangent function */
	
	printf( "tangent function:\n " );
    	printf( "Please enter angle in degrees:\n " );
    	scanf( "%f", &angle );
   	 printf( "You entered %f\n", angle );
	radianno = angle*(2*PI/360);
	answer = tan(radianno);
	printf( "tan of %f is %f\n",angle, answer );
    
    return 0;





    
}
