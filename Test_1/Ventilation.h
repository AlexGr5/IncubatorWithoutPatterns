#pragma once
//#include "Humidifier.h"
#include "Facade.h"

// ���������� ����������
class Ventilation : public Facade
{
public:
	Ventilation();

	// ����������
	virtual bool PerfomAction();
};

