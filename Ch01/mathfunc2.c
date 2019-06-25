#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
/* showing use of pow, sqrt and fabs functions */
int main()
{
	
	float answer, pownum,power,sqroot,fabsno;

	/* find x raised to power y number */

	printf( "power:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &pownum );
   	 printf( "You entered %f\n", pownum );
    	printf( "Please enter power:\n " );
    	scanf( "%f", &power );
   	 printf( "You entered %f\n", power );
	
	answer = pow(pownum,power);
	printf( "%f raised to power %f is %f\n",pownum,power, answer );

	/* find square root of number */

	printf( "square root:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &sqroot );
   	printf( "You entered %f\n", sqroot );
    	
	answer = sqrt(sqroot);
	printf( "The square root of %f is %f\n",sqroot, answer );

	/* find absolute value of number */

	printf( "absolute value:\n " );
    	printf( "Please enter number:\n " );
    	scanf( "%f", &fabsno );
   	printf( "You entered %f\n", fabsno );
    	
	answer = fabs(fabsno);
	printf( "The absolute value of %f is %f\n",fabsno, answer );



	
}