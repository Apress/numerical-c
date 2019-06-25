/*	trialimp */
/*	program uses x^2 -8x - 13 =0*/
/*	equation is solved by trial & improvement */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{


	float p2, p1, lower, upper;

	double testhigh, testlow, testvalue, middle;
	float constval;
	int i, iterations;



	/* Your curve should cross the x-axis */
	/* Here, your lower value is a value of x where your curve is below the x-axis */
	/* Your upper value is a value of x where your curve is above the x-axis */
	/* Both values should be close to where your curve crosses the x-axis */

	printf("enter initial lower value");
	scanf("%f", &lower);
	printf("enter initial upper value");
	scanf("%f", &upper);
	printf("enter number of iterations");
	scanf("%d", &iterations);

	/* Preset constant values  */
	p2 = 1;/* coefficient of power of x squared */
	p1 = -8;/* coefficient of x */
	constval = -13; /* numeric constant*/

	testlow = lower;
	testhigh = upper;
	printf("Equation is:-%f x**2 %f x %f=0\n", p2, p1, constval);
	/*printf("%f x**2 %f x= %f\n", p2,p1,constval);*/
	for (i = 0;i < iterations;i++)
	{

		middle = (testhigh + testlow) / 2;
		testvalue = pow(middle, 2) - 8 * middle - 13;

		if (testvalue == 0)
		{
			printf("x is %f", middle);
			return(0);
		}
		if (testvalue > 0)
		{
			testhigh = middle;/* replace upper value with this one */
		}
		else
		{
			testlow = middle; ;/* replace lower value with this one */

		}

	}
	printf("x is %f", middle);

}

