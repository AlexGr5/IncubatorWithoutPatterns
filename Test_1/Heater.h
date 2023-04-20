#pragma once
#include "Sensors.h"

// Нагреватель
class Heater
{

private:
	// Набор сенсоров температуры
	//vector <TemperatureSensorC0>* TemperSensors;

	typedef aggregate<TemperatureSensorC0> myContainer;
	myContainer  *data;

public:

	Heater()
	{
		data = new myContainer();
	}

	void AddSensor(TemperatureSensorC0 tempSensor)
	{
		data->push(tempSensor);
	}

	// Нагреть все датчики на 0.1 градус
	bool WarmUpZeroOneDegreeC0()
	{

		for (myContainer::myIterator it = data->begin(); it != data->end(); ++it) {
			it.next()->UpZeroOneTemp();
			
			Sleep(2);
		}
		
		return(true);
	}

	myContainer* GetConteiner()
	{
		return data;
	}
};

