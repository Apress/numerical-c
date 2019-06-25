/* radioactive decay simulation */	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
main()
{
	
	int j,timelimit,nuc;

	double randnumber,timeinc,lambda,timecount,probunittime;
	FILE *fptr;
	time_t  t;	
	srand((unsigned) time(&t)); /* random number generator seed */
	fptr=fopen("radioact.dat","w");


	/* Ask user to input specific data */
	/* initial number of nuclei, the value of lambda, time for experiment */

	printf("Enter initial number of nuclei : ");
	scanf("%d",&nuc);

	printf("Enter lambda : ");
	scanf("%lf",&lambda);

	printf("Enter time  : ");
	scanf("%d",&timelimit);

	/* time increment of loop */

	timeinc=0.001/lambda;

	printf("Time increment :%lf",timeinc);

	/* (delta t * lambda) */

	probunittime=0.001*lambda;
	timecount=0;

	/* Monte Carlo loop */
	while(timecount<=timelimit)
	{


		fprintf(fptr,"%lf %d\n",timecount,nuc);

		timecount=timecount+timeinc;

		for(j=0;j<=nuc;j++)
		{
			randnumber=rand()%1000;
			randnumber=randnumber/1000;

		/* Monte Carlo method checks random number less than (delta t * lambda) */

			if(randnumber<=probunittime)
				nuc=nuc-1;/* If less, then prob. that nucleus has decayed */
		
			if(nuc<=0)
				goto nuclimitreached;


		}
	}
nuclimitreached:	fclose(fptr); /* nuclei limit or time limit reached */ 

}
