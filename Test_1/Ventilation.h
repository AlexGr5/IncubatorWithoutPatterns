#pragma once
#include "Humidifier.h"


class Observer {
public:
	virtual void update(int x) = 0; // данные через x в update(x)
};


class IncubatorVisor : public Observer 
{
private:
	int oldState, curState;
	void check() {
		cout << "Мощность вентеляции: " << endl;
		cout << " старая мощьность: " << oldState << " текущая мощность " << curState << endl;
		if (curState > 50)
			cout << "ОСТОРОЖНО! Повышенная мощность!" << endl;
		else
			cout << "ШТАТНЫЙ РЕЖИМ!" << endl;
	}
public:
	void update(int x) {
		oldState = curState;
		if (x > 100)
			curState = 100;
		else
			curState = x;

		if (oldState >= 0) check();
	}
	IncubatorVisor() { curState = -1; }
};


class Subject 
{
protected:
	Observer* myObserver;
public:
	void attach(Observer* a) { myObserver = a; }
	void detach(Observer* a) {
		if (a == myObserver) myObserver = nullptr;
	}
	virtual void notify() = 0;
	Subject() {}
	~Subject() {}
};




// Вентиляция инкубатора
class Ventilation : public Subject
{
private:
	int x;
public:
	Ventilation() { x = 100; }

	// Проветрить
	bool VentilationOn()
	{
		//cout << "Успешно проветрено!" << endl;
		Sleep(10);

		return(true);
	}

	Ventilation(int start) { x = start; }
	~Ventilation() {}

	void notify() { myObserver->update(x); }
	// данные через параметр x в update(x)
	int getState() { return x; }
	void setState(int newX) {
		x = newX;
		notify();
	}
};

