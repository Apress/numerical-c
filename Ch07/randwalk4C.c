/* simple random walk simulation */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 


FILE *output;
time_t  t;				

main()
{
	int i;
	float xrand,yrand;
	double x, y, rms[10000];



	output= fopen ("randwalk4.dat", "w");	/* external file name */

	for (i=0; i<=10000; i++) 
		rms[i]=0.0;		/* clear array */


	srand((unsigned) time(&t));		/* set the number generator */



   	x=0.0; y=0.0;

   	for (i=1;i<=10000; i++)
      	{
		/* generate x random number */
		xrand=rand()%1000;
		xrand=xrand/1000;
		if(xrand<0.5)
			x=x+1.0;
		else
			x=x-1.0;

		/* generate y random number */
		yrand=rand()%1000;
		yrand=yrand/1000;
		if(yrand<0.5)
			y=y+1.0;
		else
			y=y-1.0;
        
          
         	rms[i] = sqrt(x*x+y*y);/* store rms to total */
  
	
        	
	}
	/* Write values to file */
	for (i=0; i<=100; i++)
	{

		fprintf(output,"%d %lf\n", i, rms[i*100]);
	}

	fclose (output);
}
