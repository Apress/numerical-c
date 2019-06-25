/* Buffon's Needle Simulation (Monte Carlo)*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


#define PI 3.141592654


main()
{

	time_t  t;



	int i, throws, count;
	double randno,anglerand;


	srand((unsigned) time(&t));/* set the random number seed */
	printf("Enter number of throws ");
	scanf("%d",&throws);
		
	count=0;

	for(i=1; i<=throws; i++) 
	{

		randno=rand()%1000;
		randno=randno/1000;/* randno is the random number */
		anglerand=rand()%1000;
		anglerand=anglerand/1000;

		anglerand=0.5*PI*anglerand; /* anglerand is the angle random number*/
		

		if(randno <= sin(anglerand)) 
			count=count+1; /* Add to count */
		
	
	}
	
	printf("PI is %lf \n",2*(double)i/(double)count);
}
