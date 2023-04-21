#pragma once
#include "RefinemenetElement.h"

class Flipper : public RefinemenetElement
{

public:
	
	Flipper(IFlipper* NewIflipper) : RefinemenetElement(NewIflipper){}

	// ����������� ����
	bool FlipperOn()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		iFlipperDecorator->FlipperOn();
		cout << " + ������������� ������ �� 135 ��������" << endl;
		cout << "�����:__________________________________" << endl;
		cout << "���� ������� ����������� (������ ��180)!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		return(true);
	}

};

