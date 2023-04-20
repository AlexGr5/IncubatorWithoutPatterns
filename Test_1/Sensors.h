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

public:

	Sensors();

	// ������ �������
	void SetHimidSensors(vector <HumiditySensor>* humidSensors);

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

