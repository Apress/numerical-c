#include <stdio.h> /* Demonstrate a goto statement */
int main()
{
   int i,testvalue;

	testvalue = 2;

   for (i=0; i<10; i++)

   {
	if(testvalue == 2)
		goto error;
   }
   printf("Normal Exit from forloop\n");
   
error:
	printf("testvalue is %d\n", testvalue);
}
