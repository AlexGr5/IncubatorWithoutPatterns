#pragma once
#include "Sensors.h"

class CountTimeUpTemp
{
protected:
	Sensors* sens;

	int myTime;

public:
	CountTimeUpTemp(Sensors* sens1) { sens = sens1; }

	int CountTime(double sravnTime)
	{
		int res = 0;
		if (sens->MinTemperature() < sravnTime)
		{
			res = int((sravnTime - sens->MinTemperature()) * 5);
		}
		
		return res;
	}

};

