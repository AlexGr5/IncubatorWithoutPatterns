#pragma once
#include "Humidifier.h"

class Device
{
public:
	virtual bool DeviceOn() = 0;
};

// ���������� ����������
class Ventilation : public Device
{
public:
	Ventilation() {}

	// ����������
	virtual bool DeviceOn()
	{
		//cout << "������� ����������!" << endl;
		Sleep(10);

		return(true);
	}
};

class Flipper : public Device
{

public:
	Flipper() {}

	// ����������� ����
	virtual bool DeviceOn()
	{
		//cout << "���� ������� �����������!" << endl;
		Sleep(10);

		return(true);
	}

};



class FctoryMethod
{
protected:
	//Device* deviceElem;

public:
	FctoryMethod() {}

	virtual Device* CreateDevice() = 0;

	Device* CloneDevice(Device* a)
	{
		return this->CreateDevice();
	}
};


class FlipObject : public FctoryMethod
{
public:

	FlipObject() : FctoryMethod() {}

	virtual Flipper* CreateDevice()
	{
		return new Flipper();
	}
};


class VentelObject : public FctoryMethod
{
public:

	VentelObject() : FctoryMethod() {}

	virtual Ventilation* CreateDevice()
	{
		return new Ventilation();
	}
};