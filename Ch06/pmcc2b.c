/*product moment correlation coefficient - first attempt at pmcc*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
	double xpoints[10], ypoints[10];
	double sigmax, sigmay, sigmaxsquared, sigmaysquared, xbar, ybar, sigmaxy;
	double sxy, sxx, syy, sx, sy, r;
	int i, points;
	double fltcnt;


	/* User enters number of points in scatter graph */
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
		sigmaxsquared = 0;
		sigmaysquared = 0;

		/* User enters points in scatter graph */
		for (i = 0;i < points;i++)
		{
			printf("enter point (x and y separated by space) \n");
			scanf("%lf %lf", &xpoints[i], &ypoints[i]);
			/* totals incremented by x and y points */
			sigmax = sigmax + xpoints[i];
			sigmay = sigmay + ypoints[i];
			sigmaxy = sigmaxy + xpoints[i] * ypoints[i];
			sigmaxsquared = sigmaxsquared + pow(xpoints[i], 2);
			sigmaysquared = sigmaysquared + pow(ypoints[i], 2);
		}
		printf("points are \n");
		for (i = 0;i < points;i++)
		{
			printf(" \n");
			printf("%lf %lf", xpoints[i], ypoints[i]);

		}
		printf(" \n");
		fltcnt = points;
		/* variables in PMCC formula calculated */
		xbar = sigmax / fltcnt;
		ybar = sigmay / fltcnt;

		syy = (1 / fltcnt)*sigmaysquared - ybar * ybar;

		sxx = (1 / fltcnt)*sigmaxsquared - xbar * xbar;
		sx = sqrt(sxx);
		sy = sqrt(syy);
		sxy = (1 / fltcnt)*sigmaxy - xbar * ybar;

		/* PMCC value calculated */
		r = sxy / (sx*sy);
		printf("r is %lf", r);
	}


}
