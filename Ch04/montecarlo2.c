/* Montecarlo2 */
/*	integration using monte carlo */
/*	by counting relative areas */
/* integrates x^2 + y^2 = 4 in the first quadrant */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main()
{

	double x, y;
	double yupper, ylower, xupper, xlower;
	double  montearea, area;
	double totalexparea, totalarea;
	int j;
	int iterations;


	printf("enter lower limit\n");
	scanf("%lf", &xlower);
	printf("enter upper limit\n");
	scanf("%lf", &xupper);
	printf("xlower %lf xupper %lf\n", xlower, xupper);
	yupper = 2;/* fixed at 2 -see graph of function */
	ylower = pow(xlower, 2);
	printf("ylower %lf yupper %lf\n", ylower, yupper);
	area = yupper * (xupper - xlower);
	printf("area is %lf\n", area);
	printf("enter iterations up to 1000000\n");
	scanf("%d", &iterations);

	totalarea = 0;
	totalexparea = 0;

	for (j = 1;j < iterations;j++)
	{


		x = rand() % 1000;/* generate random number for x up to 1000 */
		y = rand() % 1000;/* generate random number for y up to 1000 */
		y = y / 1000;/* Divide by 1000 so our number is between 0 and 1 */
		x = x / 1000;/* Divide by 1000 so our number is between 0 and 1 */
		x = xlower + (xupper - xlower)*x;/* Adjust x value to be between required limits */
		y = yupper * y;/* Adjust y value to be between required limits */


		if (x >= xlower)
		{
			totalarea = totalarea + 1;/* add 1 to count of points within whole area */
			/* test if these coordinates are within the curve */

			if (pow(x, 2) + pow(y, 2) < 4)
			{

				totalexparea = totalexparea + 1;/* add 1 to count of points below the curve */

			}
		}


	}
	if (totalarea != 0)
	{
		montearea = area * (totalexparea / totalarea);/* calculate the area below the curve */
	}
	printf("monte area is %lf\n", montearea);








}