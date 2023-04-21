#pragma once
#include "RefinemenetElement.h"

class Flipper : public RefinemenetElement
{

public:
	
	Flipper(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper){}

	// ѕеревернуть €йца
	bool FlipperOn()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		iFlipperDecorator->FlipperOn();
		cout << " + дополнительно наклон на 135 градусов" << endl;
		cout << "»того:__________________________________" << endl;
		cout << "яйца успешно ѕеревернуты (наклон на180)!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		return(true);
	}

};

