#pragma once
#include "IFlipper.h"

class Turner45 : public IFlipper
{
public:
	bool FlipperOn()
	{
		cout << "���� ������� ��������� �� 45 ��������!" << endl;
		Sleep(10);

		return(true);
	}
};

