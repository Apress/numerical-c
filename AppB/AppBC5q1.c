/* Matrix program */
/* Add two floating point matrices */
	#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

	
main()

{
	float matarr1[8][8];/* First matrix store (rowxcolumn)*/
	float matarr2[8][8];/* Second matrix store (rowxcolumn)*/
	float matsum[8][8];/* Sum of matrices store (rowxcolumn)*/
	int i,j,k,l;

	printf("enter order of the two matrices (max 8 rows max 8 columns) \n");
	scanf("%d %d", &k, &l);
	if(k>8 || l>8)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		printf("enter first matrix\n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				scanf("%f",&matarr1[i][j]);
			}
		}
		printf("Your first matrix is \n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%f ",matarr1[i][j]);/* first matrix in matarr1 */
			}
			printf("\n");
		}
		printf("enter second matrix\n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				scanf("%f",&matarr2[i][j]);
			}
		}
		printf("Your second matrix is \n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%f ",matarr2[i][j]);/* second matrix in matarr2 */
			}
			printf("\n");
		}
		/* add correspoding elements of the matrices into matsum */
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				matsum[i][j] = matarr1[i][j] + matarr2[i][j];
			}
		}

		printf("Your matrix sum is \n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%f ",matsum[i][j]);/* sum of matrices in matsum */
			}
			printf("\n");

		}
	}

		
}
