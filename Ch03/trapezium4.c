/*trapezium - trapezium method showing problem with negative areas */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{

	double lowerx, upperx;
	double PI;

	double stripwidth, xposn;
	double middlevalues, zero, width, area;
	double yarr[10002];
	int i, strips;

	double lowangle, uppangle, lowradianno, uppradianno;

	/* Preset constant values */

	PI = 3.141592654;
	zero = 0;
	printf("Please enter lower angle in degrees:\n ");
	scanf("%lf", &lowangle);
	printf("You entered %f\n", lowangle);

	lowradianno = lowangle * (2 * PI / 360);

	printf("Please enter upper angle in degrees:\n ");
	scanf("%lf", &uppangle);
	printf("You entered %lf\n", uppangle);
	uppradianno = uppangle * (2 * PI / 360);

	printf("enter number of strips");
	scanf("%d", &strips);

	if (strips > 10000)
	{
		printf("Number of strips exceeds 10000");
		return(0);
	}
	width = uppradianno - lowradianno;
	stripwidth = width / strips;

	lowerx = sin(lowradianno);
	yarr[1] = lowerx;
	upperx = sin(uppradianno);
	yarr[strips + 1] = upperx;

	middlevalues = zero;

	for (i = 1;i < strips;i++)
	{
		xposn = sin(lowradianno + (i*stripwidth));

		yarr[i + 1] = xposn;

		middlevalues = middlevalues + yarr[i + 1];
	}

area = 0.5*stripwidth*(yarr[1] + 2 * middlevalues + yarr[strips + 1]);

	printf("Area is %lf\n", area);

}
