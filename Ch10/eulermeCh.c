#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
float func(float x, float y);
int main()
{
	float F1;
	float x0, y0, x, y, h, xn;
	printf("Enter initial x, initial y, final x, increment ");
	scanf("%f %f %f %f", &x0, &y0, &xn, &h);
	x = x0;/* set initial value for loop */
	y = y0;/* set initial value for loop */

	for (x = x0;x < xn;x = x)
	{
		F1 = h * func(x, y); /*  h f'(x) from our Euler Formula */

		y = y + F1;/* y(n+1) = yn + h f'(x) from our Euler Formula */
		x = x + h; /* increment the x value for the next pass of loop */
		/*printf("X = %f Y = %f\n",x,y);*/
	}
	printf("X = %f Y = %f\n", x, y);


}
float func(float x, float y)
{
	float funcval;
	funcval = 2 * x;/* Function is dy/dx = 2x */
	return funcval;
}