// Пример 3
//Используя концепцию многофайлового программирования и сборки приложения,
//написать на языке С приложение, которое позволяет вывести информацию о самом
//старшем студенте.Информация о группе студентов хранится в файле.Запись имеет
//следующий вид :
//1. Фамилия
//2. Имя
//3. Отчество
//4. Год рождения
//5. Пол
//6. Оценки по предметам(не менее трех предметов)
//В группе не менее 10 человек(5 юношей и 5 девушек).
//Программа должна допускать следующие режимы работы :
//(1) Добавить запись в файл(если файла нет, то создать его)
//(2) Просмотреть все записи файла
//(3) Вывести результаты запроса — информацию о самом старшем студенте

#include <stdio.h>

void addNote();
void printNodes();
void printInfOldestStud();


int main(int argc, char* argv[])
{
	int operation = 0;
	printf("Operations:\n1 - Add node\n2 - Print all nodes\n3 - Print information about the oldest student\n4 - Exit\n");

	while (1)
	{
		if (operation == 4)
			break;
		printf("Choose operation\n");
		scanf("%d", &operation);
		getchar();
		switch (operation)
		{
		case 1:
			addNote();
			break;
		case 2:
			printNodes();
			break;
		case 3:
			printInfOldestStud();
			break;
		default:
			printf("Please, enter valid number of operation\n");
			break;
		}
	}

	return 0;
}