#pragma once
#include "Sensors.h"

// �����������
class Heater
{

private:
	// ����� �������� �����������
	vector <TemperatureSensorC0>* TemperSensors;
	Factory* fact;
	int Size;

public:

	Heater();

	void AddSensor(TemperatureSensorC0 tempSensor);

	// ������ �������
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	void SetFactory(Factory* fact1, int size) { fact = fact1; Size = size; }

	// ������� ��� ������� �� 0.1 ������
	bool WarmUpZeroOneDegreeC0();

	vector <TemperatureSensorC0>* GetSensors();
};

