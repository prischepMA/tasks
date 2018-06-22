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

void printMostUnsuccess()
{
	student *records = (student*)malloc(sizeof(student) * 100);;
	FILE *fStudBin = fopen("STUDENTS", "rb");
	if (fStudBin != NULL)
	{
		if (fread(&records[0], sizeof(student), 1, fStudBin))
		{
			int idxMostUnsuccess = 0;
			int minAverageMark = (records[0].markCN + records[0].markTP + records[0].markOS) / 3;
			for (int i = 1; fread(&records[i], sizeof(student), 1, fStudBin); i++)
			{
				if (minAverageMark > (records[i].markCN + records[i].markTP + records[i].markOS) / 3)
				{
					minAverageMark = (records[i].markCN + records[i].markTP + records[i].markOS) / 3;
					idxMostUnsuccess = i;
				}
			}
			printf("\n\tSecond name: %s\n\tName: %s\n\tPatronymic: %s\n\tBirth year: %d\n\tGender: %s\n\tMark TP: %d\n\tMark OS %d\n\tMark CN: %d\n", records[idxMostUnsuccess].secondName, records[idxMostUnsuccess].name, records[idxMostUnsuccess].patronymic, records[idxMostUnsuccess].birthYear, records[idxMostUnsuccess].gender, records[idxMostUnsuccess].markTP, records[idxMostUnsuccess].markOS, records[idxMostUnsuccess].markCN);

		}
	}
	fclose(fStudBin);
	free(records);
}