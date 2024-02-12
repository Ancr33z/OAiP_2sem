#include <iostream>
#include <algorithm>

int numcq(int a, int b) {
    if (b == 0) 
        return 0;
    else 
        return floor(a/b) + numcq(b, (a - floor(a/b)*b));

}

int main() {

    setlocale(LC_ALL, "RUS");

    // Пример использования функции
    int a, b;

    std::cout << "Введите значение a: ";
    std::cin >> a;

    std::cout << "Введите значение b: ";
    std::cin >> b;

    int result = numcq(a, b);

    std::cout << "Значение numcq(" << a << ',' << b << ") = " << result << std::endl;

    return 0;
}
