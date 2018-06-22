//Пример 4
//Используя концепцию многофайлового программирования и сборки приложения,
//написать на языке С приложение, которое позволяет вывести информацию о самом
//неуспевающем студенте.Продемонстрировать использованием структур, хранение
//данных в файле.Запись имеет следующий вид :
//1. Фамилия
//2. Имя
//3. Отчество
//4. Год рождения
//5. Пол
//6. Оценки по предметам(не менее трех предметов)
//В группе не менее 10 человек(5 юношей и 5 девушек).
//Программа должна допускать следующие режимы работы :
//(1) Просмотреть все записи файла
//(2) Вывести результаты запроса — вывести информацию о самом неуспевающем студенте
//(3) Вывести результаты запроса — все сведения о студенте по его имени и фамилии

#include <stdio.h>

void printNodes();
void printMostUnsuccess();
void printByNames();


int main(int argc, char* argv[])
{
	int operation = 0;
	printf("Operations:\n1 - Print all records\n2 - Print information about the most unsuccessful student\n3 - Print information about student with Second Name and First Name\n4 - Exit\n");

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
			printNodes();
			break;
		case 2:
			printMostUnsuccess();
			break;
		case 3:
			printByNames();
			break;
		default:
			printf("Please, enter valid number of operation\n");
			break;
		}
	}

	return 0;
}