#include "Sensors.h"

Sensors::Sensors()
{
	TemperSensors = new vector <TemperatureSensorC0>();
	HumidSensors = new vector <HumiditySensor>();
}

// ������ �������
void Sensors::SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
{
	TemperSensors = temperSensors;
}

// ������ �������
void Sensors::SetHimidSensors(vector <HumiditySensor>* humidSensors)
{
	HumidSensors = humidSensors;
}

// ����� �������� �����������
double Sensors::MinTemperature()
{
	if (TemperSensors->size() > 0)
	{
		double minimum = TemperSensors->at(0).GetTemperatureC0();
			for (int i = 0; i < TemperSensors->size(); i++)
			{
				if (TemperSensors->at(i).GetTemperatureC0() < minimum)
					minimum = TemperSensors->at(i).GetTemperatureC0();
			}

		return(minimum);
	}
	else
		return (-999);
}

// ����� ��������� �����������
double Sensors::MaxTemperature()
{
	if (TemperSensors->size() > 0)
	{
		double maximum = TemperSensors->at(0).GetTemperatureC0();
		for (int i = 0; i < TemperSensors->size(); i++)
		{
			if (TemperSensors->at(i).GetTemperatureC0() > maximum)
				maximum = TemperSensors->at(i).GetTemperatureC0();
		}

		return(maximum);
	}
	else
		return (999);
}

// ���������� ����������
void Sensors::SortTemperature()
{
	;
}

// ����� �������� ���������
double Sensors::MinHummidity()
{
	if (HumidSensors->size() > 0)
	{
		double minimum = HumidSensors->at(0).GetHumidity();
		for (int i = 0; i < HumidSensors->size(); i++)
		{
			if (HumidSensors->at(i).GetHumidity() < minimum)
				minimum = HumidSensors->at(i).GetHumidity();
		}

		return(minimum);
	}
	else
		return (-999);
}

// ����� ��������� ���������
double Sensors::MaxHummidity()
{
	if (HumidSensors->size() > 0)
	{
		double maximum = HumidSensors->at(0).GetHumidity();
		for (int i = 0; i < HumidSensors->size(); i++)
		{
			if (HumidSensors->at(i).GetHumidity() > maximum)
				maximum = HumidSensors->at(i).GetHumidity();
		}

		return(maximum);
	}
	else
		return (999);
}

// ���������� ���������
void Sensors::SortHumidity()
{
	;
}

// �������� ������ ���������� � ���������,
// ������� ���������� � ��������� ����������
bool Sensors::Poteri()
{
	for (int i = 0; i < HumidSensors->size(); i++)
	{
		for (int j = 0; j < 12; j++)
			HumidSensors->at(i).DownOneHimid();

		Sleep(10);
	}
	

	for (int i = 0; i < TemperSensors->size(); i++)
	{
		for (int j = 0; j < 12; j++)
			TemperSensors->at(i).DownZeroOneTemp();

		Sleep(10);
	}

	return 0;
}