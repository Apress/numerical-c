#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* program to show character array use */
	
int main()

{
	char arr2[10];
	int i;



	printf("enter 10 characters \n");

	for(i=0;i<10;i++)
	{
		scanf("%c",&arr2[i]);
	}
	printf("Your 10 characters are \n");

	for(i=0;i<10;i++)
	{
		printf("%c ",arr2[i]);
	}
	printf("\n");




}
