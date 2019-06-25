/* augmat17A */	
/*	augmented matrix 3x4 */
/*	complete program	 */
/*  */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
	void funcdivide(int first,int second,int count);
	void funcsubtract(int first,int second,int count);
	double matrix[12][13];
	double divisor;
	int i;	

main()
{
	
	double element,x,y,z;
	int i,j,n;
	
	

	
	n = 3; /* Only 3x3 matrix for this program */
	
	printf("square matrix is %d",n);
	
	printf("Enter data for augmented matrix \n");
	
	for(j=0;j<n;j++)
	{
		printf("row %d ",j);
		for(i=0;i<n+1;i++)
		{
			printf("enter x\n");
			scanf("%lf",&element);	
			matrix[j][i] = element;		
		}
	}
	printf("augmented matrix is\n");
	for(j=0;j<n;j++)
	{
		
		for(i=0;i<n+1;i++)
		{
			printf("matrix[%d][%d] = %lf\n",j,i,matrix[j][i]);
					
		}
	}

/*	Perform 9 stages to find row-reduced form of augmented matrix.*/
/*	divide stages are done in funcdivide */
/*	subtract stages are done in funcsubtract */


	funcdivide(0,0,1);	/* stage 1 – divide row 0 by divisor row 0 col 0 */
	funcdivide(1,0,2);	/* stage 2 – divide row 1 by divisor row 1 col 0 */
	funcdivide(2,0,3);	/* stage 3 – divide row 2 by divisor row 2 col 0 */
	funcsubtract(1,0,4);	/* stage 4 – subtract row 0 from row 1 */
	funcsubtract(2,0,5);	/* stage 5 – subtract row 0 from row 2 */
	funcdivide(1,1,6);	/* stage 6 – divide row 1 by divisor row 1 col 1 */
	funcdivide(2,1,7);	/* stage 7 – divide row 2 by divisor row 2 col 1 */
	funcsubtract(2,1,8);	/* stage 8 – subtract row 1 from row 2 */
	funcdivide(2,2,9);	/* stage 9 – divide row 2 by divisor row 2 col 2 */


	/* Calculate and print out the answers */

	z=matrix[2][3];
	y=matrix[1][3]-z*matrix[1][2];
	x=matrix[0][3]-y*matrix[0][1]-z*matrix[0][2];

	printf("x = %f y= %f z = %f",x,y,z);

		
			
}

			
void funcdivide(int first,int second,int count)
{
		/* divide each element in row "first" by element [first][second] */
	int i,j;
	
	divisor=matrix[first][second];
	for(i=0;i<4;i++)
	{
		matrix[first][i]=matrix[first][i]/divisor;
	}
	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<3;j++)
	{
		printf("%lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3]);
	}
}	
	 
void funcsubtract(int first,int second,int count)
{
		/* subtract row "second" from row "first" */
	int i,j;	
	
	
	for(i=0;i<4;i++)
	{
		matrix[first][i]=(matrix[first][i])-matrix[second][i];
	}
	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<3;j++)
	{
		printf("%lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3]);
	}
}	

