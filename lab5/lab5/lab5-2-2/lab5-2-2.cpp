#include <iostream>

using namespace std;

FILE* f;

typedef struct time
{
	int hours : 5;
	int minuts : 6;
} TIME;

union trainNumber
{
	int iNumber;
	char cNumber;
};

typedef struct Station
{
	trainNumber number;
	char destinationPoint[30];
	int travelDays;
	TIME arrivalTime;
	TIME departureTime;
} RAILWAY;

void input(int);
void find(char[30]);
void toConsoleFromFile();


int main()
{
	setlocale(LC_ALL, "RUS");

	int i, b, choice, trainNumber, counter = 0;
	char destinationPoint[30];
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по пункту назначения\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите количество поездов: ";
			cin >> trainNumber;
			input(trainNumber);
			break;

		case 2:
			toConsoleFromFile();
			break;

		case 3:
			cout << "Введите пункт назначения: ";
			cin >> destinationPoint;
			find(destinationPoint);
			break;

		default:
			break;
		}
	} while (choice != 0);

	return 0;
}


void input(int size)
{
	setlocale(LC_ALL, "Russian");
	int day, month, year;
	int hours, minuts;
	bool err = false;

	RAILWAY buf = { ' ', ' ', ' ', {}, {' '}, };
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{

			cout << "Номер поезда: "; cin >> buf.number.cNumber;
			cout << "Пункт назначения: "; cin >> buf.destinationPoint;
			cout << "Дни следования: "; cin >> buf.travelDays;
			cout << "Время прибытия: "; cin >> hours >> minuts; buf.arrivalTime.hours = hours; buf.arrivalTime.minuts = minuts;
			cout << "Время отправления: "; cin >> hours >> minuts; buf.departureTime.hours = hours; buf.departureTime.minuts = minuts;
			fwrite(&buf, sizeof(buf), 1, f);

		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void toConsoleFromFile()
{
	bool flag = false; RAILWAY buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << "Номер поезда: " << buf.number.iNumber << endl;
			cout << "Пункт назначения: " << buf.destinationPoint << endl;
			cout << "Дни следования: " << buf.travelDays << endl;
			cout << "Время прибытия: " << buf.arrivalTime.hours << '.' << buf.arrivalTime.minuts << endl;
			cout << "Время отправления " << buf.departureTime.hours << '.' << buf.departureTime.minuts << endl;
			flag = true; break;
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}


void find(char destinationPoint[30])
{
	bool flag = false;  RAILWAY buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(destinationPoint, buf.destinationPoint) == 0)
			{
				cout << "Номер поезда: " << buf.number.iNumber << endl;
				cout << "Пункт назначения: " << buf.destinationPoint << endl;
				cout << "Дни следования: " << buf.travelDays << endl;
				cout << "Время прибытия: " << buf.arrivalTime.hours << '.' << buf.arrivalTime.minuts << endl;
				cout << "Время отправления " << buf.departureTime.hours << '.' << buf.departureTime.minuts << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
