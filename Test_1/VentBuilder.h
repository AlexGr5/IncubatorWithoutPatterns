#pragma once
#include "Humidifier.h"


// Вентиляция инкубатора
class Ventilation
{
protected:
	string info;

public:
	Ventilation() {}

	void SetInfo(string s) { info = s; }

	// Проветрить
	bool VentilationOn()
	{
		//cout << "Успешно проветрено!" << endl;
		cout << "Вентеляция: " << info << endl;
		Sleep(10);

		return(true);
	}
};


class VentBuilder
{
protected:
	Ventilation* ventilation;

public:
	VentBuilder() {}

	Ventilation* GetVentel() { return ventilation; }

	void createNewVentelation() { ventilation = new Ventilation(); }

	virtual void BuildVentel() = 0;
};


class BuildVentIn : public VentBuilder
{
public:
	BuildVentIn() : VentBuilder() {}

	virtual void BuildVentel() { ventilation->SetInfo("на вдув"); }
};


class BuildVentOut : public VentBuilder
{
public:
	BuildVentOut() : VentBuilder() {}

	virtual void BuildVentel() { ventilation->SetInfo("на выдув"); }
};


// Director
class Director
{
private:
	VentBuilder* ventBuilder;
public:
	Director() : ventBuilder(nullptr) {}
	~Director() { }

	void SetVentelBuilder(VentBuilder* b) { ventBuilder = b; }
	Ventilation* GetVentel() { return ventBuilder->GetVentel(); }
	void ConstructVentel()
	{
		ventBuilder->createNewVentelation();
		ventBuilder->BuildVentel();
	}
};