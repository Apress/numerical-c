#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/* Program to demonstrate string operations strlen, strcpy, strcat, strcmp */

int main () {
	char borrow[7] = {'b', 'o', 'r', 'r', 'o', 'w','\0'};
   char string1[32] = "This is string1";
   char string2[16] = "This is string2";
   char string3[16];
   int  len ;
/* Print out the lengths of the strings */
   
   len = strlen(string1);
   printf("strlen(string1) :  %d\n", len );
   len = strlen(string2);
   printf("strlen(string2) :  %d\n", len );
   len = strlen(string3);
   printf("strlen(string3) :  %d\n", len );


   /* copy string1 into string3 */
   strcpy(string3, string1);
   printf("strcpy( string3, string1) :  %s\n", string3 );
   len = strlen(string3);
   printf("strlen(string3) after copy of string1 into string3 :  %d\n", len );
   /* Compare string1 and string3 (these should be the same)*/
   if(strcmp(string1,string3) == 0)
	printf("strings are the same\n");


   /* concatenates string1 and string2 */
   strcat( string1, string2);
   printf("strcat( string1, string2):   %s\n", string1 );
   /* total length of string1 after concatenation */
   len = strlen(string1);
   printf("strlen(string1) after cat of string2 onto string1 :  %d\n", len );

   


   printf("String as predefined quoted chars: %s\n", borrow );
   

   return 0;
}

