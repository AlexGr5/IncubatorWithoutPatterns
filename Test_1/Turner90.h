#pragma once
#include "Flipper.h"

class Turner90 : public RefinemenetElement
{
public:
	Turner90(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper) {}

	// ����������� ����
	bool FlipperOn()
	{
		iFlipperDecorator->FlipperOn();
		iFlipperDecorator->FlipperOn();
		cout << "______________________________________" << endl;
		cout << "���� ������� ��������� �� 90 ��������!" << endl;

		return(true);
	}
};

