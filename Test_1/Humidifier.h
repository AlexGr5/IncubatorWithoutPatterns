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



	// Поиск минимума влажности
	double MinHummidity()
	{
		if (HumidSensors->size() > 0)
		{
			double minimum = HumidSensors->at(0).GetValue();
			for (int i = 0; i < HumidSensors->size(); i++)
			{
				if (HumidSensors->at(i).GetValue() < minimum)
					minimum = HumidSensors->at(i).GetValue();
			}

			return(minimum);
		}
		else
			return (-999);
	}

	// Поиск максимума влажности
	double MaxHummidity()
	{
		if (HumidSensors->size() > 0)
		{
			double maximum = HumidSensors->at(0).GetValue();
			for (int i = 0; i < HumidSensors->size(); i++)
			{
				if (HumidSensors->at(i).GetValue() > maximum)
					maximum = HumidSensors->at(i).GetValue();
			}

			return(maximum);
		}
		else
			return (999);
	}
};

