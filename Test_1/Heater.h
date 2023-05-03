#pragma once
//#include "Sensors.h"
#include "ImplementBooster.h"

// �����������
class Heater : public ImplementBooster
{

private:
	// ����� �������� �����������
	vector <TemperatureSensorC0>* TemperSensors;

public:

	Heater();

	void AddSensor(TemperatureSensorC0 tempSensor);

	// ������ �������
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	// ������� ��� ������� �� 0.1 ������
	bool UpOnePercent();

	vector <TemperatureSensorC0>* GetSensors();
};

