#pragma once
#include "RefinemenetElement.h"

class Flipper : public RefinemenetElement
{

public:
	
	Flipper(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper){}

	// ����������� ����
	bool FlipperOn()
	{
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		cout << "_______________________________" << endl;
		cout << "���� ������� ����������� (180)!" << endl;

		return(true);
	}

};

