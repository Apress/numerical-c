#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Example of a switch operation */
int main()
{
     int this_is_a_number;

	printf( "Please enter an integer between 1 and 5:\n " );
    	scanf( "%d", &this_is_a_number );

     switch(this_is_a_number)
     {

	case 1:	
           printf("Case1: Value is: %d", this_is_a_number);
		break;
        case 2:
           printf("Case2: Value is: %d", this_is_a_number);
		break;
        case 3:
           printf("Case3: Value is: %d", this_is_a_number);
		break;
	case 4:
           printf("Case4: Value is: %d", this_is_a_number);
		break;
        case 5:
           printf("Case5: Value is: %d", this_is_a_number);
		break;
        default:
           printf("Error Value is: %d", this_is_a_number); /* The number entered was not between 1 and 5 */
    }
    return 0;
}