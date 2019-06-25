/* Montecarlo circle (whole circle in 1st quadrant)*/
/*	Calculation of volume using monte carlo */
/*	by counting relative volumes */
/* integrates (x-2)^2 + (y-2)^2 = 2^2 to your specified limits (radius fixed at 2 - centre at (2,2)) */
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



	printf("enter lower x limit\n");
	scanf("%lf", &xlower);
	printf("enter upper x limit\n");
	scanf("%lf", &xupper);
	printf("xlower %lf xupper %lf\n", xlower, xupper);


	printf("enter lower y limit\n");
	scanf("%lf", &ylower);
	printf("enter upper y limit\n");
	scanf("%lf", &yupper);
	printf("ylower %lf yupper %lf\n", ylower, yupper);



	area = (xupper - xlower)*(yupper - ylower);
	printf("overall area is %lf\n", area);

	printf("enter iterations \n");
	scanf("%d", &iterations);

	totalarea = 0;
	totalexparea = 0;


	for (j = 1;j < iterations;j++)
	{

		/* find random numbers for x,y ansd z */
		x = rand() % 1000;
		y = rand() % 1000;

		y = y / 1000;
		x = x / 1000;


		/* x,y  will have numbers between 0 and 1 */
		/* so multiply by the user's entered ranges for x,y  */
		x = xlower + (xupper - xlower)*x;
		y = ylower + (yupper - ylower)*y;




		if (x >= xlower && y >= ylower)
		{
			totalarea = totalarea + 1; /* This contains the total number of entries */


			if ((pow((y - 2), 2) + pow((x - 2), 2)) < 4)
			{

				totalexparea = totalexparea + 1;/* This contains number of entries within desired area */

			}
		}


	}
	if (totalarea != 0)
	{
		montearea = area * (totalexparea / totalarea);/* Monte Carlo area os the fraction of the outer area */
	}
	printf("monte carlo area is %lf\n", montearea);








}