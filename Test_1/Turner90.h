#pragma once
#include "Flipper.h"

class Turner90 : public RefinemenetElement
{
public:
	Turner90(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper) {}

	// ѕеревернуть €йца
	bool FlipperOn()
	{
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		cout << "______________________________________" << endl;
		cout << "яйца успешно наклонены на 90 градусов!" << endl;

		return(true);
	}
};

