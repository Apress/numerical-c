/* Matrix program */
/* multiply two matrices */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	
int main()

{
	#define MAXROW  8
	#define MAXCOL  8
	int matarr1[MAXROW][MAXCOL];/* First matrix store (rowxcolumn)*/
	int matarr2[MAXROW][MAXCOL];/* Second matrix store (rowxcolumn)*/
	int matmult[MAXROW][MAXCOL];/* matrix answer (rowxcolumn)*/

	int i,j,k;
	int r1,c1,r2,c2;/* row and col for 1st and 2nd matrices */
	int error;

	error=0;

	printf("enter order of the first matrix (max 8 rows max 8 columns) \n");
	scanf("%d %d", &r1, &c1);

	/* Check if user is trying to enter too many rows or columns */
	/* or the number of columns in their 1st matrix is not the same as */
	/* the number of rows in their 2nd matrix */

	if(r1>MAXROW || c1>MAXCOL)
	{
		printf("error - max for rows or columns exceeded\n");
		error=1;

	}
	if(error == 0)
	{
		printf("enter order of the second matrix (max %d rows max %d columns) \n",MAXROW,MAXCOL);
		scanf("%d %d", &r2, &c2);
		if(r2>MAXROW || c2>MAXCOL)
		{
			printf("error - max for rows or columns exceeded\n");
			error=1;

		}
		else
		if(c1 != r2)
		{
			printf("error - number of columns in 1st matrix must equal number of rows in 2nd\n");
			error=1;
			
		}
		
			
	}
	if(error == 0)

	{
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				matmult[i][j]=0;/* clear the matrix */
			}
		}

		/* Read in first matrix */

		printf("enter first matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&matarr1[i][j]);
			}
		}
		printf("Your first matrix is \n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d ",matarr1[i][j]);/* first matrix in matarr1 */
			}
			printf("\n");
		}

		/* Read in second matrix */	

		printf("enter second matrix\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%d",&matarr2[i][j]);
			}
		}
		printf("Your second matrix is \n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d ",matarr2[i][j]);/* second matrix in matarr2 */
			}
			printf("\n");
		}

		/* multiply corresponding elements of the matrices into matmult */

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

		/* Write the solution */	

		printf("Your matrix multiplication is \n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d ",matmult[i][j]);
			}
			printf("\n");

		}
	}

		
}