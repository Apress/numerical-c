/* fileseek6r */
/* reads from file */
/* reads and prints sequentially */
/* reads and prints specific records */
/* Only does seek when finding a record (not going back to start) */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Patient {
	int PatientID;
	char name[13];
	int BloodPressure;
};

int main()
{
	FILE *fp;

	/*FILE *fpout;*/
	struct Patient s2;
	struct Patient s1 = { 68,"Warne       ",95 };

	int numread, i;
	int posn;
	long int minusone = -1;
	/* Open patients file */

	fp = fopen("patients.bin", "r+");
	for (i = 0;i < 17;i++)
	{
		/* Read each patient data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print patient ID, name and Blood Pressure for each patient */

		printf("\nPatientID : %d", s2.PatientID);
		printf("\n Name : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
		posn = ftell(fp);/* Find current file position */
		printf("\n file posn is : %d", posn);/* Print current file position */
	}

	fclose(fp);

	/* Re-open the patients file */

	fp = fopen("patients.bin", "r+");
	for (i = 0;i < 17;i++)
	{
		/* Search the file for patient with ID of 23 */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.PatientID == 23)
		{
			/* Found the patient. Print their name */
			printf("\nName : %s", s2.name);
			break;
		}
	}
	/* Go back to the beginning of the file */


	rewind(fp);
	/* Find all patients with Blood Pressure reading above 63 */
	for (i = 0;i < 17;i++)
	{
		fread(&s2, sizeof(s2), 1, fp);
		if (s2.BloodPressure > 63)
		{
			/* Print out name of each patient with Blood pressure above 63 */
			printf("\nName : %s", s2.name);

		}
	}
	/* Go back to the beginning of the file */


	rewind(fp);

	/* Read and print out the first 3 patients in the file */

	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{
	printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);

	}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{

		printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
	}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{

		printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
	}

	/* Demonstrate use of fseek to move current position in the file */
	/* Then overwrite the current structure with a new one */


	posn = ftell(fp);/* Find current file position */
	printf("\n file posn is : %d", posn);/* Print current file position */

	/* File pointer is now pointing to the 4th (the next) record in the file */

	fseek(fp, minusone*sizeof(s2), SEEK_CUR);/* set it back to point at the third */

	posn = ftell(fp);/* Find current file position */
	printf("\n file posn is : %d", posn);/* Print current file position */

	fwrite(&s1, sizeof(s1), 1, fp);/* overwrites what was in that position (3rd) */
	fclose(fp);
	fp = fopen("patients.bin", "r");
	for (i = 0;i < 18;i++)
	{
		/* Read each patient data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print patient ID, name and Blood Pressure for each patient */

		printf("\nPatientID : %d", s2.PatientID);
		printf("\n Name : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);


	}


	/* Close the file */

	fclose(fp);

}
