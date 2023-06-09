#pragma once
#include "InterfaceIncubator.h"

class Incubator : public InterfaceIncubator
{
private:

	// ������� ��� ���
	EggType* CurrentEggType;

	//=====================

	Flipper *CurrentFlipper;
	Ventilation *CurrentVentilation;

	Humidifier* CurrentHumidifier;
	Heater* CurrentHeater;

	Sensors *CurrentSensors;

public:

	Incubator();

	Incubator(EggType* eggType, Flipper* flipper, 
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	void SetIncubator(EggType* eggType, Flipper* flipper,
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	// �������������
	bool Incubation();

	void SetEggType(EggType* eggType);

	void SetFlipper(Flipper* flipper);
	void SetVentilation(Ventilation* ventilation);
	void SetHumidifier(Humidifier* humidifier);
	void SetHeater(Heater* heater);
	void SetSensors(Sensors* sensors);

};

