#include <iostream>
#include <cmath>

using namespace std;

float equation1(float x) {
    return (pow(x, 3) + x - 3);
}

float equation2(float x) {
    return (pow(cos(x), 3));
}

float bisectionMethod(float (*equation)(float), float a, float b, float epsilon, int maxIterations) {
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
    } while (fabs(a - b) > 2 * epsilon);

    return x;
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    float a, b;
    const float epsilon = 0.001;
    int maxIterations;

    cout << "������� ��������� �������� a: ";
    cin >> a;

    cout << "������� ��������� �������� b: ";
    cin >> b;

    cout << "������� ������������ ���������� �������� n: ";
    cin >> maxIterations;


    cout << "��������� 1: x^3 + x + 3 = 0" << endl;
    float root1 = bisectionMethod(equation1, a, b, epsilon, maxIterations);
    cout << "������ ��������� 1: " << root1 << endl << endl;


    cout << "��������� 2: cos^3(x) = 0" << endl;
    float root2 = bisectionMethod(equation2, a, b, epsilon, maxIterations);
    cout << "������ ��������� 2: " << root2 << endl;

    return 0;
}