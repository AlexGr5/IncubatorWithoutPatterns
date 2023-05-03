#pragma once
//#include "Humidifier.h"
#include "Facade.h"

// Вентиляция инкубатора
class Ventilation : public Facade
{
public:
	Ventilation();

	// Проветрить
	virtual bool PerfomAction();
};

