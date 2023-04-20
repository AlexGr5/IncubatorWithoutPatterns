#pragma once
#include "HumiditySensor.h"
#include "Heater.h"

// �����������
class Humidifier : public IComponentSensor
{
protected:
	// ����� �������� ���������
	vector <IComponentSensor>* HumidSensors;

public:

	Humidifier()
	{
		HumidSensors = new vector <IComponentSensor>();
	}

	// ������ �������
	void SetHimidSensors(vector <IComponentSensor>* humidSensors)
	{
		HumidSensors = humidSensors;
	}

	IComponentSensor GetI(int i)
	{
		if (i > 0 && i < HumidSensors->size())
			return HumidSensors->at(i);
	}

	// ������� ������ ������ ��������
	int GetSize()
	{
		return HumidSensors->size();
	}

	void AddSensor(HumiditySensor humidSensor)
	{
		HumidSensors->push_back(humidSensor);
	}

	// ��������� ��������� ���� �������� �� 1 �������
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

