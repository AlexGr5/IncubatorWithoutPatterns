#pragma once
#include <stdlib.h>		// ��� ��������� ����. �����
#include <time.h>		// ��� ��������� ����. �����

#include <omp.h>		// ����������� ����� � �������������

#include <iostream>		// ��� ������ �++
#include <stdio.h>		// ��� ������ �

#include "windows.h"	// ��� ��������� �������� Sleep

#include <vector>		// ��� ������ � ���������

#include <algorithm>	// std::min_element
#include <iterator>		// std::begin, std::end

#include <chrono>		// ��� ��������� �������� �������

#include <string>		// ��� �����

#include <Windows.h>	// ��� system

#include <sstream>		// ��� �������� LARGE_INTEGER �
#include <iomanip>		// string

// ���������������� ��� ���������� ����� ������
#define DEF(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
	void set_##var(type val) { var = val; }


using namespace std::chrono;

using namespace std;


class RandomNumbers
{

public:
	// �������, ������������ ��������� �������������� ����� �� min �� max
	static double GetRandomDouble(double min, double max);

	// ������� ������������� ���������� �������������� ����� � ��������� ��������.
	// �������� �����: [min, max]
	static int GetRandomInt(int min, int max);
};

