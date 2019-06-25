/* Structure example program */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/* define the structure */ 
struct Student {
   int id;
   char name[16];
   float percent;
};
 
int main() {
   /* define two data locations of type "student" */
   struct Student s1, s2;
	
	/* Assign values to the s1 structure */

	s1.id = 56;
	strcpy( s1.name, "Rob Smith");
   	s1.percent = 67.400000;
 
    	/* Print out structure s1 */

   	printf("\nid : %d", s1.id);
  	printf("\nName : %s", s1.name);
  	printf("\nPercent : %f", s1.percent);

	/* Assign values to the s2 structure */

	s2.id = 73;
	strcpy( s2.name, "Mary Gallagher");
   	s2.percent = 93.800000;
 
    	/* Print out structure s1 */

   	printf("\nid : %d", s2.id);
  	printf("\nName : %s", s2.name);
  	printf("\nPercent : %f", s2.percent);

 
   return (0);
}
