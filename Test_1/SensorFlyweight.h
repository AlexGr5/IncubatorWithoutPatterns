#pragma once
#include "TemperatureSensorC0.h"

class SensorFlyweight
{
protected:
	double value;
    int pos;

public:
    SensorFlyweight();

	SensorFlyweight(int pos) { this->pos = pos; }

	virtual void UpOnePercent() = 0;

    virtual double GetTemperature() = 0;

    virtual void SetAverageTemp(double temperaature) = 0;

    virtual void DownZeroOneTemp() = 0;

    // Сгенерировать температуру для имитации работы датчика
    double GenericTemperatureC0(double min, double max)
    {
        return (RandomNumbers::GetRandomDouble(min, max));
    }
};


class TemperatureSensor1 : public SensorFlyweight
{
public:
    
    TemperatureSensor1(int pos) : SensorFlyweight(pos) {}

    TemperatureSensor1()
    {
        value = 37.5;
    }

    TemperatureSensor1(double temperaature)
    {
        value = temperaature;
    }

    // Установить среднюю температуру датчика
    virtual void SetAverageTemp(double temperaature)
    {
        value = temperaature;
    }

    // Получить температуру с датчика
    virtual double GetTemperature()
    {
        cout << "Датчик температуры типа 1" << endl;
        return(this->GenericTemperatureC0(value - 0.3, value + 0.3)); // Эмитируем работу датчиков
    }

    // Повысить температуру на 0.1 градус
    virtual void UpOnePercent()
    {
        value += 0.1;
    }

    // Понизить температуру на 0.1 градус
    virtual void DownZeroOneTemp()
    {
        value -= 0.1;
    }
};


class TemperatureSensor2 : public SensorFlyweight
{
public:

    TemperatureSensor2(int pos) : SensorFlyweight(pos) {}

    TemperatureSensor2()
    {
        value = 37.5;
    }

    TemperatureSensor2(double temperaature)
    {
        value = temperaature;
    }

    // Установить среднюю температуру датчика
    virtual void SetAverageTemp(double temperaature)
    {
        value = temperaature;
    }

    // Получить температуру с датчика
    virtual double GetTemperature()
    {
        cout << "Датчик температуры типа 2" << endl;
        return(this->GenericTemperatureC0(value - 0.3, value + 0.3)); // Эмитируем работу датчиков
    }

    // Повысить температуру на 0.1 градус
    virtual void UpOnePercent()
    {
        value += 0.1;
    }

    // Понизить температуру на 0.1 градус
    void DownZeroOneTemp()
    {
        value -= 0.1;
    }
};


class Factory
{
protected:

    typedef std::map<int, SensorFlyweight*> SensorsA;

    SensorsA mSensorA;

public:

    SensorFlyweight* getSensor(int inPos) {
        cout << inPos << "->";
        SensorsA::const_iterator it = mSensorA.find(inPos);
        if (mSensorA.end() == it) {
            cout << "new - ";

            SensorFlyweight* f;
            if (inPos % 2)
                f = new TemperatureSensor1(inPos);
            else
                f = new TemperatureSensor2(inPos);
            mSensorA[inPos] = f;
            return f;
        }
        else {
            cout << "return - ";
            return it->second;
        }
    }
};