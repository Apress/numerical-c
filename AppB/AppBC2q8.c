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

		/* sets testvalue to 2*(middle)2 -2/(middle)2 */
		testvalue=2*pow(middle,2)-2*pow(middle,-2);
		
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
