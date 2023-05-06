#pragma once
#include "InterfaceEggType.h"

class EggType : public InterfaceEggType
{
private:

	// ����� ������ �������������
	vector <Stage> KitStages;

	// ����� ������� ������
	//int CurrentStageNumber;

	// �������� ���� ���
	DEF(string, NameOfType);

	Memento* tempMemento;

public:

	EggType();

	EggType(string Name);

	// ���������� ����� ������
	void SetKitStages(vector <Stage> kitStages);

	// �������� ������ � ����� ������
	void AppendStage(Stage oneStage);

	// ������� ������ ������
	vector <Stage> GetStages();

	// ������� ��������
	string GetName();

	// �������� �����-�� ������������, � ���������� �������, �������� ���������� ������ KitStages
	void EmitateWork()
	{
		
		if (KitStages.size() > 0)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "������������ ������:" << endl;
			KitStages[0].DisplayStage();

			cout << endl;

			cout << "������� ����� ������ � Memento:" << endl << endl;
			tempMemento = new Memento(KitStages[0].get_TimeStageOfMilliSec(), KitStages[0].get_CountFlips(),
				KitStages[0].get_CountVentilations(), KitStages[0].get_MinTemerature(),
				KitStages[0].get_MaxTemerature(), KitStages[0].get_MinHumidity(), KitStages[0].get_MaxHumidity());

			cout << endl;

			cout << "�����-�� ������������, � ���������� �������, �������� ���������� ������:" << endl;
			KitStages[0].set_CountFlips(10);
			KitStages[0].set_CountVentilations(10);
			KitStages[0].set_MaxHumidity(90);
			KitStages[0].set_MaxTemerature(40);
			KitStages[0].set_MinHumidity(70);
			KitStages[0].set_MinTemerature(30);
			KitStages[0].set_TimeStageOfMilliSec(10000);

			cout << endl;

			cout << "������ ����� ������������:" << endl;
			KitStages[0].DisplayStage();

			cout << endl;

			cout << "�������������� ������" << endl;
			this->Beack();

			cout << endl;

			cout << "��������������� ������:" << endl;
			KitStages[0].DisplayStage();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}

	void Beack()
	{
		if (tempMemento != NULL)
		{
			KitStages[0].set_CountFlips(tempMemento->get_CountFlips());
			KitStages[0].set_CountVentilations(tempMemento->get_CountVentilations());
			KitStages[0].set_MaxHumidity(tempMemento->get_MaxHumidity());
			KitStages[0].set_MaxTemerature(tempMemento->get_MaxTemerature());
			KitStages[0].set_MinHumidity(tempMemento->get_MinHumidity());
			KitStages[0].set_MinTemerature(tempMemento->get_MinTemerature());
			KitStages[0].set_TimeStageOfMilliSec(tempMemento->get_TimeStageOfMilliSec());
		}
	}
};

