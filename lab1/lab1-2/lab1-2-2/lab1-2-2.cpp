#include <iostream>


int sum(int n, ...);
using namespace std;

void main()
{
    cout << sum(6, 4, 5, 1, 2, 3, 2) << endl;
    cout << sum(2, 34, 4445) << endl;
    cout << sum(6, 4, 5, 1, 2, 5, 7, 5) << endl;
    cout << sum(1, 200) << endl;
}

int sum(int n, ...)
{
    int* p = &n;
    int sum = 0;
    ++p;
    ++p;
    for (int i = 1; i < n; i++) {
        sum += (*(p) * *(p + 2));
        cout << *p << " " << *(p + 2) << endl;
        p++;
        p++;

    }
    return sum;
}