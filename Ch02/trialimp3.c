/*	trialimp */
/*	user enters an equation.*/
/*	equation is solved by trial & improvement */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{


	float p6, p5, p4, p3, p2, p1, lower, upper;

	double testhigh, testlow, testvalue, middle;
	float constval;
	int i,  iterations, highpower;

	/* Preset constant values to zero */

	p6 = 0.0;
	p5 = 0.0;
	p4 = 0.0;
	p3 = 0.0;
	p2 = 0.0;
	p1 = 0.0;
	constval = 0.0;

	/* Enter the highest power of x in your equation */
	/* (so that you don't have to enter values if you don't have higher powers) */

	printf("enter highest power of x (max 6)");
	scanf("%d", &highpower);

	/* Enter the coefficient for each of your powers */

	switch (highpower) {
	case 6:
		printf("enter coefficient of x power 6(-9 to 9)");
		scanf("%f", &p6);

	case 5:
		printf("enter coefficient of x power 5(-9 to 9)");
		scanf("%f", &p5);
	case 4:
		printf("enter coefficient of x power 4(-90 to 9)");
		scanf("%f", &p4);
	case 3:
		printf("enter coefficient of x power 3(-9 to 9)");
		scanf("%f", &p3);
	case 2:
		printf("enter coefficient of x power 2(-9 to +9)");
		scanf("%f", &p2);
	case 1:
		printf("enter coefficient of x (-9 to +9)");
		scanf("%f", &p1);
	case 0:
		printf("enter numeric constant (-999 to +999)");
		scanf("%f", &constval);
	default:
		printf("default");

	}
	/* Display the equation you have entered */

	printf("Equation is:- ");
	printf("%f x**6+%f x**5+%f x**4+%f x**3 +%f x**2 %f x= %f\n", p6, p5, p4, p3, p2, p1, constval);

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


	testlow = lower;
	testhigh = upper;

for (i = 0;i < iterations;i++)
	{


		middle = (testhigh + testlow) / 2;
		testvalue = p6 * pow(middle, 6) + p5 * pow(middle, 5) + p4 * pow(middle, 4) + p3 * pow(middle, 3) + p2 * pow(middle, 2) + p1 * middle + constval;

		if (testvalue == 0)
		{
			printf("x is %f", middle);
			return(0);
		}
		if (testvalue > 0)
		{
			testhigh = middle;
		}
		else
		{
			testlow = middle;
		}

	}
	printf("x is %f", middle);

}
