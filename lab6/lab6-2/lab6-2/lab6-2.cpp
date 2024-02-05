#include <iostream>
#include <fstream>

using namespace std;

struct list
{
	double number;
	list* next;
};

void insert(list*& p, double value); //Добавление символа в начало списка
void findAveragePositive(list*& p);  //Поиск среднего арифметического
void printList(list* p);      //Вывод списка 
int del(list*& p, int value); //Удаление числа
void toFile(list*& p);        //Запись в файл
void fromFile(list*& p);      //Считывание из файла
void menu(void);              //Вывод меню 


int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice; double value;
	menu();    // вывести меню 
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  	
			cout << "Введите число: ";
			cin >> value;
			insert(first, value);
			printList(first);
			menu();
			break;
		case 2: 
			findAveragePositive(first);
			break;
		case 3:	 
			cout << "Введите число для удаления";
			cin >> value;
			del(first, value);
			menu();
			break;
		case 4:   toFile(first); menu();
			break;
		case 5:   fromFile(first); menu();
			break;
		default:  cout << "Неправильный выбор" << endl;
			menu(); break;
		}
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, double value) //Добавление символа в начало списка
{
	list* newP = new list;
	if (newP != NULL)    //есть ли место?  
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void findAveragePositive(list*& p)
{
		double sum = 0, average = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number > 0)
			{	
				sum += p->number;
				p = p->next;
				average++;    //Считаем количество элементов списка 
			}
		}
		average = sum / average;
		cout << "Среднее арифметическое = " << average << endl;
	}
}

int del(list*& p, int value)  // Удаление числа 
{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}


void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	while (temp)
	{
		buf = *temp;
		frm.write(reinterpret_cast<char*>(&temp->number), sizeof(double));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p)          //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read(reinterpret_cast<char*>(&buf), sizeof(double));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read(reinterpret_cast<char*>(&buf), sizeof(double));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}

void menu(void)     //Вывод меню 
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Поиск среднего арифметического положительных элементов" << endl;
	cout << " 3 - Удаление числа" << endl;
	cout << " 4 - Запись списка в файл" << endl;
	cout << " 5 - Чтение списка из файла" << endl;
	cout << " 6 - Выход" << endl;
}
