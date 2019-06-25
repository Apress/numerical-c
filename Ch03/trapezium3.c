/*trapezium -  trapezium method using a mix of direct and inverse functions */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
	double p6, p5, p4, p3, p2, p1, p0, lower, upper;
	double ip6, ip5, ip4, ip3, ip2, ip1, ip0;
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
	ip6 = 0.0;
	ip5 = 0.0;
	ip4 = 0.0;
	ip3 = 0.0;
	ip2 = 0.0;
	ip1 = 0.0;
	ip0 = 0.0;


	/* Enter the highest inverse power of x in your equation */
	/* (so that you don't have to enter values if you don't have higher powers) */

	printf("enter highest inverse power of x (max 4)");
	scanf("%d", &highpower);

	/* Enter the coefficient for each of your powers */

	switch (highpower) {

	case 4:
		printf("enter coefficient of inverse x power 4(-90 to 9)");
		scanf("%lf", &ip4);
	case 3:
		printf("enter coefficient of inverse x power 3(-9 to 9)");
		scanf("%lf", &ip3);
	case 2:
		printf("enter coefficient of inverse x power 2(-9 to +9)");
		scanf("%lf", &ip2);
	case 1:
		printf("enter coefficient of inverse x (-9 to +9)");
		scanf("%lf", &ip1);
	case 0:
		printf("enter numeric constant (-999 to +999)");
		scanf("%lf", &ip0);
	default:
		printf("default");

	}
	/* Enter the highest power of x in your equation */
	/* (so that you don't have to enter values if you don't have higher powers) */

	printf("enter highest power of x (max 4)");
	scanf("%d", &highpower);

	/* Enter the coefficient for each of your powers */

	switch (highpower) {

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
	printf("%lf x**-4+%lf x**-3 +%lf x**-2 %lf x**-1= %lf\n", p4, p3, p2, p1, p0);
	printf("%lf x**-4+%lf x**-3 +%lf x**-2 %lf x**-1= %lf\n", ip4, ip3, ip2, ip1, ip0);

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
	yarr[1] = p4 * pow(lower, 4) + p3 * pow(lower, 3) + p2 * pow(lower, 2) + p1 * pow(lower, 1) + p0 + ip4 * pow(lower, -4) + ip3 * pow(lower, -3) + ip2 * pow(lower, -2) + ip1 * pow(lower, -1);
	/* yarr[strips+1] contains the Last side from our trapezium area formula */
	yarr[strips + 1] = p4 * pow(upper, 4) + (p3*pow(upper, 3)) + (p2*pow(upper, 2)) + p1 * pow(upper, 1) + p0 + p4 * pow(upper, -4) + (p3*pow(upper, -3)) + (p2*pow(upper, -2)) + p1 * pow(upper, -1);
	middlevalues = zero;

	/* forloop loops round yarr to add all the values of the sides of the trapezia in the formula */
	for (i = 1;i < strips;i++)
	{
		xposn = lower + (i*stripwidth);
		yarr[i + 1] = p4 * pow(xposn, 4) + (p3*pow(xposn, 3)) + (p2*pow(xposn, 2)) + p1 * pow(xposn, 1) + p0 + ip4 * pow(xposn, -4) + (ip3*pow(xposn, -3)) + (ip2*pow(xposn, -2)) + ip1 * pow(xposn, -1);
		middlevalues = middlevalues + yarr[i + 1];
	}

	area = 0.5*stripwidth*(yarr[1] + 2 * middlevalues + yarr[strips + 1]);
	printf("Area is %lf\n", area);
}
T