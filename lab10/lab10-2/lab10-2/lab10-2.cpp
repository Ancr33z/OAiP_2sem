#include <iostream>
#include <algorithm>

int F(int m, int n) {
    if ((n + m) % 2 == 0) {
        return std::max(m, n);
    }
    else {
        int newM = (n + m + 1) / 2;
        int newN = n + 1;
        return F(newM, n) + F(m, newN);
    }
}

int main() {

    setlocale(LC_ALL, "RUS");

    // Пример использования функции
    int m, n;

    std::cout << "Введите значение m: ";
    std::cin >> m;

    std::cout << "Введите значение n: ";
    std::cin >> n;

    int result = F(m, n);

    std::cout << "Значение F(" << m << ", " << n << ") = " << result << std::endl;

    return 0;
}
