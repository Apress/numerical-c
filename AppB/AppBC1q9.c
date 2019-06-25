#define _CRT_SECURE_NO_WARNINGS
		
#include<stdio.h>

/* example of a 2D array test for 2 arrays*/	
int main()
{
	int arr1[8][8];
	int arr2[8][8];

	int i,j,k,l;

	printf("enter number of rows and columns of first array(max 8 rows max 8 columns) \n");
	scanf("%d %d", &k, &l);
	if(k>8 || l>8)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		printf("enter array\n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				scanf("%d",&arr1[i][j]);
			}
		}
		printf("Your array is \n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%d ",arr1[i][j]);
			}
		printf("\n");
		
		}
	}
	printf("first row of first array\n");
	for(j=0;j<k;j++)
	{
		printf("%d ",arr1[0][j]);
	}


	printf("enter number of rows and columns of second array(max 8 rows max 8 columns) \n");
	scanf("%d %d", &k, &l);
	if(k>8 || l>8)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		printf("enter array\n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				scanf("%d",&arr2[i][j]);
			}
		}
		printf("Your array is \n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%d ",arr2[i][j]);
			}
		printf("\n");
		
		}
	}
	printf("first row of second array\n");
	for(j=0;j<k;j++)
			{
				printf("%d ",arr2[0][j]);
			}

		printf("\n");
}
