/* augmat18 */	
/*	augmented matrix for 3,4 or 5 equations */
/*	calls functions for row division and row subtraction */
/* catches incidences of zeros which would cause program to crash (3x3 ,4x4 and 5x5) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

	void funcdivide(int first,int second,int count);
	void funcsubtract(int first,int second,int count);
	double matrix[12][13];
	double divisor;

	int i,row,col;	


main()
{
	
	double value,x,y,z,a,b,c,d,e;
	
	double solution[12];
	
	int i,j,k,m,n,count;
	
	/* Enter data for augmented matrix - one element at a time*/

	printf("enter row/column number (square matrix 3x3 4x4 5x5 only)");
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

	/* Print entered matrix */

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

	/* Print out answers depending on number of equations */
 
	if(n == 3)
	{
		z=matrix[2][3];
		y=matrix[1][3]-z*matrix[1][2];
		x=matrix[0][3]-y*matrix[0][1]-z*matrix[0][2];
		printf("x = %f y= %f z = %f",x,y,z);
	}
	if(n == 4)
	{
		d=matrix[3][4];
		c=matrix[2][4]-d*matrix[2][3];
		b=matrix[1][4]-c*matrix[1][2]-d*matrix[1][3];
		a=matrix[0][4]-b*matrix[0][1]-c*matrix[0][2]-d*matrix[0][3];
		printf("a = %lf b= %lf c = %lf d = %lf",a,b,c,d);
	}
	if(n == 5)
	{
		e=matrix[4][5];
		d=matrix[3][5]-e*matrix[3][4];
		c=matrix[2][5]-d*matrix[2][3]-e*matrix[2][4];
		b=matrix[1][5]-c*matrix[1][2]-d*matrix[1][3]-e*matrix[1][4];
		a=matrix[0][5]-b*matrix[0][1]-c*matrix[0][2]-d*matrix[0][3]-e*matrix[0][4];
		printf("a = %lf b= %lf c = %lf d = %lf e = %lf",a,b,c,d,e);
	}	
			

}

/* Function to perform division on a row */			
void funcdivide(int first,int second,int count)
{

	int i,j;
	double swopmatrix[12][13];
	
	a1:divisor=matrix[first][second];
	printf("divisor is %lf \n",divisor);
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
/* The next few lines are commented out. You can use them to display your matrix at each stage for testing */
/* The number of terms in printf will vary with the size of the matrix */
/*
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
*/	
	
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

	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<row;j++)
	{
		if(row == 3)
			printf("%lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3]);
		else if(row == 4)
			printf("%lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4]);
			else
				printf("%lf %lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4],matrix[j][5]);
	}
}	

/* Function to perform subtraction of one row from another */	 
void funcsubtract(int first,int second,int count)
{

	int i,j;	
	

	if(matrix[first][second] != 0.000000) /* check for swopped row */
		for(i=second;i<col;i++)
		{
			matrix[first][i]=(matrix[first][i])-matrix[second][i];
		}

/* The next few lines are commented out. You can use them to display your matrix at each stage for testing */
/* The number of terms in printf will vary with the size of the matrix */
/*	
	printf("augmented matrix after %d operation is\n",count);
	for(j=0;j<row;j++)
	{
		if(row == 3)
			printf("%lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3]);
		else if(row == 4)
			printf("%lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4]);
			else
				printf("%lf %lf %lf %lf %lf %lf\n",matrix[j][0],matrix[j][1],matrix[j][2],matrix[j][3],matrix[j][4],matrix[j][5]);
	}
*/
}	

