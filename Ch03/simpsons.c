/*simpsons - to integrate sqrt(4+x^2)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{

	double lower, upper;

	double stripwidth, xposn;
	double mideven, midodd, width, area;
	double yarr[10002];
	int i, strips;

	/* prompt and read in limits and number of strips */


	printf("enter lower limit");
	scanf("%lf", &lower);
	printf("enter upper limit");
	scanf("%lf", &upper);
	printf("enter number of strips");
	scanf("%d", &strips);

	if (strips > 10000)
	{
		printf("Number of strips exceeds 10000");
		return(0);
	}

	width = upper - lower;
	stripwidth = width / strips;
	yarr[0] = sqrt(4 + pow(lower, 2));	/* First ordinate */
	yarr[strips] = sqrt(4 + pow(upper, 2));	/* Last ordinate */

	mideven = 0;
	midodd = 0;

	/* Process odd-numbered strips */
	for (i = 1;i < strips;i++)
	{

		xposn = lower + (i*stripwidth);
		yarr[i] = sqrt(4 + pow(xposn, 2));
		midodd = midodd + yarr[i];
		i++;

	}
	/* Process even-numbered strips */
	for (i = 2;i < strips;i++)
	{

		xposn = lower + (i*stripwidth);
		yarr[i] = sqrt(4 + pow(xposn, 2));
		mideven = mideven + yarr[i];
		i++;

	}

	/* Process Simpson's formula */
	area = (0.3333)*stripwidth*((yarr[0] + yarr[strips]) + 4 * midodd + 2 * mideven);

	printf("Area is %lf\n", area);

}

