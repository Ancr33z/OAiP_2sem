#include<iostream> 
using namespace std;
struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin);                        //вывод элементов очереди 
Number* minElem(Number* begin);               //определение минимального элемента 
Number* maxElem(Number* begin);
int elemBetween(Number* min, Number* max);
void delMaxElem(Number** begin);

int main()
{
    Number* begin = NULL, * end, * t, * max;
    t = new Number;
    max = new Number;
    int p, size;
    cout << "\nEnter size queue=";  cin >> size;
    cout << "Enter number= ";       cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cout << "Enter number= ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //вывод на экран
        cout << "No elements" << endl;
    else
        view(begin);
    t = minElem(begin);    //определение минимального
    cout << "minimum=" << t->info << endl;
    max = maxElem(begin);
    cout << "maximum=" << max->info << endl;
    cout << "Element between min and max elements: " << elemBetween(t, max);
    delMaxElem(&begin);
    cout << "\n Max element deleted \n";
    view(begin);

    return 0;
}
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
}
Number* minElem(Number* begin) //Определение минимального элемента
{
    Number* t = begin, * mn = nullptr;
    int min;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        min = t->info;
        while (t != NULL)
        {
            if (t->info <= min)
            {
                min = t->info;
                mn = t;
            }
            t = t->next;
        }
    }
    return mn;
}
Number* maxElem(Number* begin)
{
    Number* t = begin, * mx = nullptr;
    int max;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info >= max)
            {
                max = t->info;
                mx = t;
            }
            t = t->next;
        }
    }
    return mx;
}

int elemBetween(Number* min, Number* max)
{
    Number* t = min;
    int count = 0;
    while (t != NULL)
    {
        if (t == max)
        {
            return (count - 1);
        }
        else
        {
            t = t->next;
            count++;
        }
    }
}

void delMaxElem(Number** begin)
{
    if (*begin == nullptr) {
        // Список пуст, ничего не удаляем
        return;
    }

    // Ищем максимальный элемент в списке
    Number* max = *begin;
    Number* current = (*begin)->next;

    while (current != nullptr) {
        if (current->info > max->info) {
            max = current;
        }
        current = current->next;
    }

    // Удаляем максимальный элемент
    current = *begin;
    if (*begin == max) {
        // Если максимальный элемент - первый в списке
        *begin = (*begin)->next;
        delete max;
    }
    else {
        while (current->next != max) {
            current = current->next;
        }
        current->next = max->next;
        delete max;
    }
}
