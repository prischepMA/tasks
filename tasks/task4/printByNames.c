#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

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

void printByNames()
{
	char secondName[20];
	char name[20];
	printf("Please, enter Second name and Name\n");
	scanf("%s%s", secondName, name);

	student *records = (student*)malloc(sizeof(student) * 100);;
	FILE *fStudBin = fopen("STUDENTS", "rb");
	int isFinded = 0;
	if (fStudBin != NULL)
	{
		for (int i = 0; fread(&records[i], sizeof(student), 1, fStudBin); i++)
		{
			if (strcmp(secondName, records[i].secondName) == 0 && strcmp(name, records[i].name) == 0)
			{
				printf("\n\tSecond name: %s\n\tName: %s\n\tPatronymic: %s\n\tBirth year: %d\n\tGender: %s\n\tMark TP: %d\n\tMark OS %d\n\tMark CN: %d\n", records[i].secondName, records[i].name, records[i].patronymic, records[i].birthYear, records[i].gender, records[i].markTP, records[i].markOS, records[i].markCN);
				isFinded = 1;
				break;
			}
		}
	}
	if (!isFinded)
		printf("No such student\n");
	fclose(fStudBin);
	free(records);
}