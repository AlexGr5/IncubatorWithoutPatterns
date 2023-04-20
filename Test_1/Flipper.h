#pragma once
#include "RefinemenetElement.h"

class Flipper : public RefinemenetElement
{

public:
	
	Flipper(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper){}

	// ѕеревернуть €йца
	bool FlipperOn()
	{
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		cout << "_______________________________" << endl;
		cout << "яйца успешно ѕеревернуты (180)!" << endl;

		return(true);
	}

};

