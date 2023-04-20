#pragma once
#include "TemperatureSensorC0.h"

// ������ ���������
class HumiditySensor
{
private:
	
	// ������� ��������� �������
	double AverageHumidity;

public:
	double GetHumidity();			// �������� ��������� � �������

	HumiditySensor();

	HumiditySensor(double humidity);

	// ���������� ������� ��������� �������
	void SetAverageHum(double humidity);

	// �������� ��������� �� 1 �������
	void UpOneHimid();

	// �������� ��������� �� 1 �������
	void DownOneHimid();

protected:

	// ������������� ��������� ��� �������� ������ �������
	double GenericHumidity(double min, double max);

};

