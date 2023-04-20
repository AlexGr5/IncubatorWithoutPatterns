#pragma once
#include "Stage.h"

class InterfaceEggType
{

	// ���������� ����� ������
	virtual void SetKitStages(vector <Stage> kitStages) = 0;

	// �������� ������ � ����� ������
	virtual void AppendStage(Stage oneStage) = 0;

	// ������� ������ ������
	virtual vector <Stage> GetStages() = 0;

};

