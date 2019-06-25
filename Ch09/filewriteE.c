#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>


	

int main()
{

	struct record
	{
		double matrix[12][13];
	};
		int counter,i,j;
		FILE *ptr;
		struct record data_record;
		size_t r1;

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

	/* Copy preset array to output array */

	for(i=0;i<12;i++)
	{
		for(j=0;j<13;j++)
		{
			data_record.matrix[i][j]=inmat[i][j];
		}

	}

	/* Open output file (write/binary) */

	ptr=fopen("testaug.bin","wb");
	if (!ptr)
	{
		printf("Can not open file");
		return 1;
	}
		
	/* Write output matrix to output file */
	
	r1 = fwrite(data_record.matrix, sizeof(data_record.matrix), 1, ptr);
	printf("wrote %d elements \n", r1);
	printf("size of data_record.matrix is %d \n", sizeof(data_record.matrix));


	/* Print matrix written to file */

	for(i=0;i<12;i++)
	{
		for(j=0;j<13;j++)
		{
			data_record.matrix[i][j]=inmat[i][j];
			printf("data_record.matrix[%d][%d] = %lf \n",i,j,data_record.matrix[i][j]);
		}

	}


	fclose(ptr);
	return 0;
}

