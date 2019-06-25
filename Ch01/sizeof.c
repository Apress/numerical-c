/* Program to illustrate the use of the sizeof command */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h >
#include < limits.h >
#include < math.h >

int main(){

	int sizeofint;
	unsigned int sizeofunsint;
	float sizeoffloat;
	double sizeofdouble;

	printf("storage size for int : %d \n", sizeof(sizeofint));
	printf("storage size for uns int : %d \n", sizeof(sizeofunsint));
	printf("storage size for float : %d \n", sizeof(sizeoffloat));
	printf("storage size for double float: %d \n", sizeof(sizeofdouble));

	return(0);


}