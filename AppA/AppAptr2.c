#include <stdio.h>

int main()
{
 	int ourvariable = 38;
	char achar = 'M';
	char anarray[10] = "HELLO";

	int *ourvariablep;
	char *acharp;
	char *anarrayp;

	ourvariablep = &ourvariable;
	acharp = &achar;
	anarrayp = anarray;



	printf("address of ourvariable is %xp\n",&ourvariable);
	printf("value in ourvariable is %d\n",ourvariable);
	printf("address in ourvariablep is %xp\n",ourvariablep);

	printf("address of achar is %xp\n",&achar);
	printf("value in achar is %c\n",achar);
	printf("address in acharp is %xp\n",acharp);

	printf("address of anarray is %xp\n",&anarray);
	printf("value in anarray is %s\n",anarray);
	printf("address in anarrayp is %xp\n", anarrayp); 

	return(0);
}
