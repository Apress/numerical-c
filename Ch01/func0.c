#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* This code demonstrates what a function does */
/* The function here compares two numbers and says which is bigger */
/* The user enters three numbers and gets told which is bigger than which !*/
	void myfunction(int a,int b); /* decaration of your function and its parameters */
	int first , second, third;
	
main()
{
	printf( "Please enter first integer number: " );
    	scanf( "%d", &first );
	 printf( "Please enter second integer number: " );
    	scanf( "%d", &second );
	 printf( "Please enter third integer number: " );
    	scanf( "%d", &third );
	 
	myfunction(first , second);
	myfunction(first , third);
	myfunction(second , third);
}
void myfunction(int a,int b)
/* the function is outside the main{} part of the program */
/* The function just compares the two parameters, a and b, and says which is greater*/
{
	
	if(a>b)
		printf("%d is greater than %d\n", a,b);
	else if (a<b)
		printf("%d is greater than %d\n", b,a);
	else
		printf("%d and %d are equal\n", a,b);
}	

