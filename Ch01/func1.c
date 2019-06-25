#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/* example of a function*/	
void printarow(int row,int cols, int arr[8][8]);
int main()

{
	int arr1[8][8];


	int i,j,rows,cols;
	

	printf("enter number of rows and columns (max 8 rows max 8 columns) \n");
	scanf("%d %d", &rows, &cols);
	if(rows>8 || cols>8)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		printf("enter array\n");
		for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
			{
				scanf("%d",&arr1[i][j]);
			}
		}
		printf("Your array is \n");
		for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
			{
				printf("%d ",arr1[i][j]);
			}
		printf("\n");
		
		}
	}
	
	
	printarow(2,cols,arr1);/* This calls to print out row 2 only(assumes that you have at least 2 rows) */
	printf("\n");
	printarow(1,cols,arr1);/* This calls to print out row 1 only */
	printf("\n");
}
void	printarow(int row,int cols,int arr[8][8])
	/* this is a function which can be called from anywhere in the program */
	/* and can be called as often as you want to */
	/* If you need to do the same type of thing many times it saves you */
	/* having to write out the same code repeatedly. All you need to */
	/* is call the function */

	{

		int j;
		printf("row %d is ",row);
		for(j=0;j<cols;j++)
		{
			printf("%d ",arr[row-1][j]);
		}
		
	}
		
	
