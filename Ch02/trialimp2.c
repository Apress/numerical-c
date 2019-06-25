/*	trialimp */
/*	program uses x^3 +2x^2 - x =0*/
/*	equation is solved by trial & improvement */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{


	float p3, p2, p1, lower, upper;

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
	p3 = 1;/* coefficient of power of x power 3 */
	p2 = 2;/* coefficient of power of x squared */
	p1 = -1;/* coefficient of x */
	constval = 0; /* numeric constant*/

	testlow = lower;
	testhigh = upper;
	/*printf("Equation is:-%f x**2 %f x %f=0\n", p3,p2,constval);*/

	printf("Equation is:%f x**3 %f x**2 %f x= 0\n", p3, p2, p1);
	for (i = 0;i < iterations;i++)
	{


		middle = (testhigh + testlow) / 2;
		testvalue = pow(middle, 3) + 2 * pow(middle, 2) - middle;

		if (testvalue == 0)
		{
			printf("x is %f", middle);
			/*exit(1);*/
			return(0);/*  test */
		}
		if (testvalue > 0)
		{
			testhigh = middle; ;/* replace upper value with this one */

		}
		else
		{
			testlow = middle; ;/* replace lower value with this one */

		}

	}
	printf("x is %f", middle);
}
