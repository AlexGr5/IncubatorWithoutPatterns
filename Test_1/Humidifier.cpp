#include "Humidifier.h"

Humidifier::Humidifier()
{
	HumidSensors = new vector <HumiditySensor>();
}

// ������ �������
void Humidifier::SetHimidSensors(vector <HumiditySensor>* humidSensors)
{
	HumidSensors = humidSensors;
}

void Humidifier::AddSensor(HumiditySensor humidSensor)
{
	HumidSensors->push_back(humidSensor);
}

// ��������� ��������� ���� �������� �� 1 �������
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