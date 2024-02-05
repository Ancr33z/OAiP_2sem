#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(char x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
}

char pop(Stack*& myStk)   //���������� (��������) �������� �� �����
{
	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� (-1) 
	}
	else
	{
		Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
		char x = myStk->data;    //������ �������� �� ���� data � �����. x 
		if (myStk)
			myStk = myStk->next;   //������� �������
		delete e;
		return x;
	}
}

void delNegative(Stack*& myStk)
{
	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return;               //���� ���� ���� - ������� (-1) 
	}
	else
	{
		if (myStk->data < 0)
		{
		Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
		if (myStk)
			myStk = myStk->next;   //������� �������
		delete e;
			return;
		}
	}
}

void toFile(Stack*& myStk) //������ � ����
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "���� ������� � ���� mStack.dat\n";
}

void fromFile(Stack*& myStk)          //���������� �� �����
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, e);
		frm.read((char*)&buf, sizeof(Stack));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data = pop(e);
		push(buf.data, p);
		myStk = p;
	}
	cout << "\n���� ������ �� ����� mStack.dat\n\n";
}
void show(Stack*& myStk)  //����� ����� � ��������
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
		cout << pop(e) << " ";
	cout << endl;
}
