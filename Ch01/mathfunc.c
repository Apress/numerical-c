#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
/* showing use of exp, log and log10 functions */
int main()
{
	
	float answer, expno,natlog,lb10;

	/* find exponent of entered number */

	printf( "exponental function:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &expno );
   	 printf( "You entered %f\n", expno );
	
	answer = exp(expno);
	printf( "exponent of %f is %f\n",expno, answer );

	/* find natural logarithm of entered number */

	printf( "natural logarithm function:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &natlog );
   	 printf( "You entered %f\n", natlog );
	answer = log(natlog);
	printf( "natural logarithm of %f is %f\n",natlog, answer );

	
	/* find log to base 10 of entered number */

	printf( "log to base 10 function:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &lb10 );
   	 printf( "You entered %f\n", lb10 );
	answer = log10(lb10);
	
	printf( "log to base 10 of %f iis %f\n",lb10, answer );
}