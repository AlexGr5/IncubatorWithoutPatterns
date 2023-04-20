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



	// ����� �������� ���������
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

	// ����� ��������� ���������
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

