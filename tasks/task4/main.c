//������ 4
//��������� ��������� �������������� ���������������� � ������ ����������,
//�������� �� ����� � ����������, ������� ��������� ������� ���������� � �����
//������������ ��������.������������������ �������������� ��������, ��������
//������ � �����.������ ����� ��������� ��� :
//1. �������
//2. ���
//3. ��������
//4. ��� ��������
//5. ���
//6. ������ �� ���������(�� ����� ���� ���������)
//� ������ �� ����� 10 �������(5 ������ � 5 �������).
//��������� ������ ��������� ��������� ������ ������ :
//(1) ����������� ��� ������ �����
//(2) ������� ���������� ������� � ������� ���������� � ����� ������������ ��������
//(3) ������� ���������� ������� � ��� �������� � �������� �� ��� ����� � �������

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