/* augmat25 */	
/*	augmented matrix for up to 12 equations */
/*	calls functions for row division and row subtraction 	 */
/* catches incidences of zeros which would cause program to crash  */
/* preset array for augmented matrix */
/* Can use prest array or enter data manually */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct record
	{
		double matrix[12][13];
	};

	void funcdivide(int first,int second,int count);
	void funcsubtract(int first,int second,int count);
	double matrix[12][13];
	double divisor;
	int i,row,col,rw,cl;	

main()
{
	
	double value,x,y,z,a,b,c,d,e;
	double solution[12];
	double x1,x2,x3;
	int j,k,n,count;
	int pr;
	

	int counter;
	
	struct record data_record;
	




		double inmat[12][13]={
	{2.6,3.1,7.4,0.6,9.3,4.9,3.4,8.7,0.2,3.6,7.7,3.9,394.125},
	{4.9,9.3,0.6,7.4,3.1,2.6,0.3,6.3,5.1,4.9,9.1,0.6,360.703},
	{8.3,8.8,5.2,2.7,0.8,1.3,8.5,7.6,6.2,4.1,0.4,1.2,324.618},
	{1.3,0.4,2.3,5.8,8.1,6.3,6.3,5.1,9.2,6.6,1.3,2.3,414.999},
	{9.7,6.8,3.9,0.4,6.7,4.1,7.1,6.3,5.5,4.1,1.7,3.1,366.599},
	{7.3,5.8,6.1,2.7,9.2,1.8,4.2,5.2,7.1,3.7,2.9,2.6,364.771},
	{9.2,7.3,9.3,2.4,3.6,1.2,2.6,3.7,6.2,2.7,3.1,0.2,273.245},
	{8.6,8.4,8.7,6.8,3.9,4.3,3.8,4.6,5.3,6.5,2.6,0.5,359.206},
	{9.4,9.3,7.1,7.3,2.4,3.1,9.2,8.3,7.1,6.7,4.1,1.3,463.157},
	{7.2,6.8,7.6,3.5,3.1,2.5,3.9,7.6,8.3,8.5,5.2,2.1,445.064},
	{6.9,9.9,8.4,7.7,4.1,3.8,8.2,9.7,6.5,7.7,1.3,1.8,465.479},
	{5.9,8.1,6.8,4.6,1.6,2.2,7.9,6.4,8.5,5.9,0.6,1.6,377.258}
	};

	printf("enter 1 or 2 (1=use preset matrix, 2=enter matrix manually))");
		scanf("%d",&pr);
	if(pr == 2)
	{
		/* Enter data manually */
 

		printf("enter row/column number (square matrix only up to 12 rows)");
		scanf("%d",&n);
	
		printf("square matrix is %d",n);
	
		row=n;
		col=n+1;
		for(j=0;j<n;j++)
		{
			printf("row %d ",j);
			for(i=0;i<n+1;i++)
			{
				printf("enter x\n");
				scanf("%lf",&value);	
				matrix[j][i] = value;		
			}
		}


	}else
	{
		/* Use preset array */

		n=12;/* set matrix to 12x12 */


		/* Copy preset array to output array */

		for(i=0;i<12;i++)
		{
			for(j=0;j<13;j++)
			{
				matrix[i][j]=inmat[i][j];
			}

		}


	}

	/* Print matrix  */

	for(i=0;i<12;i++)
	{
		for(j=0;j<13;j++)
		{
			
			printf("matrix[%d][%d] = %lf \n",i,j,matrix[i][j]);
		}

	
	}




	row=n; /* row count */
	col=n+1; /* column count */


	
	
/* Call functions. One to divide a row by an element of that row */
/* Tne other to subtract one row from another */
	
	count=0;
	for(i=0;i<col;i++)
	{
		for(k=i;k<row;k++)
		{
			count=count+1;
			funcdivide(k,i,count);
		}
		for(j=i+1;j<row;j++)
		{
			count=count+1;
			funcsubtract(j,i,count);
		}
	}


	/* Calculate solutions from reduced augmented matrix */
	
	rw=n-1;
	cl=n;		
	solution[rw]=matrix[rw][cl];

	for(i=1;i<=cl;i++)
	{
		solution[rw-i]=matrix[rw-i][cl];	
		j=rw;
		for(k=0;k<=i;k++)
		{
			solution[rw-i]=solution[rw-i]-matrix[rw-i][rw-i+1+k]*solution[rw-i+1+k];	
			j=j-1;
		}	
	}
	printf("solution\n");	
	for(i=0;i<=rw;i++)
	{
		printf("\n x%d = %lf",i+1, solution[i]);	
	}
}

/* Function to perform division on a row */
				
void funcdivide(int first,int second,int count)
{

	int i,j;
	double swopmatrix[12][13];
	
	a1:divisor=matrix[first][second];


if(divisor == 0.0 && first != row-1)	/* check for divisor of zero (don't try to swop if last row) */
	{
		/* zero divisor so swop this row with the one below */
		for(i=0;i<col;i++)
		{

			swopmatrix[0][i]=matrix[first][i];
		}
		for(i=0;i<col;i++)
		{

			matrix[first][i]=matrix[first+1][i];
		}
		for(i=0;i<col;i++)
		{

			matrix[first+1][i]=swopmatrix[0][i];
		}


		printf("augmented matrix after swop  operation is\n");
		for(j=0;j<row;j++)
		{
			if(row == 3)
				printf("%lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3]);
			else if(row == 4)
			
				printf("%lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4]);
				else
					printf("%lf %lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4],matrix[j][5]);	
		}	
	
	divisor=matrix[first][second];
	goto a1; /* check if the next element is a zero divisor */
	}

	if(divisor == 0.0 && first == row-1)
	{
		/* Check if last row with zero divisor */
		printf("ignore zero divisor\n");
	}else
		for(i=second;i<col;i++)
		{
			matrix[first][i]=matrix[first][i]/divisor;
		}



	
/* The next few lines are commented out. You can use them to display your matrix at each stage for testing */
/* The number of terms in printf will vary with the size of the matrix */
/*
	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<row;j++)
	{
		
		printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4],matrix[j][5],matrix[j][6],matrix[j][7],matrix[j][8],matrix[j][9],matrix[j][10],matrix[j][11],matrix[j][12]);
	}
*/
}
	

/* Function to perform subtraction of one row from another */	
 
void funcsubtract(int first,int second,int count)
{

	int i;	
	
	
	for(i=0;i<col;i++)
	{
		matrix[first][i]=(matrix[first][i])-matrix[second][i];
	}

/* The next few lines are commented out. You can use them to display your matrix at each stage for testing */
/* The number of terms in printf will vary with the size of the matrix */
/*
	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<row;j++)
	{
		
		printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4],matrix[j][5],matrix[j][6],matrix[j][7],matrix[j][8],matrix[j][9],matrix[j][10],matrix[j][11],matrix[j][12]);
	}
*/
}	

