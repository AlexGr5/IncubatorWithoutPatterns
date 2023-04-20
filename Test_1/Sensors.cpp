#include "Sensors.h"

Sensors::Sensors()
{
	//TemperSensors = new vector <TemperatureSensorC0>();
	HumidSensors = new vector <HumiditySensor>();
	data = new myContainer();
}

// Задать сенсоры
void Sensors::SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
{
	//TemperSensors = temperSensors;
}

// Задать сенсоры
void Sensors::SetHimidSensors(vector <HumiditySensor>* humidSensors)
{
	HumidSensors = humidSensors;
}

// Поиск минимума температуры
double Sensors::MinTemperature()
{
	double minimum = data->begin().next()->GetTemperatureC0();
	myContainer::myIterator it = data->begin();
	for (; it != data->end(); ++it)
	{
		double temp = it.next()->GetTemperatureC0();
		if (temp < minimum)
			minimum = temp;
	}

	return(minimum);
}

// Поиск максимума температуры
double Sensors::MaxTemperature()
{
	
	double maximum = data->begin().next()->GetTemperatureC0();
	myContainer::myIterator it = data->begin();
	for (; it != data->end(); ++it)
	{
		double temp = it.next()->GetTemperatureC0();
		if (temp > maximum)
			maximum = temp;
	}

	return(maximum);
}

// Сортировка температур
void Sensors::SortTemperature()
{
	;
}

// Поиск минимума влажности
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

// Поиск максимума влажности
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

// Сортировка влажности
void Sensors::SortHumidity()
{
	;
}

// Эмитация потерь температур и влажности,
// которые происходят в настоящем инкубаторе
bool Sensors::Poteri()
{
	for (int i = 0; i < HumidSensors->size(); i++)
	{
		for (int j = 0; j < 12; j++)
			HumidSensors->at(i).DownOneHimid();

		Sleep(10);
	}
	

	for (myContainer::myIterator it = data->begin(); it != data->end(); ++it) {
		for (int j = 0; j < 12; j++)
			it.next()->DownZeroOneTemp();

		Sleep(10);
	}

	return 0;
}