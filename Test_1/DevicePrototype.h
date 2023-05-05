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
		cout << "”стройство: " << info << endl;
		return true;
	}
};

// ¬ентил€ци€ инкубатора
class Ventilation : public DevicePrototype
{
public:
	//Ventilation() : DevicePrototype () {}

	Ventilation() : DevicePrototype() 
	{ 
		info = "обща€ вентел€ци€"; 
		cout << "<" << info << ">" << endl; 
	}

	/*
	// ѕроветрить
	bool VentilationOn()
	{
		//cout << "”спешно проветрено!" << endl;

		cout << "¬ентел€ци€: " << info << endl;
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
		info = "общий переворачиватель";
		cout << "<" << info << ">" << endl;
	}

	//Flipper() : DevicePrototype() { info = "обща€"; }

	/*
	// ѕеревернуть €йца
	bool FlipperOn()
	{
		//cout << "яйца успешно перевернуты!" << endl;
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
		info = "Ёкстренна€ вентел€ци€!"; 
		cout << "<" << info << ">" << endl;
	}

	DevicePrototype* Clone() { return new VentelationExtrime(*this); }
};

class Flipper90 : public Flipper
{
public:
	Flipper90() : Flipper()
	{
		info = "ѕереворачиватель €иц на 90 градусов!";
		cout << "<" << info << ">" << endl;
	}

	DevicePrototype* Clone() { return new Flipper90(*this); }
};