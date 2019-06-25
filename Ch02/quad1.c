/*quad1 -  quadratic solver with complex numbers*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{

	double a, b, c, xra, xia, xrb, xib, xa, xb;

	/* prompt and read in coefficients of x^2,x and constant */
	printf("enter A value");
	scanf("%lf", &a);
	printf("enter B value");
	scanf("%lf", &b);
	printf("enter C value");
	scanf("%lf", &c);
	if (pow(b, 2) < 4 * a*c) /* test for complex root */
	{
		/* complex root */
		/* switch b^2 and 4ac to find the positive root then add i to the answer*/
		printf("complex root\n");
		xra = -b / (2 * a);
		xia = sqrt((4 * a*c) - (pow(b, 2))) / (2 * a);
		xrb = -b / (2 * a);
		xib = -sqrt((4 * a*c) - (pow(b, 2))) / (2 * a);
		printf("Roots are %lf +%lfi and %lf - %lfi", xra, xia, xra, xia);
	}
	else
	{
		/* real root */
		xa = (-b + sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
		xb = (-b - sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
		printf("Roots are %lf and %lf", xa, xb);
	}

}
