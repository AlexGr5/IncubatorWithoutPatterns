#pragma once
#include "IFlipper.h"

class Turner45 : public IFlipper
{
public:
	bool FlipperOn()
	{
		cout << "яйца успешно повернуты на 45 градусов!" << endl;
		Sleep(10);

		return(true);
	}
};

