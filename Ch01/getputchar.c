#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* read and display a character */
int main () {
   char c;
 
   printf("Enter character: ");
   c = getchar(); /* read the character in */
 
   printf("Character entered: ");
   putchar(c); /* write the character */

   return(0);
}
