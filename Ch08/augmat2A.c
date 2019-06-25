/* augmat2A */
/*	preset augmented matrix 3x4 */
/*	uses nine row operations for a 3 equation problem */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{

	float /*value,*/ x, y, z;

	/* Augmented matrix to be input is preset */
	float matrix[3][4] = {
		{2,1,-1,1},
		{2,-3,1,-1},
		{4,-1,4,14}
		};
	float divisor;
	int i, j;



	/* Read in the three rows (one element at a time) */

	/*for (j = 0;j < 3;j++)
	{
		printf("row %d ", j);
		for (i = 0;i < 4;i++)
		{
			printf("enter x\n");
			scanf("%f", &value);
			matrix[j][i] = value;
		}
	}
	*/

	/* Print out the preset augmented matrix  */

	printf("augmented matrix is\n");
	for (j = 0;j < 3;j++)
	{

		for (i = 0;i < 4;i++)
		{
			printf("matrix[%d][%d] = %f\n", j, i, matrix[j][i]);

		}
	}

	/* Nine stages on the rows of the augmented matrix for our 3 equation problem */

	/* stage 1 divide first row by (row 0 col 0 ) */
	divisor = matrix[0][0];
	for (i = 0;i < 4;i++)
	{
		matrix[0][i] = (matrix[0][i]) / divisor;
	}
	printf("augmented matrix after division of first row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 2 divide second row by (row 1 col 0 )*/
	divisor = matrix[1][0];
	for (i = 0;i < 4;i++)
	{
		matrix[1][i] = (matrix[1][i]) / divisor;
	}
	printf("augmented matrix after division of second row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 3 divide third row by (row 2 col 0 )*/
	divisor = matrix[2][0];
	for (i = 0;i < 4;i++)
	{
		matrix[2][i] = (matrix[2][i]) / divisor;
	}
	printf("augmented matrix after division of third row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}

	/* stage 4 subtract first row from second row */
	divisor = matrix[1][0];
	for (i = 0;i < 4;i++)
	{
		matrix[1][i] = (matrix[1][i]) - matrix[0][i];
	}
	printf("augmented matrix after subtraction of first row from second row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}

	/* stage 5 subtract first row from third row*/
	divisor = matrix[2][0];
	for (i = 0;i < 4;i++)
	{
		matrix[2][i] = (matrix[2][i]) - matrix[0][i];
	}
	printf("augmented matrix after subtraction of first row from third row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 6 divide second row by (row 1 col 1 )*/
	divisor = matrix[1][1];
	for (i = 0;i < 4;i++)
	{
		matrix[1][i] = (matrix[1][i]) / divisor;
	}
	printf("augmented matrix after division of second row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 7 divide third row by (row 2 col 1) */
	divisor = matrix[2][1];
	for (i = 0;i < 4;i++)
	{
		matrix[2][i] = (matrix[2][i]) / divisor;
	}
	printf("augmented matrix after division of third row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 8 subtract second row from third row*/
	divisor = matrix[2][0];
	for (i = 0;i < 4;i++)
	{
		matrix[2][i] = (matrix[2][i]) - matrix[1][i];
	}
	printf("augmented matrix after subtraction of second row from third row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}
	/* stage 9 divide third row by (row 2 col 2 )*/
	divisor = matrix[2][2];
	for (i = 0;i < 4;i++)
	{
		matrix[2][i] = (matrix[2][i]) / divisor;
	}
	printf("augmented matrix after division of third row is\n");
	for (j = 0;j < 3;j++)
	{
		printf("%f %f %f %f\n", matrix[j][0], matrix[j][1], matrix[j][2], matrix[j][3]);
	}

	/* Print out x,y and z solutions */

	z = matrix[2][3];
	y = matrix[1][3] - z * matrix[1][2];
	x = matrix[0][3] - y * matrix[0][1] - z * matrix[0][2];

	printf("x = %f y= %f z = %f", x, y, z);



}