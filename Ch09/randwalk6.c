/* simple random walk simulation in 1 dimension */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 


FILE *output;
time_t  t;				

main()
{
	int i;
	double xrand;
	
	double x,rms[20001];


	output= fopen ("randwalk6.dat", "w");	/* external file name */

	for (i=0; i<=20000; i++) 
		rms[i]=0.0;		/* clear array */


	srand((unsigned) time(&t));		/* set the number generator */



   	x=0.0;


   	for (i=1;i<=20000; i++)
      	{
		/* generate x random number */
		xrand=rand()%1000;
		xrand=xrand/1000;
		if(xrand<0.5)
			x=x+1.0;
		else
			x=x-1.0;

		
        	rms[i] = sqrt(x*x);/* store rms to total */ 
	
        	
	}
	/* Write values to file */
	for (i=0; i<=200; i++)
	{

		fprintf(output,"%d %lf\n", i, rms[i*100]);
	}

	fclose (output);
}
