#include <iostream>

using namespace std;

FILE* f;

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
	man = 1, woman
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

void input(int);
void find(int);
void output();


int main()
{
	setlocale(LC_ALL, "RUS");

	int i, b, choice, clientNumber, counter = 0;
	int birthdate;
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
			cout << "Введите количество горжанин: ";
			cin >> clientNumber;
			input(clientNumber);
			break;

		case 2:
			output();
			break;

		case 3:
			cout << "Введите дату рождения: ";
			cin >> birthdate;
			find(birthdate);
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
	int sex = 0;
	bool err = false;

	CITIZEN buf = { ' ', ' ', ' ', {}, {' '},};
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{

			cout << "Введите имя: "; cin >> buf.name; cout << endl;
			cout << "Введите фамилию: "; cin >> buf.surname; cout << endl;
			cout << "Введите отчество: "; cin >> buf.fathersName; cout << endl;
			cout << "Введите дату рождения: "; cin >> day; buf.birthDate.day = day; cin >> month; buf.birthDate.month = month; cin >> year; buf.birthDate.year = year; cout << endl;
			cout << "Введите город: "; cin >> buf.residentialАddress.city; cout << endl;
			cout << "\t" << "Введите дом: "; cin >> buf.residentialАddress.house; cout << endl;
			cout << "\t" << "Введите улицу: "; cin >> buf.residentialАddress.street; cout << endl;
			cout << "\t" << "Введите квартиру: "; cin >> buf.residentialАddress.apartment; cout << endl;
			do
			{
				cout << "Введите пол: 1-man 2-woman "; cin >> sex; (sex == 0) ? buf.sex = man : (sex == 1) ? buf.sex = woman : err = true;
				if (err)
					cout << "Некоректный ввод";
			} while (err);
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
