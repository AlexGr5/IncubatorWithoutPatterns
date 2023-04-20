#include "Stage.h"

Stage::Stage()
{
	TimeStageOfMilliSec = 5000;

	CountFlips = 2;

	CountVentilations = 2;

	MinTemerature = 36.5;
	MaxTemerature = 38.5;

	MinHumidity = 45;
	MaxHumidity = 60;

}

void Stage::SetStage(double timeStageOfMilliSec,
	int countFlips, int countVentilations,
	double minTemerature, double maxTemerature,
	double minHumidity, double maxHumidity)
{
	TimeStageOfMilliSec = timeStageOfMilliSec;

	CountFlips = countFlips;

	CountVentilations = countVentilations;

	MinTemerature = minTemerature;
	MaxTemerature = maxTemerature;

	MinHumidity = minHumidity;
	MaxHumidity = maxHumidity;
}