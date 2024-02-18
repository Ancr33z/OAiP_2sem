#include <iostream> //a=-1 b=-0.1 n=200
#include <cmath>

using namespace std;

float equation1(float x) {
    return (sin(x) + pow(x, 3));
}

float equation2(float x) {
    return (0.4 + pow(x, 3));
}

float bisectionMethod(float (*equation)(float), float a, float b, float epsilon) {
    float x;
    int iteration = 0;

    do {
        x = (a + b) / 2;

        if (equation(x) * equation(a) <= 0) {
            b = x;
        }
        else {
            a = x;
        }

        iteration++;
    } while (abs(a - b) > 2 * epsilon);

    return x;
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    float a, b;
    const float epsilon = 0.001;
    int maxIterations;

    cout << "Введите начальное значение a: ";
    cin >> a;

    cout << "Введите начальное значение b: ";
    cin >> b;


    cout << "Уравнение 1:sin(x) + pow(x, 3)=0" << endl;
    float root1 = bisectionMethod(equation1, a, b, epsilon);
    cout << "Корень уравнения 1: " << root1 << endl << endl;


    cout << "Уравнение 2: 0.4 + pow(x, 3)= 0" << endl;
    float root2 = bisectionMethod(equation2, a, b, epsilon);
    cout << "Корень уравнения 2: " << root2 << endl;

    return 0;
}

