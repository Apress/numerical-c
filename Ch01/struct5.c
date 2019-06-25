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
   /* define 5 data locations of type "student" */
  	 
	struct Student year9[5];
	
	/* Assign values to the s1 structure */

	year9[0].id = 56;
	strcpy( year9[0].name, "Rob Smith");
   	year9[0].percent = 67.400000;
 
    	/* Print out structure s1 */

   	printf("\nid : %d", year9[0].id);
  	printf("\nName : %s", year9[0].name);
  	printf("\nPercent : %f", year9[0].percent);

	/* Assign values to the s2 structure */

	year9[1].id = 73;
	strcpy(year9[1].name, "Mary Gallagher");
   	year9[1].percent = 93.800000;
 
    	/* Print out structure s1 */

   	printf("\nid : %d", year9[1].id);
  	printf("\nName : %s", year9[1].name);
  	printf("\nPercent : %f", year9[1].percent);

 
   return (0);
}
