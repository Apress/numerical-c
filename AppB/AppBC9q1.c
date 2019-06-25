/* filereadexr */
/* reads from file */
/* reads and prints sequentially */
/* reads and prints specific records */
/* Does not use seek */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Patient {
	int PatientID;
	char name[13];
	int BloodPressure;
	char allergies;
	char leukaemia;
	char anaemia;
	char asthma;
	char epilepsy;
	char famepil;
};

int main()
{
	FILE *fp;

	
	struct Patient s2;


	int numread, i;
	double casthepi;
	double percent;

	/* Open patients file */

	fp = fopen("patientex.bin", "r");
	if(!fp)
	{
		printf("patientex.bin file unavailable");
		return(0);
	}
	for (i = 0;i < 17;i++)
	{
		/* Read each patient data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print patient ID, name and Blood Pressure for each patient */

		printf("\nPatientID : %d", s2.PatientID);
		printf("\n Name : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
		printf("\nAllergies %c leukaemia %c anaemia %c", s2.allergies, s2.leukaemia, s2.anaemia);
		printf("\nAsthma %c epilepsy %c famely epilepsy %c", s2.asthma, s2.epilepsy, s2.famepil);


	}

	fclose(fp);


	/* Re-open the patients file */

	fp = fopen("patientex.bin", "r");
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
	/* Close the file */

	fclose(fp);
	/* Re-open the patients file */
	casthepi = 0;
	fp = fopen("patientex.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Search the file for link between asthma and epilepsy */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.epilepsy == 'y' && s2.asthma == 'y')
		{
			casthepi = casthepi + 1.0;
			/* Found the patient. Print their name */
			printf("\nLink between asthma and epilepsy");
			printf("\nName : %s", s2.name);

		}
	}
	percent = (casthepi / 17.0)*100.0;
	printf("\npercent asthma & epilepsy : %f", percent);
	fclose(fp);

}
