#include "Heater.h"

Heater::Heater()
{
	TemperSensors = new vector <TemperatureSensorC0>();
	fact = new Factory();
	Size = 0;
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
bool Heater::WarmUpZeroOneDegreeC0()
{
	for (uint_fast8_t i = 0; i < Size; i++) {
		fact->getSensor(i)->UpOnePercent();

		Sleep(2);
	}

	return(true);
}


vector <TemperatureSensorC0>* Heater::GetSensors()
{
	return TemperSensors;
}