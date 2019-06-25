/* Structure example program (extended structure)*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/* define the structure */ 
struct Student {
   int id;
   char name[16];
   float percent;
};
 
int main() {
	int i;
   /* define 5 data locations of type "student" */
  	 
	struct Student year9[5];
	
	for(i=0; i<5; i++)
	{
		/* Assign values to the structure */
		printf("enter student ID\n");
		scanf("%d",&year9[i].id);
		printf("enter student name\n");
		scanf("%s",year9[i].name);
		printf("enter student percent\n");
		scanf("%f",&year9[i].percent);

	
	}
	for(i=0; i<5; i++)
	{
  	 	/* Print out structure s1 */

  	 	printf("\nid : %d", year9[i].id);
  		printf("\nName : %s", year9[i].name);
  		printf("\nPercent : %f", year9[i].percent);


	}
 
    	
 
   return (0);
}
