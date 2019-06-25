  /*trapezium - first attempt at trapezium method*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{

	double p6, p5, p4, p3, p2, p1, p0, lower, upper;
	
	double stripwidth, xposn;
	double middlevalues, zero, width, area;
	double yarr[10002]; /* Array to store lengths of sides of each trapezium */
	int i, strips, highpower;

	/* Preset constant values to zzero */

	p6 = 0.0;
	p5 = 0.0;
	p4 = 0.0;
	p3 = 0.0;
	p2 = 0.0;
	p1 = 0.0;
	p0 = 0.0;
   	/* Enter the highest power of x in your equation */
		/* (so that you don't have to enter values if you don't have higher powers) */

	printf("enter highest power of x (max 6)");
	scanf("%d", &highpower);

	/* Enter the coefficient for each of your powers */

	switch (highpower) {
	case 6:
		printf("enter coefficient of x power 6(-9 to 9)");
		scanf("%lf", &p6);
	case 5:
		printf("enter coefficient of x power 5(-9 to 9)");
		scanf("%lf", &p5);
	case 4:
		printf("enter coefficient of x power 4(-90 to 9)");
		scanf("%lf", &p4);
	case 3:
		printf("enter coefficient of x power 3(-9 to 9)");
		scanf("%lf", &p3);
	case 2:
    		printf("enter coefficient of x power 2(-9 to +9)");
		scanf("%lf", &p2);
	case 1:
		printf("enter coefficient of x (-9 to +9)");
		scanf("%lf", &p1);
	case 0:
		printf("enter numeric constant (-999 to +999)");
		scanf("%lf", &p0);
	default:
		printf("default");

	}

	/* Display the equation you have entered */

	printf("Equation is:- ");
	printf("%lf x**6+%lf x**5+%lf x**4+%lf x**3 +%lf x**2 %lf x= %lf\n", p6, p5, p4, p3, p2, p1, p0);



	printf("enter lower limit");/* the lower x value for your integration */
	scanf("%lf", &lower);
	printf("enter upper limit");/* the upper x value for your integration */
	scanf("%lf", &upper);
	printf("enter number of strips (max 1000)");/* how many trapezia are you splitting your area into */
	scanf("%d", &strips);
	if (strips > 10000)
	{
		printf("Number of strips exceeds 10000");
		return(0);
	}
	zero = 0;
	width = upper - lower;/* overall x-distance between limits of our integration */
	stripwidth = width / strips; /* stripwidth is perpendicular height of each trapezium */
	/* yarr[1] contains the First side from our trapezium area formula */
	yarr[1] = p6 * pow(lower, 6) + p5 * pow(lower, 5) + p4 * pow(lower, 4) + p3 * pow(lower, 3) + p2 * pow(lower, 2) + (p1*lower) + p0;
	/* yarr[strips+1] contains the Last side from our trapezium area formula */
	yarr[strips + 1] = p6 * pow(upper, 6) + p5 * pow(upper, 5) + p4 * pow(upper, 4) + (p3*pow(upper, 3)) + (p2*pow(upper, 2)) + (p1*upper) + p0;
	middlevalues = zero;

	/* forloop loops round yarr to add all the values of the sides of the trapezia in the formula */
	for (i = 1;i < strips;i++)
	{

		xposn = lower + (i*stripwidth);
		yarr[i + 1] = (p6*pow(xposn, 6) + p5 * pow(xposn, 5) + p4 * pow(xposn, 4) + p3 * pow(xposn, 3)) + (p2*pow(xposn, 2)) + (p1*xposn) + p0;
		middlevalues = middlevalues + yarr[i + 1];
	}
/* Now collect the first side, the last side and 2x the middle sides and multiply by 0.5x the stripwidth (as in the formula) */

	area = 0.5*stripwidth*(yarr[1] + 2 * middlevalues + yarr[strips + 1]);
/* Now we have the area */

	printf("Area is %lf\n", area);

}
