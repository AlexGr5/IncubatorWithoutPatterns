#pragma once
#include "Humidifier.h"

// ���������� ����������
class Ventilation
{
public:
	Ventilation();

	// ����������
	bool VentilationOn();
};

class VentPool
{
private:

	struct PoolRecord
	{
		Ventilation* instance;
		bool    in_use;
	};

	std::vector<PoolRecord> m_pool;

public:
	VentPool() {}

	Ventilation* Take()
	{
		for (size_t i = 0; i < m_pool.size(); ++i)
		{
			if (!m_pool[i].in_use)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "����� ��������� ���������� � ���� � ���������� �!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				m_pool[i].in_use = true; // ��������� ������ � ������ ������������
				return m_pool[i].instance;
			}
		}
		// ���� �� ����� ��������� ������, �� ��������� ���
		PoolRecord record;
		record.instance = new Ventilation;
		record.in_use = true;

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "�� ����� ��������� ���������� � ����, ������� ����� ������!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		m_pool.push_back(record);

		return record.instance;
	}

	void Down(Ventilation* ventelation)
	{
		// ��������, ��� ������ ��������
		for (size_t i = 0; i < m_pool.size(); ++i)
		{
			if (m_pool[i].instance == ventelation)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "������� ���������� � ���!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				m_pool[i].in_use = false;
				break;
			}
		}
	}


	virtual ~VentPool()
	{
		//  ������� �������
		for (size_t i = 0; i < m_pool.size(); ++i)
			delete m_pool[i].instance;
	}
};

