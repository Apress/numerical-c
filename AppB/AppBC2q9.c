/*trapezium -  trial and improvement using inverse functions */ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
main()
{
	float lower,upper;
	 
	int i;
	double testhigh,testlow,testvalue,middle;
	 
	int iterations;
	
	printf("enter lower limit");/* the lower x value for your integration */
	scanf("%f",&lower);
	printf("enter upper limit");/* the upper x value for your integration */
	scanf("%f",&upper);
	printf("enter number of iterations");
	scanf("%d",&iterations);

	testlow=lower;
	testhigh=upper;
	
	for(i=0;i<iterations;i++)
	{	
		middle=(testhigh+testlow)/2;

		/* sets testvalue to 0.75/(middle)2 -0.8*(middle)3 */
		testvalue=0.75*pow(middle,-2)-0.8*pow(middle,3);
	
		if(testvalue == 0)
		{
			printf("x is %f",middle);
			return(0);
		}
		if(testvalue > 0)
		{
			testhigh=middle;
		}
		else
		{
			testlow=middle;
		}

	}
	printf("x is %f",middle);
	
	
}
