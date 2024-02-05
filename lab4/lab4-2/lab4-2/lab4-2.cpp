#include <iostream>

using namespace std;

void input(int size);
void output();
void find(char lastName[16]);

int clientNumber; FILE* f; errno_t err;

typedef struct HotelClient
{
	char passportDetails[30];
	char lastName[30];
	char arrivalDates[30];
	char departureDates[30];
	char placementType[30];
	int room;
} CLIENT;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 50;
	int i, b, choice, counter = 0;
	char lastName[20];

	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите количество клиентов: ";
			cin >> clientNumber;
			input(clientNumber);
			break;

		case 2:
			output();
			break;

		case 3:
			cout << "Введите фамилию: ";
			cin >> lastName;
			find(lastName);
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

	CLIENT buf = { ' ', ' ', ' ', ' ', ' ', ' ' };
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{

			cout << "Паспортные данные: "; 	cin >> buf.passportDetails;
			cout << "Фамилия: "; 	cin >> buf.lastName;
			cout << "Дата приезда: "; 	cin >> buf.arrivalDates;
			cout << "Дата отъезда: "; 	cin >> buf.departureDates;
			cout << "Тип размещения: "; 	cin >> buf.placementType;
			cout << "Номер: "; 	cin >> buf.room;
			fwrite(&buf, sizeof(buf), 1, f);
			
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	CLIENT buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		cout << "\nФамилия    Группа\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << "Паспортные данные: " << buf.passportDetails << endl;
			cout << "Фамилия: " << buf.lastName << endl;
			cout << "Дата приезда: " << buf.arrivalDates << endl;
			cout << "Дата отъезда: " << buf.departureDates << endl;
			cout << "Тип размещения: " << buf.placementType << endl;
			cout << "Номер: " <<  buf.room << endl;
			fread(&buf, sizeof(buf), 1, f);

		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}


void find(char lastName[16])
{
	bool flag = false;  CLIENT buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.lastName) == 0)   
			{
				cout << "Паспортные данные: " << buf.passportDetails << endl;
				cout << "Фамилия: " << buf.lastName << endl;
				cout << "Дата отъезда: " << buf.departureDates << endl;
				cout << "Тип размещения: " << buf.placementType << endl;
				cout << "Номер: " << buf.room << endl;
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
