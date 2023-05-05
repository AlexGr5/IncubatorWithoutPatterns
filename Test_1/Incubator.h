#pragma once
#include "InterfaceIncubator.h"

class Incubator : public InterfaceIncubator
{
private:

	// Текущий тип яиц
	EggType* CurrentEggType;

	//=====================

	//Flipper *CurrentFlipper;
	//Ventilation *CurrentVentilation;

	Humidifier* CurrentHumidifier;
	Heater* CurrentHeater;

	Sensors *CurrentSensors;

	Device* CurrentFlipper;
	Device* CurrentVentilation;

public:

	Incubator();

	Incubator(EggType* eggType, Flipper* flipper, 
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	void SetIncubator(EggType* eggType, Flipper* flipper,
		Ventilation* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors);

	void SetIncubator(EggType* eggType, Device* flipper,
		Device* ventilation, Humidifier* humidifier,
		Heater* heater, Sensors* sensors)
	{
		CurrentEggType = eggType;
		CurrentFlipper = flipper;
		CurrentVentilation = ventilation;
		CurrentHumidifier = humidifier;
		CurrentHeater = heater;
		CurrentSensors = sensors;
	}

	// Инкубирование
	bool Incubation();

	void SetEggType(EggType* eggType);

	void SetFlipper(Flipper* flipper);
	void SetVentilation(Ventilation* ventilation);
	void SetHumidifier(Humidifier* humidifier);
	void SetHeater(Heater* heater);
	void SetSensors(Sensors* sensors);

};

