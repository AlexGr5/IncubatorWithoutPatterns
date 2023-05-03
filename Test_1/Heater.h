#pragma once
#include "CountTimeUpTemp.h"

// �����������
class Heater
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
	bool WarmUpZeroOneDegreeC0();

	vector <TemperatureSensorC0>* GetSensors();
};

