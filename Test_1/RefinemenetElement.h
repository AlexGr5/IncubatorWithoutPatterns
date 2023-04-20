#pragma once
#include "Turner45.h"

class RefinemenetElement : public IFlipper
{
protected:
	IFlipper* iFlipperDecorator;	// ������������ ������

public:

	// ����������� ����
	virtual bool FlipperOn() = 0;

	RefinemenetElement(IFlipper* newItem)
	{
		iFlipperDecorator = newItem;
	}
};

