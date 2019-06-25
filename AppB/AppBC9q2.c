/* filereadex3r */
/* reads from Company file */
/* reads and prints sequentially */
/* reads and prints specific records */
/* does not use seek */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


struct Company {
	int CompanyID;
	char companyname[13];
	float salesprofitpct;/* profit as a % of sales */
	float totalctrypop;/* total populations countries for sales (in millions) */
	float advertpct;/* Advertising as a % of sales */
	float salprofpct;/* Total salaries as a % of profit */
	float mwpct;/* Women as a % of total workers */
	float alienwpct;/* Foreign workers as a % of total */

};
int main()
{
	FILE *fp;

	struct Company s2;


	int numread, i;
	double count; /* count of women to men >40 salespercent >40 */
	double percent;/* percent of women to men >40 salespercent >40 */

	/* Open patients file */

	fp = fopen("Companyex.bin", "r");
	if(!fp)
	{
		printf("Companyex.bin file not available");
		return(0);
	}
	for (i = 0;i < 17;i++)
	{
		/* Read and print each Company data from file sequentially */


		fread(&s2, sizeof(s2), 1, fp);
		/* Print Company ID, name etc */
		printf("\nCompanyID : %d", s2.CompanyID);
		printf("\ncompanyname : %s", s2.companyname);
		printf("\nprofit as a percentage of sales : %f", s2.salesprofitpct);
		printf("\ntotal populations countries for sales (in millions) %f ", s2.totalctrypop);
		printf("\nAdvertising as a percentage of sales %f ", s2.advertpct);
		printf("\nTotal salaries as a percentage of profit %f ", s2.salprofpct);
		printf("\nWomen as a percentage of total workers %f ", s2.mwpct);
		printf("\nForeign workers as a percentage of total %f ", s2.alienwpct);




	}

	fclose(fp);


	/* Re-open the Company file */

	fp = fopen("Companyex.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Search the file for Company with ID of 23 */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.CompanyID == 23)
		{
			/* Found the company. Print their name */
			printf("\nCompany with ID of 23 ");
			printf("\nCompany Name : %s", s2.companyname);
			break;
		}
	}
	/* Go back to the beginning of the file */


	rewind(fp);
	/* Find all Companys with women to men percent > 50  */

	for (i = 0;i < 17;i++)
	{
		fread(&s2, sizeof(s2), 1, fp);
		if (s2.mwpct > 50)
		{
			/* Print out name of each company with women to men percent > 50*/
			printf("\nwomen to men >50pc");
			printf("\nCompany Name : %s", s2.companyname);

		}
	}
	/* Go back to the beginning of the file */


	rewind(fp);

	/* Read and print out the first 3 Companys in the file */

	numread = fread(&s2, sizeof(s2), 1, fp);
	printf("\nFirst 3 companies on file");
	if (numread == 1)
	{
		printf("\nCompanyID : %d", s2.CompanyID);
		printf("\nCompany Name : %s", s2.companyname);

	}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{

		printf("\nCompanyID : %d", s2.CompanyID);
		printf("\nCompany Name : %s", s2.companyname);

	}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{

		printf("\nCompanyID : %d", s2.CompanyID);
		printf("\nCompany Name : %s", s2.companyname);

	}
	/* Close the file */

	fclose(fp);
	/* Re-open the patients file */
	count = 0;/* set count of percent women to men >40 salespercent >40*/
 	fp = fopen("Companyex.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Search count of percent women to men >40 salespercent >40 */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.mwpct > 40.0 && s2.salesprofitpct > 40.0)
		{
			count = count + 1.0; /* Add 1 to overall count */

			/* Found the company. Print their name */

			printf("\nLink between women to men >40pc and salespc > 40 ");
			printf("\nName : %s", s2.companyname);

		}
	}
	/* Calculated and print percentage of women to men over 40 and salespercent over 40 */
	percent = (count / 17.0)*100.0;
	printf("\npercent women to men >40 salespercent >40 : %f", percent);
 
	fclose(fp);
}
