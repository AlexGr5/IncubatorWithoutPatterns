#include "Ventilation.h"

Ventilation::Ventilation()
{
	;
}

// Проветрить
bool Ventilation::PerfomAction()
{
	//cout << "Успешно проветрено!" << endl;
	Sleep(10);
	
	return(true);
}