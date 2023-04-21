#pragma once
#include "Flipper.h"

class Turner90 : public RefinemenetElement
{
public:
	Turner90(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper) {}

	// ����������� ����
	bool FlipperOn()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		iFlipperDecorator->FlipperOn();
		cout << " + ������������� ������ �� 45 ��������" << endl;
		cout << "�����:________________________________" << endl;
		cout << "���� ������� ��������� �� 90 ��������!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		return(true);
	}
};

