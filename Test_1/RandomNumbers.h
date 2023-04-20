#pragma once
#include <stdlib.h>		// Для генерации случ. чисел
#include <time.h>		// Для генерации случ. чисел

#include <omp.h>		// запрашиваем время в миллисекундах

#include <iostream>		// Для вывода с++
#include <stdio.h>		// Для вывода с

#include "windows.h"	// Для временной задержки Sleep

#include <vector>		// Для работы с векторами

#include <algorithm>	// std::min_element
#include <iterator>		// std::begin, std::end

#include <chrono>		// Для получения текущего времени

#include <string>		// Для строк

#include <Windows.h>	// Для system

#include <sstream>		// Для перевода LARGE_INTEGER в
#include <iomanip>		// string

// Макроподстановка для объявления полей класса
#define DEF(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
	void set_##var(type val) { var = val; }


using namespace std::chrono;

using namespace std;


class RandomNumbers
{

public:
	// Функция, генерирующая случайное действительное число от min до max
	static double GetRandomDouble(double min, double max);

	// Функция генерирования случайного целочисленного числа в указанных пределах.
	// Диапазон чисел: [min, max]
	static int GetRandomInt(int min, int max);
};

