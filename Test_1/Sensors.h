#pragma once
#include "HumiditySensor.h"


// ������� ����������� � ���������
// � ������ ������ � ����� ��� � ����� �����
class Sensors
{
private:

	// ����� �������� �����������
	typedef aggregate<TemperatureSensorC0> myContainer;
	myContainer* data;

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


	void AddTempSensor(TemperatureSensorC0 tempSensor)
	{
		data->push(tempSensor);
	}

	void SetConteiner(myContainer* cont)
	{
		data = cont;
	}
};

