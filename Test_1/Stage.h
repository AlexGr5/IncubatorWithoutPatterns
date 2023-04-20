#pragma once
#include "InterfaceStage.h"


class Stage
{

public:
	Stage();

	void SetStage(double timeStageOfMilliSec,
		int countFlips, int countVentilations,
		double minTemerature, double maxTemerature,
		double minHumidity, double maxHumidity);

private:

	// ����������� ���������� � �����������
	DEF(double, TimeStageOfMilliSec);

	// ���������� �����������
	DEF(int, CountFlips);

	// ���������� �������������
	DEF(int, CountVentilations);

	// ����������� � ������������ �����������
	DEF(double, MinTemerature);
	DEF(double, MaxTemerature);

	// ����������� � ������������ ���������
	DEF(double, MinHumidity);
	DEF(double, MaxHumidity);

};

