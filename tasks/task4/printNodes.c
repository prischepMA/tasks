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

void printNodes()
{
	student *records = (student*)malloc(sizeof(student) * 100);;
	FILE *fStudBin = fopen("STUDENTS", "rb");
	if (fStudBin != NULL)
	{
		int i = 0;
		while (fread(&records[i], sizeof(student), 1, fStudBin))
			printf("\n\tSecond name: %s\n\tName: %s\n\tPatronymic: %s\n\tBirth year: %d\n\tGender: %s\n\tMark TP: %d\n\tMark OS %d\n\tMark CN: %d\n", records[i].secondName, records[i].name, records[i].patronymic, records[i].birthYear, records[i].gender, records[i].markTP, records[i].markOS, records[i].markCN);
	}
	fclose(fStudBin);
	free(records);
}