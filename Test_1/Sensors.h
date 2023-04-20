#pragma once
#include "Humidifier.h"


// Датчики температуры и влажности
// И методы работы с нимим как с одним целым
class Sensors
{
private:

	// Набор сенсоров температуры
	vector <TemperatureSensorC0> *TemperSensors;

	// Набор сенсоров влажности
	//Humidifier* HumidSensors;

public:

	Sensors()
	{
		TemperSensors = new vector <TemperatureSensorC0>();
		//HumidSensors = new Humidifier();
	}

	// Задать сенсоры
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
	{
		TemperSensors = temperSensors;
	}

	// Задать сенсоры
	//void SetHimidSensors(Humidifier* humidSensors)
	//{
	//	;//HumidSensors = humidSensors;
	//}

	// Поиск минимума температуры
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

	// Поиск максимума температуры
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

	// Сортировка температур
	void SortTemperature()
	{
		;
	}

	

	// Эмитация потерь температур и влажности,
	// которые происходят в настоящем инкубаторе
	bool Poteri()
	{


		for (int i = 0; i < TemperSensors->size(); i++)
		{
			for (int j = 0; j < 12; j++)
				TemperSensors->at(i).DownZeroOneTemp();

			Sleep(10);
		}

		return 0;
	}

};

