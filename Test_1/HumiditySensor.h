#pragma once
#include "TemperatureSensorC0.h"

// ����������� ����� ������� ���������
class HumiditySensor {
protected:
	double Value;

public:
	virtual double readHumidity() = 0;
	virtual ~HumiditySensor() {}
};

// ���������� ������� ��������� �� ������ ������� 1
class Sensor1 : public HumiditySensor {
public:
	double readHumidity() override {
		// ��������� � ������� 1
		return 50.0; 
	}
};

// ���������� ������� ��������� �� ������ ������� 2
class Sensor2 : public HumiditySensor {
public:
	double readHumidity() override {
		// ��������� � ������� 2
		return 60.0;
	}
};

// ����� "����������" �������� ���������
class HumiditySensors {
public:
	void addSensor(HumiditySensor* sensor) {
		sensors.push_back(sensor);
	}

	double readHumidity() {
		double totalHumidity = 0.0;
		for (HumiditySensor* sensor : sensors) {
			totalHumidity += sensor->readHumidity();
		}
		return totalHumidity / sensors.size();
	}

private:
	std::vector<HumiditySensor*> sensors;
};