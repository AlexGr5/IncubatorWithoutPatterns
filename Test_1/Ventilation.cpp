#include "Ventilation.h"

Ventilation::Ventilation()
{
	;
}

// Проветрить
bool Ventilation::VentilationOn()
{
	//cout << "Успешно проветрено!" << endl;
	Sleep(10);
	
	return(true);
}