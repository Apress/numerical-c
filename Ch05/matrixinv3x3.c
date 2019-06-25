/* Matrix program */
/* invert a 3x3 matrix */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	
int main()

{
	
	double matarr1[3][3];/*  matrix store (rowxcolumn)*/
	double mattrans[3][3];/* adjugate matrix store (rowxcolumn)*/
	double matinv[3][3];/* matrix answer (rowxcolumn)*/ 

	/* array to hold the positions of the minors for each of the 9 points in the matrix */

	int posarr[78]={1,1,2,2,1,2,2,1,	/* row 0 col 0 */
			1,0,2,2,1,2,2,0,	/* row 0 col 1 */
			1,0,2,1,1,1,2,0,	/* row 0 col 2 */
			0,1,2,2,0,2,2,1,	/* row 1 col 0 */
			0,0,2,2,0,2,2,0,	/* row 1 col 1 */
			0,0,2,1,0,1,2,0,	/* row 1 col 2 */
			0,1,1,2,0,2,1,1,	/* row 2 col 0 */
			0,0,1,2,0,2,1,0,	/* row 2 col 1 */
			0,0,1,1,0,1,1,0};	/* row 2 col 2 */

	double det[9];/* array to contain matrix of minors row1col1,row1col2,row1col3,row2col1 etc */
	double detant;	/* The determinant (any row or col of the original matrix X corresponding one in cofactors) */
																																																
	int i,j,x;
	int r1,c1;
	

	
	r1=3;
	c1=3;


	
	printf("enter matrix\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%lf",&matarr1[i][j]);
		}
	}
	printf("Your matrix is \n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%lf ",matarr1[i][j]);/* first matrix in matarr1 */
		}
			printf("\n");
	}


	/* invert */

/* Stage 1- Matrix of minors */

	for(j=0;j<9;j++)
	{
		x = j*8;
		for(i=0;i<8;i++)
		{
			det[j]=matarr1[posarr[x]][posarr[x+1]]*matarr1[posarr[x+2]][posarr[x+3]]-matarr1[posarr[x+4]][posarr[x+5]]*matarr1[posarr[x+6]][posarr[x+7]];
			
		}
	}

	printf("Your matrix of minors is \n");
	for(j=0;j<3;j++)
	{
	
		for(i=0;i<3;i++)
		{
			printf("%lf ",det[i+3*j]);
		}
		printf("\n");

	}

/* Stage 2 - Matrix of cofactors */

	printf("Your matrix of cofactors is \n");

		
	det[1]=det[1]*-1;
	det[3]=det[3]*-1;
	det[5]=det[5]*-1;
	det[7]=det[7]*-1;
				
			
			

		
	for(j=0;j<3;j++)
	{
		
		for(i=0;i<3;i++)
		{
			printf("%lf ",det[i+3*j]);
		}
		printf("\n");

	}

/* Stage 3 - Determinant */

	/* We can multiply any row or column of the original matrix by */
	/* the corresponding row or column of the matrix of cofactors. */
	/* Here we just take the first row */

	detant=matarr1[0][0]*det[0]+matarr1[0][1]*det[1]+matarr1[0][2]*det[2];
	printf("determinant is %lf ",detant);

/* Stage 4- Adjugate (or transpose) */

	/* Transpose the cofactor matrix about its diagonal */

	printf("Your matrix transpose is  \n");
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			mattrans[i][j]=det[i+3*j];
				
		}
		printf("\n");
	}
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
				
			printf("%lf ",mattrans[j][i]);

		}
		printf("\n");
	}

/* Stage 5- Multiply inverse of determinant by adjugate */

	/* Multiply the result of Stage 4 by the result of Stage 3 */

	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			matinv[j][i]=mattrans[j][i]*(1/detant);
				
		}
		printf("\n");
	}

/* Print solution */

	for(j=0;j<3;j++)
	{ 
		for(i=0;i<3;i++)
		{
				
			printf("%lf ",matinv[j][i]);

		}
		printf("\n");
	}


		
}