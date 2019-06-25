#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

int main()
{
	#define PI 3.14159265

	float angle , radianno , answer, arccos, arcsin, arctan;

	/* the arccos function */

	printf( "arccos function:\n " );
    	printf( "Please enter arccos:\n " );
    	scanf( "%f", &arccos );
   	 printf( "You entered %f\n", arccos );
	radianno = acos(arccos);
	answer = radianno*(360/(2*PI));
	printf( "arccos of %f in degrees is %f\n",arccos, answer );

	/* the arcsin function */

	printf( "arcsin function:\n " );
    	printf( "Please enter arcsin:\n " );
    	scanf( "%f", &arcsin );
   	 printf( "You entered %f\n", arcsin );
	radianno = asin(arcsin);
	answer = radianno*(360/(2*PI));
	printf( "arcsin of %f in degrees is %f\n",arcsin, answer );
	
	/* the arctan function */

	printf( "arctan function:\n " );
    	printf( "Please enter arctan:\n " );
    	scanf( "%f", &arctan );
   	 printf( "You entered %f\n", arctan );
	radianno = atan(arctan);
	answer = radianno*(360/(2*PI));
	printf( "arctan of %f in degrees is %f\n",arctan, answer );


   	
    return 0;





    
}