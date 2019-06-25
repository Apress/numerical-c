/*	Calculation of volume using monte carlo */
/*	by counting relative volumes */
/* integrates x^2 + y^2 * z to your specified limits */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main()
/* Montecarlo cylinder*/
{

	double x, y, z;
	double zupper, zlower, yupper, ylower, xupper, xlower;
	double  montevol,  volume;
	double totalexpvol, totalvol;
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


	printf("enter lower z limit\n");
	scanf("%lf", &zlower);
	printf("enter upper z limit\n");
	scanf("%lf", &zupper);
	printf("zlower %lf zupper %lf\n", zlower, zupper);


	volume = (xupper - xlower)*(yupper - ylower)*(zupper - zlower);
	printf("volume is %lf\n", volume);

	printf("enter iterations \n");
	scanf("%d", &iterations);

	totalvol = 0;
	totalexpvol = 0;


	for (j = 1;j < iterations;j++)
	{

		/* find random numbers for x,y ansd z */
		x = rand() % 1000;
		y = rand() % 1000;
		z = rand() % 1000;
		y = y / 1000;
		x = x / 1000;
		z = z / 1000;

		/* x,y and z will have numbers between 0 and 1 */
		/* so multiply by the user's entered ranges for x,y and z */
		x = xlower + (xupper - xlower)*x;
		y = ylower + (yupper - ylower)*y;
		z = zlower + (zupper - zlower)*z;



		if (x >= xlower && z >= zlower && y >= ylower)
		{
			totalvol = totalvol + 1; /* This contains the total number of entries */


			if ((pow(y, 2) + pow(x, 2)) < 4)
			{

				totalexpvol = totalexpvol + 1;/* This contains number of entries within desired vol */

			}
		}


	}
	if (totalvol != 0)
	{
		montevol = volume * (totalexpvol / totalvol);/* Monte Carlo volume os the fraction of the cube volume */
	}
	printf("monte carlo volume is %lf\n", montevol);








}