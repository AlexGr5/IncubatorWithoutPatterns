#pragma once
#include "Heater.h"

// �����������
class Humidifier : public ImplementBooster
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
	bool UpOnePercent();

	vector <HumiditySensor>* GetSensors();
};

