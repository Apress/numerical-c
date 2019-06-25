/* Function which returns an answer  */
/* finds the pupil in one year of the school with the highest marks */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double getmarks(double pupils[]);

int main()
{
	double pupil;
	/* Array with marks for class is preset in the main part of the program */
	double  marks[] = {1.2,2.3,3.4,4.5,5.6,6.7,7.8,8.9,9.0};
	/* Call function getmarks. The function returns the average marks which is then stored in pupil */
	pupil = getmarks(marks); 
	printf("Avarage mark is  = %lf", pupil);
	return 0;
}

double getmarks(double pupils[])
{
	int i;
	double average, total;
	total = 0;
	/* Go through all the pupils in turn and add their mark */
	for (i = 0; i < 9; ++i)
	{
		total = total + pupils[i];
		
	}
	average = total/9;
	return average; /* returns the value in average to where the function was called */
}
