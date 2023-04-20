#pragma once
#include "IComponentSensor.h"

// ������ ���������
class HumiditySensor : public IComponentSensor
{

public:
	HumiditySensor()
	{
		AverageHumidity = 50;
	}

	HumiditySensor(double humidity)
	{
		AverageHumidity = humidity;
	}

	// ���������� ������� ��������� �������
	void SetAverageHum(double humidity)
	{
		AverageHumidity = humidity;
	}

	// �������� ��������� � �������
	double GetHumidity()
	{
		return(this->GenericHumidity(AverageHumidity - 2, AverageHumidity + 2)); // ��������� ������ ��������
	}

	// ������������� ��������� ��� �������� ������ �������
	double GenericHumidity(double min, double max)
	{
		return (RandomNumbers::GetRandomInt(min, max));
	}

	// �������� ��������� �� 1 �������
	void UpOneHimid()
	{
		AverageHumidity += 1;
	}

	// �������� ��������� �� 1 �������
	void DownOneHimid()
	{
		AverageHumidity -= 1;
	}

};

