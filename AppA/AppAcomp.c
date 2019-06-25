#include<stdio.h>
main()
{
	float f,f1,f2;
	double d,d1,d2;
	int i,i1,i2;
   /* We want to divide 1623875 by 57 in double format, float format and integer format */
	
	f1=1623875;
	f2=57;

	d1=1623875;
	d2=57;

	i1=1623875;
	i2=57;

	d=d1/d2;
	f=f1/f2;
	i=i1/i2;

	printf("d is %lf, f is %f, i is %d\n",d,f,i);

/* Answer to this is d = 28489.035088 f = 28489.035156 i = 28489
	Calculator anwer is 28489.035087719289245614 (recurring)
*/


}
