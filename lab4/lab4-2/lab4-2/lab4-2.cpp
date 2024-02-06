#include <iostream>
#include <fstream>

using namespace std;

void input();
void output();
void find(char lastName[16]);
void writeToFile();
void toConsole();
void delClient();

#define MAXSIZE 100

int clientNumber; FILE* f; errno_t err,choice, current_size = 0;


typedef struct HotelClient
{
	char passportDetails[30];
	char lastName[30];
	char arrivalDates[30];
	char departureDates[30];
	char placementType[30];
	int room;
} CLIENT;

CLIENT  clients[MAXSIZE];

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 50;
	char lastName[20];

	do
	{
		cout << "1.Ввод клиента\n";
		cout << "2.Ввод данных в файл\n";
		cout << "3.Вывод элементов в консоль \n";
		cout << "4.Удаление клиента\n";
		cout << "5.Вывод данных из файла\n";
		cout << "6.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите клиента: \n";
			input();
			break;
		case 2:
			writeToFile();
			break;
		case 3:
			toConsole();
			break;
		case 4:
			delClient();
			break;
		case 5:
			output();
			break;

		case 6:
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

void input()
{
	setlocale(LC_ALL, "Russian");
	

	if (current_size < MAXSIZE)
	{
		cout << "\nПаспортные данные: "; 	cin >> clients[current_size].passportDetails;
		cout << "\nФамилия: "; 	cin >> clients[current_size].lastName;
		cout << "\nДата приезда: "; 	cin >> clients[current_size].arrivalDates;
		cout << "\nДата отъезда: "; 	cin >> clients[current_size].departureDates;
		cout << "\nТип размещения: "; 	cin >> clients[current_size].placementType;
		cout << "\nНомер: "; 	cin >> clients[current_size].room;
		current_size++;
	}
	else {
		cout << "Достигнуто максимальное количество клиентов.\n";
	}

}


void writeToFile() {

	if (!fopen_s(&f, "base.bin", "ab"))
	{

		fwrite(&clients, sizeof(clients), 1, f);

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

void toConsole()
{
	for (int i = 0; i < current_size; i++)
	{
		cout << "Паспортные данные: " << clients[i].passportDetails << endl;
		cout << "Фамилия: " << clients[i].lastName << endl;
		cout << "Дата отъезда: " << clients[i].departureDates << endl;
		cout << "Тип размещения: " << clients[i].placementType << endl;
		cout << "Номер: " << clients[i].room << endl << endl;
	}
}

void delClient()
{
	int number;

	cout << "Введите номер клиента: ";
	cin >> number;

	if (number < current_size)
	{
		for (int i = number; i < current_size - 1; i++)
		{
			clients[i] = clients[i + 1];
		}
		current_size--;
		cout << "Клиент под номером " << number << " удален" << endl;
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
