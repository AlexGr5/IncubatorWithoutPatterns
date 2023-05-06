// Test_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>

#include "Incubator.h"

int main()
{
    system("chcp 1251");
    system("cls");

    TemperatureSensorC0 T1(32.1);
    TemperatureSensorC0 T2(32.2);
    TemperatureSensorC0 T3(32.3);
    TemperatureSensorC0 T4(32.4);
    TemperatureSensorC0 T5(32.2);

    HumiditySensor H1(31);
    HumiditySensor H2(32);
    HumiditySensor H3(33);
    HumiditySensor H4(34);
    HumiditySensor H5(32);

    Heater* Heater1 = new Heater();
    Heater1->AddSensor(T1);
    Heater1->AddSensor(T2);
    Heater1->AddSensor(T3);
    Heater1->AddSensor(T4);
    Heater1->AddSensor(T5);

    Humidifier* Humidefier1 = new Humidifier();
    Humidefier1->AddSensor(H1);
    Humidefier1->AddSensor(H2);
    Humidefier1->AddSensor(H3);
    Humidefier1->AddSensor(H4);
    Humidefier1->AddSensor(H5);

    Ventilation* V1 = new Ventilation();
    Flipper* F1 = new Flipper();

    Sensors* S1 = new Sensors();
    S1->SetHimidSensors(Humidefier1->GetSensors());
    S1->SetTempSensors(Heater1->GetSensors());

    Stage St1;
    Stage St2;
    St1.SetStage(15000, 3, 3, 35.1, 36.1, 40, 50);
    St2.SetStage(15000, 3, 3, 36.0, 37.0, 50, 80);

    EggType* EgT1 = new EggType("Куриные");
    EgT1->AppendStage(St1);
    EgT1->AppendStage(St2);

    //===================================================
    Director director;

    BuildVentIn ventIn;
    director.SetVentelBuilder(&ventIn);
    director.ConstructVentel();
    Ventilation* ventelation = director.GetVentel();
    //===================================================

    Incubator Incub1;

    Incub1.SetIncubator(EgT1, F1, ventelation, Humidefier1, Heater1, S1);

    Incub1.Incubation();
}

