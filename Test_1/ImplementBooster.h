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
		cout << "��������� ����������� �������� ������ ���������! <Abstract>" << endl;

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
		cout << "��������� ������ ���������! <BoosterHumidity>" << endl;

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
		cout << "����������� ������ ���������! <BoosterTemperature>" << endl;

		impl->UpOnePercent();

		return true;
	}
};
