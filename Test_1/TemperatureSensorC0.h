#pragma once
#include "RandomNumbers.h"

// ������ �����������
class TemperatureSensorC0
{
private:

	// ������� ����������� �������
	double AverageTemperature;

public:

	TemperatureSensorC0();

	TemperatureSensorC0(double temperaature);

	// �������� ����������� � �������
	double GetTemperatureC0();

	// ���������� ������� ����������� �������
	void SetAverageTemp(double temperaature);

	// �������� ����������� �� 0.1 ������
	void UpZeroOneTemp();

	// �������� ����������� �� 0.1 ������
	void DownZeroOneTemp();

protected:

	// ������������� ����������� ��� �������� ������ �������
	double GenericTemperatureC0(double min, double max);

};