#include "RandomNumbers.h"

// �������, ������������ ��������� �������������� ����� �� min �� max
double RandomNumbers::GetRandomDouble(double min, double max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

// ������� ������������� ���������� �������������� ����� � ��������� ��������.
// �������� �����: [min, max]
int RandomNumbers::GetRandomInt(int min, int max)
{
	// ���������� ��������� ��������� �����
	srand(time(NULL));

	// �������� ��������� ����� - �������
	int num = min + rand() % (max - min + 1);

	return num;
}