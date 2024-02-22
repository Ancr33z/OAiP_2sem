#include <iostream>
#include <ctime>

using namespace std;

void insOrd(int m[], int sm, int em, int e);
int* merge(int m[], int sm, int cm, int em);
int* sortMerge(int m[], int lm, int sm = 0);
int getHoarBorder(int A[], int sm, int em);
int* sortHoar(int A[], int sm, int em);


int main()
{

    setlocale(LC_ALL, "RUS");
    const int MAX_SIZE = 60000; //Переменная для указания размера начального массива
    int i, j = 0;              //Переменные для итерации
    int size;                  //Количество элементов массива B
    int massA[MAX_SIZE];
    int massB[MAX_SIZE / 2];
    int massC[MAX_SIZE / 2];
    srand(time(0));
    clock_t t1, t2;




    for (i = 0; i < MAX_SIZE; i++)
    {
        massA[i] = rand();
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (i % 2 == 0 && (massA[i+1] % 2 == 1 || massA[i+1] % 2 == -1))
        {
            massB[j] = massA[i];
            j++;
        }
    }
    size = j; 
    for (i = 0; i < MAX_SIZE / 2; i++)
    {
        massC[i] = massB[i];
    }
    t1 = clock();
    sortMerge(massB, j, 0);
    t2 = clock();
    cout << "time for sorting by insertion: " << (t2 - t1) * 0.001 << "sec" << endl;

    t1 = clock();
    sortHoar(massC, 0, j);
    t2 = clock();
    cout << "time for sorting by Hoar: " << (t2 - t1) * 0.001 << "sec" << endl;



    return 0;
}


void insOrd(int m[], int sm, int em, int e)
{ // m[]  массив чисел; sm  индекс 1-ого элемента левой части; cm  индекс
  //последн. элемента левой части; em  индекс последн. элемента правой части
    int buf, i = sm;
    while (i <= em && m[i] > e)
    {
        if (i - 1 >= sm)
            m[i - 1] = m[i];
        i++;
    }  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
    for (int i = 0; i <= sm; i++)
    {
        if (m[i] < m[cm + 1])
        {
            int buf = m[i];
            m[i] = m[cm + 1];
            insOrd(m, cm + 1, em, buf);
        }
    }
    return m;
}
int* sortMerge(int m[], int lm, int sm)
{
    if (lm > 1)
    {
        sortMerge(m, lm / 2, sm);
        sortMerge(m, lm - lm / 2, sm + lm / 2);
        merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
    };
    return m;
}
int getHoarBorder(int A[], int sm, int em)
{
    int i = sm - 1, j = em + 1;
    int brd = A[sm], buf;
    while (i < j)
    {
        while (A[--j] > brd);
        while (A[++i] < brd);
        if (i < j)
        {
            buf = A[j];
            A[j] = A[i];
            A[i] = buf;
        };
    }
    return j;
}
int* sortHoar(int A[], int sm, int em)
{
    if (sm < em)
    {
        int hb = getHoarBorder(A, sm, em);
        sortHoar(A, sm, hb);
        sortHoar(A, hb + 1, em);
    }
    return A;
};
