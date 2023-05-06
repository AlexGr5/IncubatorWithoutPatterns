#pragma once
#include "Humidifier.h"


// ���������� ����������
class Ventilation
{
protected:
	string info;

public:
	Ventilation() {}

	void SetInfo(string s) { info = s; }

	// ����������
	bool VentilationOn()
	{
		//cout << "������� ����������!" << endl;
		cout << "����������: " << info << endl;
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

	virtual void BuildVentel() { ventilation->SetInfo("�� ����"); }
};


class BuildVentOut : public VentBuilder
{
public:
	BuildVentOut() : VentBuilder() {}

	virtual void BuildVentel() { ventilation->SetInfo("�� �����"); }
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