/* filewriteex3 */
/* Creates Company file */
/* prints out the records sequentially */

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
	int i,numread;
 	FILE *fp;
 	struct Company s1;
	struct Company s2;

	/* Preset a structure for each company to be written to the output file */
          
	struct Company s10 = {10,"Brown Co    ",20.2,402,0.3,45.5,43.2,2.7};
	struct Company s11 = {11,"CompuFix    ",1.3,354,2.6,60.3,27.5,1.6};	
	struct Company s12 = {12,"Wall's      ",12.6,766,5.8,14.7,54.6,3.8};
	struct Company s13 = {13,"Goldman Inc ",29.5,876,12.6,21.6,43.9,9.3};
	struct Company s14 = {14,"Stocks LLC  ",0.7,1252,8.2,18.4,38.4,3.8};
	struct Company s15 = {15,"Black & Blue",1.4,984,5.8,12.7,27.9,10.6};
	struct Company s16 = {16,"Allenby     ",52.8,1325,32.9,14.3,47.2,3.9};	
	struct Company s17 = {17,"StoneWorks  ",16.3,1548,4.6,28.9,51.3,4.1};
	struct Company s18 = {18,"Evans LLC   ",51.0,1006,19.6,51.7,43.7,11.7};
	struct Company s19 = {19,"Royle & Co  ",19.6,983,14.3,26.2,48.1,12.3}; 
	struct Company s20 = {20,"Stone Inc   ",24.8,1030,8.5,13.5,34.6,5.6};
	struct Company s21 = {21,"WeeksAway   ",16.9,547,0.9,12.9,43.9,2.9};	
	struct Company s22 = {22,"Owens Co    ",45.7,792,2.7,31.6,33.6,1.7};
	struct Company s23 = {23,"PowerTools  ",32.6,1563,17.5,29.3,51.8,13.3};
	struct Company s24 = {24,"Bloom       ",27.2,1869,23.9,18.7,40.4,9.6};

	struct Company s28 = {28,"HaverGoodOne",33.8,489,3.6,12.7,43.8,3.7};
	struct Company s29 = {29,"James & Co  ",15.5,639,17.4,15.9,36.5,4.5};

   	
	/* Open the Companys file */
	
   	fp = fopen("Companyex.bin", "w");

	/* Write details of each Company to file*/
	/* From the structures defined above */

   	fwrite(&s10, sizeof(s1), 1, fp);
	fwrite(&s11, sizeof(s1), 1, fp);
	fwrite(&s12, sizeof(s1), 1, fp);
	fwrite(&s13, sizeof(s1), 1, fp);
	fwrite(&s14, sizeof(s1), 1, fp);
   	fwrite(&s15, sizeof(s1), 1, fp);
	fwrite(&s16, sizeof(s1), 1, fp);
	fwrite(&s17, sizeof(s1), 1, fp);
	fwrite(&s18, sizeof(s1), 1, fp);
	fwrite(&s19, sizeof(s1), 1, fp);
   	fwrite(&s20, sizeof(s1), 1, fp);
   	fwrite(&s21, sizeof(s1), 1, fp);
	fwrite(&s22, sizeof(s1), 1, fp);
	fwrite(&s23, sizeof(s1), 1, fp);
	fwrite(&s24, sizeof(s1), 1, fp);
 
	fwrite(&s28, sizeof(s1), 1, fp);
	fwrite(&s29, sizeof(s1), 1, fp);

	/* Close the file */

   	fclose(fp);

 	/* Reopen the file */

	fopen("Companyex.bin", "r");

	/* Read and print out all of the records on the file */

	for(i=0;i<17;i++)
	{

		numread=fread(&s2, sizeof(s2), 1, fp);

		if(numread == 1)
		{



		
			/*printf( "Number of items read = %d ", numread );*/
		
			printf("\nCompanyID : %d", s2.CompanyID);
   			printf("\ncompanyname : %s", s2.companyname);
   			printf("\nprofit as a percentage of sales : %f", s2.salesprofitpct);
			printf("\ntotal populations countries for sales (in millions) %f ", s2.totalctrypop);
			printf("\nAdvertising as a percentage of sales %f ", s2.advertpct);
			printf("\nTotal salaries as a percentage of profit %f ", s2.salprofpct);
			printf("\nWomen as a percentage of total workers %f ", s2.mwpct);
			printf("\nForeign workers as a percentage of total %f ", s2.alienwpct);

		}
		else {
			/* If an error occurred on read then print out message */
 
       			if (feof(fp))

          			printf("Error reading Companys.bin : unexpected end of file fp is %p\n",fp);

       			else if (ferror(fp))
	 		{
         	 		perror("Error reading Companys.bin");
      	 		}
		}



	
	
	}
	/* Close the file */

	fclose(fp);





}