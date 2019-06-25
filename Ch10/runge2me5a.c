/* Second Order Differential Equation */
/* Solves d2y/dx2  = dy/dx - 6x^2 + 12x */
/* Splits the second order DE into two first order DEs */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double y1a,y2;

double func1(double x,double y);
double func2(double x,double y);

int main()

{
 	double D1F1,D1F2,D1F3,D1F4; 
	double D2F1,D2F2,D2F3,D2F4;  
	double x0,x,h,xn;

	FILE *fptr1;


    	printf("Enter initial x, initial y1,initial y2 ,final x, increment ");
    	scanf("%lf %lf %lf %lf %lf",&x0,&y1a,&y2,&xn,&h);
    	x=x0;
    	    

	fptr1=fopen("rk25.dat","w");

	for(x=x0;x<xn;x=x)
	{
		/* Derivative for 1st first order DE */

		D1F1=h*func1(x,y1a);
		D1F2=h*func1(x+h/2.0,y1a+D1F1/2.0);
		D1F3=h*func1(x+h/2.0,y1a+D1F2/2.0);
		D1F4=h*func1(x+h,y1a+D1F3);
		y1a=y1a+(D1F1+2*D1F2+2*D1F3+D1F4)/6.0;

		/* Derivative for 2nd first order DE */

		D2F1=h*func2(x,y2);
		D2F2=h*func2(x+h/2.0,y2+D2F1/2.0);
		D2F3=h*func2(x+h/2.0,y2+D2F2/2.0);
		D2F4=h*func2(x+h,y2+D2F3);
		y2=y2+(D2F1+2*D2F2+2*D2F3+D2F4)/6.0;


		x=x+h;
		/*printf("X = %f Y = %f\n",x,y);*/
		fprintf(fptr1,"%f\t%f\n",x,y1a);
	}


	printf("X = %lf Y = %lf\n",x,y1a);
	fclose(fptr1);

   
}
double func1(double x,double y)
{
	/* First order differential equation no. 1 */
   	double funcval;
	funcval=y2;

    	return funcval;
}
double func2(double x,double y)
{
	/* First order differential equation no. 2 */
    	double funcval;
  
	funcval=y2-6*pow(x,2)+12*x;

   	return funcval;
}