#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice; char x;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk = NULL;             //инициализация первого элемента	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Удаление первого отрицательного элемента из стека" << endl;
		cout << "4 - Запись в файл" << endl;
		cout << "5 - Чтение из файла" << endl;
		cout << "6 - Вывод стека с очисткой" << endl;
		cout << "7 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> x;
			push(x, myStk); break;
		case 2: delNegative(myStk);
		case 3: x = pop(myStk);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;
		case 4: toFile(myStk);  break;
		case 5: fromFile(myStk); break;
		case 6: cout << "Весь стек: " << endl;
			show(myStk); break;
		case 7: return 0; break;
		default: cout << "Нет такого варианта"; continue; break;
		}
	}
	return 0;
}
