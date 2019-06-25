#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Example of using a switch on characters */
int main()
{
     
	char this_is_a_character;

	printf( "Please enter character a,b,c,d or e:\n " );
    	scanf( "%c", &this_is_a_character );


     switch (this_is_a_character)
     {
         case 'a':
            printf("a entered");
            break;
         case 'b':
            printf("b entered");
            break;
         case 'c':
            printf("c entered");
            break;
         case 'd':
            printf("d entered");
            break;
         case 'e':
            printf("e entered");
            break;
         default:
            printf("Default ");
    }
    return 0;
}