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


// �������������
bool Incubator::Incubation()
{
	vector <Stage> Stages = CurrentEggType->GetStages();

	Stage CurrentStage = Stage();

	if (Stages.size() > 0)
	{

		cout << "--------------------------------------------" << endl;
		cout << "������� ������������� �������!" << endl;
		cout << endl;

		cout << "��� ������������ ���: " << CurrentEggType->GetName() << endl;
		cout << "--------------------------------------------" << endl;

		for (int i = 0; i < Stages.size(); i++)
		{
			cout << endl;
			cout << "_______________________________" << endl;
			cout << "������ �" << to_string(i+1) << " �� " << to_string(Stages.size()) << endl;
			cout << "_______________________________" << endl;
			cout << endl;

			CurrentStage = Stages.at(i);

			volatile DWORD tStart;          // ��� ���������� ���-�� �����
			double TimeStart = 0;           // ��������� ����� � ������������
			tStart = GetTickCount();        // ��������� ��������� ���������� ����� �� ������  ���.�����
			TimeStart = omp_get_wtime();    // ����������� ����� � �������������
			double CurrentTime = 0;


			//CurrentTime = omp_get_wtime();
			TimeStart = GetTickCount();
			CurrentTime = GetTickCount();

			//cout << "�������� ����� ������ = " << to_string(CurrentStage.get_TimeStageOfMilliSec()) 
			//	<< ", ������� ������ � ������ " << to_string(CurrentTime - TimeStart) << endl;

			int CoeffFlips = CurrentStage.get_TimeStageOfMilliSec() / (CurrentStage.get_CountFlips() + 1);
			int CoeffVentilations = CurrentStage.get_TimeStageOfMilliSec() / (CurrentStage.get_CountVentilations() + 1);
			double timeToFlips = GetTickCount();
			double timeToVentilations = GetTickCount();

			cout << "====================================================================" << endl;
			while (CurrentStage.get_TimeStageOfMilliSec() >= (CurrentTime - TimeStart))
			{
				if (CurrentSensors->MinTemperature() < CurrentStage.get_MinTemerature())
				{
					cout << " ����������� ������� ����������� = " << to_string(CurrentSensors->MinTemperature()) 
						<< " ���� ���������� = " << to_string(CurrentStage.get_MinTemerature()) << endl;

					cout << "���������� ������..." << endl;
					while (CurrentSensors->MaxTemperature() < CurrentStage.get_MaxTemerature())
					{
						CurrentHeater->WarmUpZeroOneDegreeC0();
					}
					cout << "������ ��������!" << endl;
					cout << endl;
				}

				if (CurrentSensors->MinHummidity() < CurrentStage.get_MinHumidity())
				{
					cout << " ����������� ������� ��������� = " << to_string(CurrentSensors->MinHummidity())
						<< " ���� ���������� = " << to_string(CurrentStage.get_MinHumidity()) << endl;

					cout << "���������� ����������..." << endl;
					while (CurrentSensors->MaxHummidity() < CurrentStage.get_MaxHumidity())
					{
						CurrentHumidifier->WarmUpOnePercent();
					}
					cout << "���������� ���������!" << endl;
					cout << endl;
				}

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
				if (int (CurrentTime - timeToVentilations) > CoeffVentilations)
				{
					timeToVentilations = CurrentTime;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "���� ����������������!" << endl;
					CurrentVentilation->VentilationOn();
					CurrentVentilation->setState(CurrentVentilation->getState() + 10);
					cout << "���������� ���������!" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << endl;
				}

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
				if (int(CurrentTime - timeToFlips) > CoeffFlips)
				{
					timeToFlips = CurrentTime;
					cout << "���� ����������� ����!" << endl;
					CurrentFlipper->FlipperOn();
					cout << "���� �����������!" << endl;
					cout << endl;
				}

				// �������� ������ ����������
				CurrentSensors->Poteri();
				cout << "��������� ������������ ������ ����������� � ���������!" << endl;
				cout << "______________________________________________________" << endl;

				//CurrentTime = omp_get_wtime();
				CurrentTime = GetTickCount();
			}
			cout << "====================================================================" << endl;
			cout << endl;
			cout << endl;
		}
		

		cout << "**********************************************************" << endl;
		cout << "��������� ��� ���� " << CurrentEggType->GetName() << " ������� ���������!" << endl;
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

