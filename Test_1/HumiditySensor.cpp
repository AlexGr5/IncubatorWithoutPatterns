#include "HumiditySensor.h"

HumiditySensor::HumiditySensor()
{
	AverageHumidity = 50;
}

HumiditySensor::HumiditySensor(double humidity)
{
	AverageHumidity = humidity;
}

// ���������� ������� ��������� �������
void HumiditySensor::SetAverageHum(double humidity)
{
	AverageHumidity = humidity;
}

// �������� ��������� � �������
double HumiditySensor::GetHumidity()
{
	return(this->GenericHumidity(AverageHumidity - 2, AverageHumidity + 2)); // ��������� ������ ��������
}

// ������������� ��������� ��� �������� ������ �������
double HumiditySensor::GenericHumidity(double min, double max)
{
	return (RandomNumbers::GetRandomInt(min, max));
}

// �������� ��������� �� 1 �������
void HumiditySensor::UpOneHimid()
{
	AverageHumidity += 1;
}

// �������� ��������� �� 1 �������
void HumiditySensor::DownOneHimid()
{
	AverageHumidity -= 1;
}