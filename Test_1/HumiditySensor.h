#pragma once
#include "TemperatureSensorC0.h"

// Абстрактный класс датчика влажности
class HumiditySensor {
protected:
	double Value;

public:
	virtual double readHumidity() = 0;
	virtual ~HumiditySensor() {}
};

// Реализация датчика влажности на основе сенсора 1
class Sensor1 : public HumiditySensor {
public:
	double readHumidity() override {
		// влажность с датчика 1
		return 50.0; 
	}
};

// Реализация датчика влажности на основе сенсора 2
class Sensor2 : public HumiditySensor {
public:
	double readHumidity() override {
		// влажность с датчика 2
		return 60.0;
	}
};

// Класс "комоновщик" датчиков влажности
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