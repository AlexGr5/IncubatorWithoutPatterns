#include "TemperatureSensorC0.h"

TemperatureSensorC0::TemperatureSensorC0()
{
    AverageTemperature = 37.5;
}

TemperatureSensorC0::TemperatureSensorC0(double temperaature)
{
    AverageTemperature = temperaature;
}

// ���������� ������� ����������� �������
void TemperatureSensorC0::SetAverageTemp(double temperaature)
{
    AverageTemperature = temperaature;
}

// �������� ����������� � �������
double TemperatureSensorC0::GetTemperatureC0()
{
    return(this->GenericTemperatureC0(AverageTemperature - 0.3, AverageTemperature + 0.3)); // ��������� ������ ��������
}

// ������������� ����������� ��� �������� ������ �������
double TemperatureSensorC0::GenericTemperatureC0(double min, double max)
{
    return (RandomNumbers::GetRandomDouble(min, max));
}

// �������� ����������� �� 0.1 ������
void TemperatureSensorC0::UpZeroOneTemp()
{
    AverageTemperature += 0.1;
}

// �������� ����������� �� 0.1 ������
void TemperatureSensorC0::DownZeroOneTemp()
{
    AverageTemperature -= 0.1;
}