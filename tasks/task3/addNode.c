#include <stdio.h>

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

void addNote()
{
	student record;
	printf("Please, enter\nSecond name\nName\nPatronymic\nBirth Year\nGender\nMark TP\nMark OS\nMark CN\n");
	scanf("%s%s%s%d%s%d%d%d", record.secondName, record.name, record.patronymic, &record.birthYear, record.gender, &record.markTP, &record.markOS, &record.markCN);

	FILE *fStudBin = fopen("STUDENTS", "ab+");
	fwrite(&record, sizeof(student), 1, fStudBin);
	fclose(fStudBin);
}