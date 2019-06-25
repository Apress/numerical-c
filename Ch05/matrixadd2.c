/* Matrix program */
/* Add two matrices */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	
main()

{
	#define MAXROW  8
	#define MAXCOL  8
	int matarr1[MAXROW][MAXCOL];/* First matrix store (rowxcolumn)*/
	int matarr2[MAXROW][MAXCOL];/* Second matrix store (rowxcolumn)*/
	int matsum[MAXROW][MAXCOL];/* Sum of matrices store (rowxcolumn)*/
	int i,j,numrows,numcols;

	printf("enter order of the two matrices (max 8 rows max 8 columns) \n");
	scanf("%d %d", &numrows, &numcols);

	/* Check if user is trying to enter too many rows or columns */

	if(numrows>MAXROW || numcols>MAXCOL)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{

		/* Read in first matrix */

		printf("enter first matrix\n");
		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				scanf("%d",&matarr1[i][j]);
			}
		}
		printf("Your first matrix is \n");
		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				printf("%d ",matarr1[i][j]);/* first matrix in matarr1 */
			}
			printf("\n");
		}

		/* Read in second matrix */

		printf("enter second matrix\n");
		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				scanf("%d",&matarr2[i][j]);
			}
		}
		printf("Your second matrix is \n");
		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				printf("%d ",matarr2[i][j]);/* second matrix in matarr2 */
			}
			printf("\n");
		}

		/* add corresponding elements of the matrices into matsum */

		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				matsum[i][j] = matarr1[i][j] + matarr2[i][j];
			}
		}

		/* Write the solution */

		printf("Your matrix sum is \n");
		for(i=0;i<numrows;i++)
		{
			for(j=0;j<numcols;j++)
			{
				printf("%d ",matsum[i][j]);/* sum of matrices in matsum */
			}
			printf("\n");

		}
	}

		
}