/* filewritepatients */
/* reads from file */
/* prints out the records sequentially */

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
	int i, numread;
	FILE *fp;
	struct Patient s1;
	struct Patient s2;

/* Preset data for each patient */

	struct Patient s10 = { 10,"Brown       ",50,'y','n','n','y','n','y' };
	struct Patient s11 = { 11,"Jones       ",51,'y','y','n','y','y','n' };
	struct Patient s12 = { 12,"White       ",52,'y','n','y','y','n','n' };
	struct Patient s13 = { 13,"Green       ",53,'y','n','y','y','n','n' };
	struct Patient s14 = { 14,"Smith       ",54,'y','y','n','y','y','n' };
	struct Patient s15 = { 15,"Black       ",55,'y','n','n','y','n','n' };
	struct Patient s16 = { 16,"Allen       ",56,'y','n','n','y','n','y' };
	struct Patient s17 = { 17,"Stone       ",57,'y','n','n','y','y','n' };
	struct Patient s18 = { 18,"Evans       ",58,'y','y','n','y','n','n' };
	struct Patient s19 = { 19,"Royle       ",59,'y','n','y','y','n','n' };
	struct Patient s20 = { 20,"Stone       ",60,'y','y','n','y','n','n' };
	struct Patient s21 = { 21,"Weeks       ",61,'y','n','n','y','y','y' };
	struct Patient s22 = { 22,"Owens       ",62,'y','n','n','y','y','y' };
	struct Patient s23 = { 23,"Power       ",63,'y','n','n','y','n','n' };
	struct Patient s24 = { 24,"Bloom       ",63,'y','n','y','y','n','n' };
	struct Patient s28 = { 28,"Haver       ",68,'y','y','n','y','n','n' };
	struct Patient s29 = { 29,"James       ",69,'y','y','n','y','n','n' };


	/* Open the Patients file */

	fp = fopen("patientex.bin", "w");

	/* Write details of each patient to file*/
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

	fopen("patientex.bin", "r");

	/* Read and print out all of the records on the file */

	for (i = 0;i < 17;i++)
	{

		numread = fread(&s2, sizeof(s2), 1, fp);

		if (numread == 1)
		{
			/*printf( "Number of items read = %d ", numread );*/

			printf("\nPatientID : %d", s2.PatientID);
			printf("\nName : %s", s2.name);
			printf("\nBloodPressure : %d", s2.BloodPressure);
			printf("\nAllergies %c leukaemia %c anaemia %c", s2.allergies, s2.leukaemia, s2.anaemia);
			printf("\nAsthma %c epilepsy %c famely epilepsy %c", s2.asthma, s2.epilepsy, s2.famepil);
		}

		else {
			/* If an error occurred on read then print out message */

			if (feof(fp))

				printf("Error reading patients.bin : unexpected end of file fp is %p\n", fp);


			else if (ferror(fp))
			{
				perror("Error reading patients.bin");
			}
		}





	}
	/* Close the file */

	fclose(fp);



}
