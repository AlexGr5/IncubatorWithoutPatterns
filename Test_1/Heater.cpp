#include "Heater.h"

Heater::Heater()
{
	TemperSensors = new vector <TemperatureSensorC0>();
}

// Задать сенсоры
void Heater::SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
{
	TemperSensors = temperSensors;
}

void Heater::AddSensor(TemperatureSensorC0 tempSensor)
{
	TemperSensors->push_back(tempSensor);
}

// Нагреть все датчики на 0.1 градус
bool Heater::UpOnePercent()
{
	for (int i = 0; i < TemperSensors->size(); i++)
	{
		TemperSensors->at(i).UpZeroOneTemp();

		Sleep(2);
	}

	

	return(true);
}


vector <TemperatureSensorC0>* Heater::GetSensors()
{
	return TemperSensors;
}