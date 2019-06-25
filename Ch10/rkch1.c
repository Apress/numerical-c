#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double func(double x, double y);

int main()
{
	double F1, F2, F3, F4;
	double x0, y0, x, y, h, xn;

	printf("Enter initial x, initial y, final x, increment ");
	scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);

	x = x0;
	y = y0;

/* forloop contains Runge-Kutta function */

	for (x = x0;x < xn;x = x)
	{
	/* Set the values of F1,F2,F3 and F4 from the formula */
		F1 = h * func(x, y);
		F2 = h * func(x + h / 2.0, y + F1 / 2.0);
		F3 = h * func(x + h / 2.0, y + F2 / 2.0);
		F4 = h * func(x + h, y + F3);

		/* Increment our y value using the formula*/
		y = y + (F1 + 2 * F2 + 2 * F3 + F4) / 6.0;

		/* Increment the x-value by our chosen entered value */
		x = x + h; 

		/* Use the following lone of code (currently commented out) */
		/* If you want to monitor the progress of the forloop */
		/*printf("X = %lf Y = %lf\n",x,y);*/


	}
	printf("X = %lf Y = %lf\n", x, y);


}
double func(double x, double y)
{
	double funcval;
	funcval = 3*pow(x,2); /* function is dy/dx = 3x2 */
	return funcval; 
}
