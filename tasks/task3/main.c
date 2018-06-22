// ������ 3
//��������� ��������� �������������� ���������������� � ������ ����������,
//�������� �� ����� � ����������, ������� ��������� ������� ���������� � �����
//������� ��������.���������� � ������ ��������� �������� � �����.������ �����
//��������� ��� :
//1. �������
//2. ���
//3. ��������
//4. ��� ��������
//5. ���
//6. ������ �� ���������(�� ����� ���� ���������)
//� ������ �� ����� 10 �������(5 ������ � 5 �������).
//��������� ������ ��������� ��������� ������ ������ :
//(1) �������� ������ � ����(���� ����� ���, �� ������� ���)
//(2) ����������� ��� ������ �����
//(3) ������� ���������� ������� � ���������� � ����� ������� ��������

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