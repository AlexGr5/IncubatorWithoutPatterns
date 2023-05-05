#pragma once
#include "Humidifier.h"

class DevicePrototype
{
protected:
	string info;

public:

	DevicePrototype() {}

	//DevicePrototype(string Info) { info = Info; }

	DevicePrototype(const DevicePrototype* dp) 
	{
		info = dp->info;
	}

	virtual DevicePrototype* Clone() = 0;

	//string GetInfo() { return info; }
	//void SetInfo(string s) { info = s; }

	bool PowerOn()
	{
		cout << "����������: " << info << endl;
		return true;
	}
};

// ���������� ����������
class Ventilation : public DevicePrototype
{
public:
	//Ventilation() : DevicePrototype () {}

	Ventilation() : DevicePrototype() 
	{ 
		info = "����� ����������"; 
		cout << "<" << info << ">" << endl; 
	}

	/*
	// ����������
	bool VentilationOn()
	{
		//cout << "������� ����������!" << endl;

		cout << "����������: " << info << endl;
		Sleep(10);

		return(true);
	}
	*/

	DevicePrototype* Clone()
	{
		return new Ventilation(*this);
	}
};


class Flipper : public DevicePrototype
{

public:

	Flipper() : DevicePrototype() 
	{
		info = "����� ����������������";
		cout << "<" << info << ">" << endl;
	}

	//Flipper() : DevicePrototype() { info = "�����"; }

	/*
	// ����������� ����
	bool FlipperOn()
	{
		//cout << "���� ������� �����������!" << endl;
		Sleep(10);

		return(true);
	}
	*/

	DevicePrototype* Clone()
	{
		return new Flipper(*this);
	}

};

class VentelationExtrime : public Ventilation
{
public:

	VentelationExtrime() : Ventilation() 
	{ 
		info = "���������� ����������!"; 
		cout << "<" << info << ">" << endl;
	}

	DevicePrototype* Clone() { return new VentelationExtrime(*this); }
};

class Flipper90 : public Flipper
{
public:
	Flipper90() : Flipper()
	{
		info = "���������������� ��� �� 90 ��������!";
		cout << "<" << info << ">" << endl;
	}

	DevicePrototype* Clone() { return new Flipper90(*this); }
};