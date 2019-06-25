/*	regression */
/*	user enters points.*/
/*	regression of x on y calculated */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{


	float xpoints[10], ypoints[10];
	float sigmax, sigmay, sigmaxy, sigmaysquared, xbar, ybar;
	float fltcnt, sxy, syy, c, d;
	int i, points;

	/* User asked for number of points on scatter graph */
	printf("enter number of points (max 10 ) \n");
	scanf("%d", &points);
	if (points > 10)
	{
		printf("error - max of 10 points\n");

	}
	else
	{
		sigmax = 0;
		sigmay = 0;
		sigmaxy = 0;

		sigmaysquared = 0;

		/* User enters points  */
		for (i = 0;i < points;i++)
		{
			printf("enter point (x and y separated by space) \n");
			scanf("%f %f", &xpoints[i], &ypoints[i]);
			sigmax = sigmax + xpoints[i];
			sigmay = sigmay + ypoints[i];
			sigmaxy = sigmaxy + xpoints[i] * ypoints[i];

			sigmaysquared = sigmaysquared + (float)pow(ypoints[i], 2);
		}
		printf("points are \n");
		for (i = 0;i < points;i++)
		{
			printf(" \n");
			printf("%f %f", xpoints[i], ypoints[i]);

		}
		printf(" \n");
		fltcnt = (float)points;

		/* regression variables calculated */
		xbar = sigmax / fltcnt;
		ybar = sigmay / fltcnt;
		sxy = (1 / fltcnt)*sigmaxy - xbar * ybar;

		syy = (1 / fltcnt)*sigmaysquared - ybar * ybar;

		d = sxy / syy;
		c = xbar - d * ybar;


		/* Regression line */
		printf("Equation of regression line x on y  is\n ");
		printf(" x=%f + %fy", c, d);
	}

}

