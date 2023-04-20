#pragma once
#include "HumiditySensor.h"
#include "Heater.h"

// Увлажнитель
class Humidifier : public IComponentSensor
{
protected:
	// Набор сенсоров влажности
	vector <IComponentSensor>* HumidSensors;

public:

	Humidifier()
	{
		HumidSensors = new vector <IComponentSensor>();
	}

	// Задать сенсоры
	void SetHimidSensors(vector <IComponentSensor>* humidSensors)
	{
		HumidSensors = humidSensors;
	}

	IComponentSensor GetI(int i)
	{
		if (i > 0 && i < HumidSensors->size())
			return HumidSensors->at(i);
	}

	// Вернуть размер списка сенсоров
	int GetSize()
	{
		return HumidSensors->size();
	}

	void AddSensor(HumiditySensor humidSensor)
	{
		HumidSensors->push_back(humidSensor);
	}

	// Увеличить влажность всех датчиков на 1 процент
	bool UpOneHimid()
	{
		for (int i = 0; i < HumidSensors->size(); i++)
		{
			HumidSensors->at(i).UpOneHimid();

			Sleep(2);
		}
		return(true);
	}

	vector <IComponentSensor>* GetSensors()
	{
		return HumidSensors;
	}
};

