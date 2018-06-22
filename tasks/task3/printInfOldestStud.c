#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{
	char secondName[20];
	char name[20];
	char patronymic[20];
	int birthYear;
	char gender[10];
	int markTP;
	int markOS;
	int markCN;
} student;

void printInfOldestStud()
{
	student *records = (student*)malloc(sizeof(student) * 100);;
	FILE *fStudBin = fopen("STUDENTS", "rb");
	if (fStudBin != NULL)
	{
		if (fread(&records[0], sizeof(student), 1, fStudBin))
		{
			int idxOlderStud = 0;
			int maxOld = records[0].birthYear;
			for (int i = 1; fread(&records[i], sizeof(student), 1, fStudBin); i++)
			{
				if (maxOld > records[i].birthYear)
				{
					maxOld = records[i].birthYear;
					idxOlderStud = i;
				}
			}
			printf("\n\tSecond name: %s\n\tName: %s\n\tPatronymic: %s\n\tBirth year: %d\n\tGender: %s\n\tMark TP: %d\n\tMark OS %d\n\tMark CN: %d\n", records[idxOlderStud].secondName, records[idxOlderStud].name, records[idxOlderStud].patronymic, records[idxOlderStud].birthYear, records[idxOlderStud].gender, records[idxOlderStud].markTP, records[idxOlderStud].markOS, records[idxOlderStud].markCN);

		}
	}
	fclose(fStudBin);
	free(records);
}