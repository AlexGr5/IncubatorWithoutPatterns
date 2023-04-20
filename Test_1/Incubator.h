#pragma once
#include "InterfaceIncubator.h"

class Incubator : public InterfaceIncubator
{
private:

	// Текущий тип яиц
	EggType* CurrentEggType;

	//=====================

	Turner45* CurrentTurner45;
	Turner90* CurrentTurner90;
	Flipper *CurrentFlipper;
	Ventilation *CurrentVentilation;

	Humidifier* CurrentHumidifier;
	Heater* CurrentHeater;

	Sensors *CurrentSensors;

public:

	Incubator();

	Incubator(EggType* eggType, Turner45* turner45,
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	void SetIncubator(EggType* eggType, Turner45* turner45,
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	// Инкубирование
	bool Incubation();

	void SetEggType(EggType* eggType);

	void SetFlipper(Turner45* turner45);
	void SetFlipper(Flipper* flipper);
	void SetVentilation(Ventilation* ventilation);
	void SetHumidifier(Humidifier* humidifier);
	void SetHeater(Heater* heater);
	void SetSensors(Sensors* sensors);

};

