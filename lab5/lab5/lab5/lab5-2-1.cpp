#include <iostream>

using namespace std;


void input();
void writeToFile();
void toConsole();
void toConsoleFromFile();
void find(int);
void delCitizen();

const int MAX_SIZE = 100;
FILE* f; int current_size = 0;

struct date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12;
};

struct adress
{
	char city[30];
	char street[30];
	char house[30];
	int apartment;
};
enum gender
{
	man = 0, woman
};

typedef struct information
{	
	char name[30];
	char surname[30];
	char fathersName[30];
	date birthDate;
	adress residentialАddress;
	gender sex;
} CITIZEN;


CITIZEN  clients[MAX_SIZE];

int main()
{
	setlocale(LC_ALL, "RUS");

	int i, b, choice, number, counter = 0;
	int birthdate;
	do 
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Ввод данных в файл\n";
		cout << "3.Вывод данных в консоль\n";
		cout << "4.Вывод данных из файла\n";
		cout << "5.Поиск по фамилии\n";
		cout << "6.Удаление горожанина\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			writeToFile();
			break;
		case 3:
			toConsole();
		case 4:
			toConsoleFromFile();
			break;

		case 5:
			cout << "Введите дату рождения: ";
			cin >> birthdate;
			find(birthdate);
			break;
		case 6:
			delCitizen();

		default:
			break;
		}
	} while (choice != 0);

	return 0;
}

void input()
{
	setlocale(LC_ALL, "Russian");

	int day, month, year;
	int sex = 0;
	bool err = false;

	if (current_size < MAX_SIZE)
	{
		cout << "Введите имя: "; cin >> clients[current_size].name; cout << endl;
		cout << "Введите фамилию: "; cin >> clients[current_size].surname; cout << endl;
		cout << "Введите отчество: "; cin >> clients[current_size].fathersName; cout << endl;

		cout << "Введите дату рождения в формате (ДД ММ ГГГГ): "; cin >> day; clients[current_size].birthDate.day = day; 
		cin >> month; clients[current_size].birthDate.month = month; 
		cin >> year; clients[current_size].birthDate.year = year; cout << endl;

		cout << "Введите город: "; cin >> clients[current_size].residentialАddress.city; cout << endl;
		cout << "\t" << "Введите улицу: "; cin >> clients[current_size].residentialАddress.street; cout << endl;
		cout << "\t" << "Введите дом: "; cin >> clients[current_size].residentialАddress.house; cout << endl;
		cout << "\t" << "Введите квартиру: "; cin >> clients[current_size].residentialАddress.apartment; cout << endl;
		do
		{
			cout << "Введите пол: 0-man 1-woman "; cin >> sex; (sex == 0) ? clients[current_size].sex = man : (sex == 1) ? clients[current_size].sex = woman : err = true;
			if (err)
				cout << "Некоректный ввод";
		} while (err);

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

void toConsole()
{
	
	for (int i = 0; i < current_size; i++)
	{
		cout << "Имя: " << clients[i].name << endl;
		cout << "Фамилия: " << clients[i].surname << endl;
		cout << "Отчество: " << clients[i].fathersName << endl;
		cout << "Дата рождения: " << clients[i].birthDate.day << '.' << clients[i].birthDate.month << '.' << clients[i].birthDate.year << endl;
		cout << "Адресс " << "Город: " << clients[i].residentialАddress.city << endl;
		cout << "\t" << "Улица: " << clients[i].residentialАddress.street << endl;
		cout << "\t" << "Дом: " << clients[i].residentialАddress.house << endl;
		cout << "\t" << "Квартира: " << clients[i].residentialАddress.apartment << endl;
		cout << "Пол: "; clients[i].sex ? (cout << "man" << endl) : (cout << "woman" << endl);
	}
}

void toConsoleFromFile()
{
	CITIZEN buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << "Имя: " << buf.name << endl;
			cout << "Фамилия: " << buf.surname << endl;
			cout << "Отчество: " << buf.fathersName << endl;
			cout << "Дата рождения: " << buf.birthDate.day << '.' << buf.birthDate.month << '.' << buf.birthDate.year << endl;
			cout << "Адресс " << "Город: " << buf.residentialАddress.city << endl;
			cout << "\t" << "Улица: " << buf.residentialАddress.street << endl;
			cout << "\t" << "Дом: " << buf.residentialАddress.house << endl;
			cout << "\t" << "Квартира: " << buf.residentialАddress.apartment << endl;
			cout << "Пол: "; buf.sex ? (cout << "man" << endl) : (cout << "woman" << endl);
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


void find(int birthDate)
{
	bool flag = false;  CITIZEN buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (birthDate == buf.birthDate.year)
			{
				cout << "Имя: " << buf.name<< endl;
				cout << "Фамилия: " << buf.surname << endl;
				cout << "Отчество: " << buf.fathersName << endl;
				cout << "Дата рождения: " << buf.birthDate.day << '.' << buf.birthDate.month << '.' << buf.birthDate.year << endl;
				cout << "Адресс: " << "Город: " << buf.residentialАddress.city << endl;
				cout << "\t" << "Улица: " << buf.residentialАddress.street << endl;
				cout << "\t" << "Дом: " << buf.residentialАddress.house << endl;
				cout << "\t" << "Квартира: " << buf.residentialАddress.apartment << endl;
				cout << "Пол: "; buf.sex ? (cout << "man" << endl) : (cout << "woman" << endl);
				flag = true;
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


void delCitizen()
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
	else
		cout << "Клиента под таким номером нету";
}
