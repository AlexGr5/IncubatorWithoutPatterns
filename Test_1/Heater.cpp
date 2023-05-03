#include "Heater.h"

Heater::Heater()
{
	TemperSensors = new vector <TemperatureSensorC0>();
}

// ������ �������
void Heater::SetTempSensors(vector <TemperatureSensorC0>* temperSensors)
{
	TemperSensors = temperSensors;
}

void Heater::AddSensor(TemperatureSensorC0 tempSensor)
{
	TemperSensors->push_back(tempSensor);
}

// ������� ��� ������� �� 0.1 ������
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