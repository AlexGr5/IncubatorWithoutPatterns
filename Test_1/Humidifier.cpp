#include "Humidifier.h"

Humidifier::Humidifier()
{
	HumidSensors = new vector <HumiditySensor>();
}

// Задать сенсоры
void Humidifier::SetHimidSensors(vector <HumiditySensor>* humidSensors)
{
	HumidSensors = humidSensors;
}

void Humidifier::AddSensor(HumiditySensor humidSensor)
{
	HumidSensors->push_back(humidSensor);
}

// Увеличить влажность всех датчиков на 1 процент
bool Humidifier::UpOnePercent()
{
	for (int i = 0; i < HumidSensors->size(); i++)
	{
		HumidSensors->at(i).UpOneHimid();

		Sleep(2);
	}

	

	return(true);
}

vector <HumiditySensor>* Humidifier::GetSensors()
{
	return HumidSensors;
}