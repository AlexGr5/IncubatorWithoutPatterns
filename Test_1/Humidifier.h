#pragma once
#include "Heater.h"

// �����������
class Humidifier
{
private:
	// ����� �������� ���������
	vector <HumiditySensor>* HumidSensors;

public:

	Humidifier();

	void AddSensor(HumiditySensor humidSensor);

	// ������ �������
	void SetHimidSensors(vector <HumiditySensor>* humidSensors);

	// ��������� ��������� ���� �������� �� 1 �������
	bool WarmUpOnePercent();

	vector <HumiditySensor>* GetSensors();
};

