#pragma once
#include "Humidifier.h"


// ������� ����������� � ���������
// � ������ ������ � ����� ��� � ����� �����
class Sensors
{
private:

	// ����� �������� �����������
	vector <TemperatureSensorC0> *TemperSensors;

	// ����� �������� ���������
	Humidifier* HumidSensors;

public:

	Sensors()
	{
		TemperSensors = new vector <TemperatureSensorC0>();
		HumidSensors = new Humidifier();
	}

	// ������ �������
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
	{
		TemperSensors = temperSensors;
	}

	// ������ �������
	void SetHimidSensors(Humidifier* humidSensors)
	{
		HumidSensors = humidSensors;
	}

	// ����� �������� �����������
	double MinTemperature()
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
	double MaxTemperature()
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
	void SortTemperature()
	{
		;
	}

	// ����� �������� ���������
	double MinHummidity()
	{
		if (HumidSensors->GetSize() > 0)
		{
			double minimum = HumidSensors->GetI(0).GetHumidity();
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

};

