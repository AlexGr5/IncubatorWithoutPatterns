#pragma once
#include "Flipper.h"

class Turner90 : public RefinemenetElement
{
public:
	Turner90(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper) {}

	// ѕеревернуть €йца
	bool FlipperOn()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		iFlipperDecorator->FlipperOn();
		cout << " + дополнительно наклон на 45 градусов" << endl;
		cout << "»того:________________________________" << endl;
		cout << "яйца успешно наклонены на 90 градусов!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		return(true);
	}
};

