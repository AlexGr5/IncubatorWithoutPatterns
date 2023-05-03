#pragma once
#include "Sensors.h"

class ImplementBooster
{
public:

	virtual bool UpOnePercent() = 0;
};


class BoosterPercentAbstract
{
protected:
	ImplementBooster* impl;

public:
	BoosterPercentAbstract(ImplementBooster* i) { impl = i; }

	virtual bool UpOnePercent()
	{
		cout << "Некоторое абстрактное значение должно повысится! <Abstract>" << endl;

		impl->UpOnePercent();

		return true;
	}
};

class BoosterHumidity : public BoosterPercentAbstract
{
public:
	BoosterHumidity(ImplementBooster* i) : BoosterPercentAbstract(i) {}

	virtual bool UpOnePercent()
	{
		cout << "Влажность должна повысится! <BoosterHumidity>" << endl;

		impl->UpOnePercent();

		return true;
	}
};

class BoosterTemperature : public BoosterPercentAbstract
{
public:
	BoosterTemperature(ImplementBooster* i) : BoosterPercentAbstract(i) {}

	virtual bool UpOnePercent()
	{
		cout << "Температура должна повысится! <BoosterTemperature>" << endl;

		impl->UpOnePercent();

		return true;
	}
};
