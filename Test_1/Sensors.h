#pragma once
#include "HumiditySensor.h"


// ������� ����������� � ���������
// � ������ ������ � ����� ��� � ����� �����
class Sensors
{
private:

	// ����� �������� �����������
	vector <TemperatureSensorC0> *TemperSensors;

	// ����� �������� ���������
	vector <HumiditySensor>* HumidSensors;

	Factory* fact;
	int Size = 0;

public:

	Sensors();

	// ������ �������
	void SetHimidSensors(vector <HumiditySensor>* humidSensors);

	// ������ �������
	void SetFact(Factory* fact1, int size) { fact = fact1; Size = size; }

	// ������ �������
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	double MinTemperature();	// ����� �������� �����������
	double MaxTemperature();	// ����� ��������� �����������
	void SortTemperature();		// ���������� ����������

	double MinHummidity();		// ����� �������� ���������
	double MaxHummidity();		// ����� ��������� ���������
	void SortHumidity();		// ���������� ���������


	bool Poteri();				// �������� ������ ���������� � ���������,
								// ������� ���������� � ��������� ����������

};

