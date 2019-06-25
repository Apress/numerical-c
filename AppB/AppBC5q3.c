/* Matrix program */
/* multiply two floating point matrices */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	
	int main()

	{
	float matarr1[8][8];/* First matrix store (rowxcolumn)*/
	float matarr2[8][8];/* second matrix store (rowxcolumn)*/
	float matmult[8][8];/* matrix answer (rowxcolumn)*/ 
	int i,j,k;
	int r1,c1,r2,c2;
	int error;

	error=0;

	printf("enter order of the first matrix (max 8 rows max 8 columns) \n");
	scanf("%d %d", &r1, &c1);
	if(r1>8 || c1>8)
	{
		printf("error - max of 8 for rows or columns\n");
		error=1;

	}
	printf("enter order of the second matrix (max 8 rows max 8 columns) \n");
	scanf("%d %d", &r2, &c2);
	if(r2>8 || c2>8)
	{
		printf("error - max of 8 for rows or columns\n");
		error=1;

	}
	if(error == 0)

	{
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				matmult[i][j]=0;
			}
		}
		printf("enter first matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%f",&matarr1[i][j]);
			}
		}
		printf("Your first matrix is \n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%f ",matarr1[i][j]);/* first matrix in matarr1 */
			}
			printf("\n");
		}
		printf("enter second matrix\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%f",&matarr2[i][j]);
			}
		}
		printf("Your second matrix is \n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%f ",matarr2[i][j]);/* second matrix in matarr2 */
			}
			printf("\n");
		}
		/* multiply correspoding elements of the matrices into matmult */
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				for(k=0;k<r2;k++)
				{
					matmult[i][j] = matmult[i][j] + matarr1[i][k] * matarr2[k][j];
				}
			}
		}

		printf("Your matrix multiplication is \n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%f ",matmult[i][j]);
			}
			printf("\n");

		}
	}

		
}
