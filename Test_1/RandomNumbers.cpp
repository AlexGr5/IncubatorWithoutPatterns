#include "RandomNumbers.h"

// Функция, генерирующая случайное действительное число от min до max
double RandomNumbers::GetRandomDouble(double min, double max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

// Функция генерирования случайного целочисленного числа в указанных пределах.
// Диапазон чисел: [min, max]
int RandomNumbers::GetRandomInt(int min, int max)
{
	// Установить генератор случайных чисел
	srand(time(NULL));

	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);

	return num;
}