/*quad3 - first attempt at quadratic solver*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
	double a, b, c,xa, xb;

	/* prompt and read in coefficients of x^2,x and constant */
	printf("enter a value");
	scanf("%lf", &a);
	printf("enter b value");
	scanf("%lf", &b);
	printf("enter c value");
	scanf("%lf", &c);
	if (pow(b, 2) < 4 * a*c) /* test for real root */
	{
		/* not real root */
		printf("Not a real root");
	}
	else
	{
		/* real root */
		xa = (-b + sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
		xb = (-b - sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
		printf("Roots are %lf and %lf", xa, xb);
	}

}
