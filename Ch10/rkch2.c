#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double func(double x, double y);
int main()
{
	double F1, F2, F3, F4;
	double x0, y0, x, y, h, xn;

	FILE *fptr;
	fptr = fopen("runge1.dat", "w");/* ! FILE NAME ! */

	printf("Enter initial x, initial y, final x, increment ");
	scanf("%lf %lf %lf %lf", &x0, &y0, &xn, &h);
	x = x0;
	y = y0;

/* forloop contains Runge-Kutta function */

	for (x = x0;x < xn;x = x)
	{
		F1 = h * func(x, y);
		F2 = h * func(x + h / 2.0, y + F1 / 2.0);
		F3 = h * func(x + h / 2.0, y + F2 / 2.0);
		F4 = h * func(x + h, y + F3);
		y = y + (F1 + 2 * F2 + 2 * F3 + F4) / 6.0;
		x = x + h;
		fprintf(fptr, "%lf\t%lf\n", x, y);

		/*printf("X = %lf Y = %lf\n",x,y);*/
	}
	printf("X = %lf Y = %lf\n", x, y);

	fclose(fptr);
}
double func(double x, double y)
{
	double funcval;
	funcval = 3*pow(x,2); /* function is dy/dx =3 x2 */
	return funcval;
}
