#include "Incubator.h"

Incubator::Incubator()
{
	CurrentEggType = new EggType();
	CurrentFlipper = new Flipper();
	CurrentVentilation = new Ventilation();
	CurrentHumidifier = new Humidifier();
	CurrentHeater = new Heater();
	CurrentSensors = new Sensors();
}

Incubator::Incubator(EggType* eggType, Flipper* flipper,
	Ventilation* ventilation, Humidifier* humidifier,
	Heater* heater, Sensors* sensors)
{
	CurrentEggType = eggType;
	CurrentFlipper = flipper;
	CurrentVentilation = ventilation;
	CurrentHumidifier = humidifier;
	CurrentHeater = heater;
	CurrentSensors = sensors;

}

void Incubator::SetIncubator(EggType* eggType, Flipper* flipper,
	Ventilation* ventilation, Humidifier* humidifier,
	Heater* heater, Sensors* sensors)
{
	CurrentEggType = eggType;
	CurrentFlipper = flipper;
	CurrentVentilation = ventilation;
	CurrentHumidifier = humidifier;
	CurrentHeater = heater;
	CurrentSensors = sensors;
}


std::wstring LargeIntToString(const LARGE_INTEGER& li)
{
	std::wstringstream wss;
	wss << hex << setw(16) << setfill(L'0') << li.QuadPart;
	return wss.str();
}


// Инкубирование
bool Incubator::Incubation()
{
	vector <Stage> Stages = CurrentEggType->GetStages();

	Stage CurrentStage = Stage();

	if (Stages.size() > 0)
	{

		cout << "--------------------------------------------" << endl;
		cout << "Процесс инкубирования начался!" << endl;
		cout << endl;

		cout << "Тип инкубируемых яиц: " << CurrentEggType->GetName() << endl;
		cout << "--------------------------------------------" << endl;

		for (int i = 0; i < Stages.size(); i++)
		{
			cout << endl;
			cout << "_______________________________" << endl;
			cout << "СТАДИЯ №" << to_string(i+1) << " из " << to_string(Stages.size()) << endl;
			cout << "_______________________________" << endl;
			cout << endl;

			CurrentStage = Stages.at(i);

			volatile DWORD tStart;          // Для начального кол-ва тиков
			double TimeStart = 0;           // Начальное время в милисекундах
			tStart = GetTickCount();        // фиксируем начальное количество тиков до старта  пар.ветки
			TimeStart = omp_get_wtime();    // запрашиваем время в миллисекундах
			double CurrentTime = 0;


			//CurrentTime = omp_get_wtime();
			TimeStart = GetTickCount();
			CurrentTime = GetTickCount();

			//cout << "Заданное время стадии = " << to_string(CurrentStage.get_TimeStageOfMilliSec()) 
			//	<< ", разница старта и начала " << to_string(CurrentTime - TimeStart) << endl;

			int CoeffFlips = CurrentStage.get_TimeStageOfMilliSec() / (CurrentStage.get_CountFlips() + 1);
			int CoeffVentilations = CurrentStage.get_TimeStageOfMilliSec() / (CurrentStage.get_CountVentilations() + 1);
			double timeToFlips = GetTickCount();
			double timeToVentilations = GetTickCount();

			cout << "====================================================================" << endl;
			while (CurrentStage.get_TimeStageOfMilliSec() >= (CurrentTime - TimeStart))
			{
				if (CurrentSensors->MinTemperature() < CurrentStage.get_MinTemerature())
				{
					cout << " Минимальная текущая температура = " << to_string(CurrentSensors->MinTemperature()) 
						<< " ниже допустимой = " << to_string(CurrentStage.get_MinTemerature()) << endl;

					cout << "Происходит нагрев..." << endl;
					while (CurrentSensors->MaxTemperature() < CurrentStage.get_MaxTemerature())
					{
						CurrentHeater->WarmUpZeroOneDegreeC0();
					}
					cout << "Нагрев завершён!" << endl;
					cout << endl;
				}

				if (CurrentSensors->MinHummidity() < CurrentStage.get_MinHumidity())
				{
					cout << " Минимальная текущая Влажность = " << to_string(CurrentSensors->MinHummidity())
						<< " ниже допустимой = " << to_string(CurrentStage.get_MinHumidity()) << endl;

					cout << "Происходит увлажнение..." << endl;
					while (CurrentSensors->MaxHummidity() < CurrentStage.get_MaxHumidity())
					{
						CurrentHumidifier->WarmUpOnePercent();
					}
					cout << "Увлажнение завершёно!" << endl;
					cout << endl;
				}

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
				if (int (CurrentTime - timeToVentilations) > CoeffVentilations)
				{
					timeToVentilations = CurrentTime;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Пора провентилировать!" << endl;
					CurrentVentilation->VentilationOn();
					CurrentVentilation->setState(CurrentVentilation->getState() + 10);
					cout << "Вентиляция закончена!" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << endl;
				}

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
				if (int(CurrentTime - timeToFlips) > CoeffFlips)
				{
					timeToFlips = CurrentTime;
					cout << "Пора перевернуть яйца!" << endl;
					CurrentFlipper->FlipperOn();
					cout << "Яйца перевернуты!" << endl;
					cout << endl;
				}

				// Эмитация потерь инкубатора
				CurrentSensors->Poteri();
				cout << "Произошли естественные потери Температуры и Влажности!" << endl;
				cout << "______________________________________________________" << endl;

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
			}
			cout << "====================================================================" << endl;
			cout << endl;
			cout << endl;
		}
		

		cout << "**********************************************************" << endl;
		cout << "Инкубация яиц типа " << CurrentEggType->GetName() << " успешно завершена!" << endl;
		cout << "**********************************************************" << endl;
		cout << endl;
		cout << endl;

		return 0;
	}
	else
		return 1;
	
}

void Incubator::SetEggType(EggType* eggType)
{
	CurrentEggType = eggType;
}

void Incubator::SetFlipper(Flipper* flipper)
{
	CurrentFlipper = flipper;
}

void Incubator::SetVentilation(Ventilation* ventilation)
{
	CurrentVentilation = ventilation;
}

void Incubator::SetHumidifier(Humidifier* humidifier)
{
	CurrentHumidifier = humidifier;
}

void Incubator::SetHeater(Heater* heater)
{
	CurrentHeater = heater;
}

void Incubator::SetSensors(Sensors* sensors)
{
	CurrentSensors = sensors;
}

