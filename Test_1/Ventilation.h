#pragma once
#include "Humidifier.h"

// Вентиляция инкубатора
class Ventilation
{
public:
	Ventilation();

	// Проветрить
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
				cout << "Нашли свободную вентеляцию в пуле и возвращаем её!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				m_pool[i].in_use = true; // переводим объект в список используемых
				return m_pool[i].instance;
			}
		}
		// если не нашли свободный объект, то расширяем пул
		PoolRecord record;
		record.instance = new Ventilation;
		record.in_use = true;

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Не нашли свободную вентеляцию в пуле, создаем новый объект!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		m_pool.push_back(record);

		return record.instance;
	}

	void Down(Ventilation* ventelation)
	{
		// помечаем, что объект свободен
		for (size_t i = 0; i < m_pool.size(); ++i)
		{
			if (m_pool[i].instance == ventelation)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Убираем вентеляцию в пул!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				m_pool[i].in_use = false;
				break;
			}
		}
	}


	virtual ~VentPool()
	{
		//  удаляем объекты
		for (size_t i = 0; i < m_pool.size(); ++i)
			delete m_pool[i].instance;
	}
};

