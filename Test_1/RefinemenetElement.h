#pragma once
#include "Turner45.h"

class RefinemenetElement : public IFlipper
{
protected:
	IFlipper* iFlipperDecorator;	// ƒекорируемый объект

public:

	// ѕеревернуть €йца
	virtual bool FlipperOn() = 0;

	RefinemenetElement(IFlipper* newItem)
	{
		iFlipperDecorator = newItem;
	}
};

