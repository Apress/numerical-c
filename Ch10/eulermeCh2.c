#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
float func(float x, float y);
int main()
{
	float F1;
	float x0, y0, x, y, h, xn;

	FILE *fptr;
	fptr = fopen("euler1.dat", "w");

	printf("Enter initial x, initial y, final x, increment ");
	scanf("%f %f %f %f", &x0, &y0, &xn, &h);
	x = x0;
	y = y0;

	for (x = x0;x < xn;x = x)
	{
		F1 = h * func(x, y);

		y = y + F1;
		x = x + h;
		fprintf(fptr, "%f\t%f\n", x, y);
		/*printf("X = %f Y = %f\n",x,y);*/
	}
	printf("X = %f Y = %f\n", x, y);

	fclose(fptr);
}
float func(float x, float y)
{
	float funcval;
	funcval = 2 * x;
	return funcval;
}