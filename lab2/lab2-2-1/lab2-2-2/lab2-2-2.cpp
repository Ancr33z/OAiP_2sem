#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n, num;
    int arr[20];
    printf("Введите количество повторений (10 положительных и 10 отрицательных считать как одно повторение): ");
    scanf_s("%d", &n);
    FILE* f;
    FILE* g;

    fopen_s(&f, "f.txt", "w");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            fprintf(f, " %d", (rand() % 90 + 10));
        }
        for (int j = 0; j < 10; j++) {
            fprintf(f, " %d", -(rand() % 90 + 10));
        }
    }
    fclose(f);
    fopen_s(&f, "f.txt", "r");
    fopen_s(&g, "g.txt", "w");



    for (int i = 0; i < n; ++i) 
    {

        for (int j = 0; j < 20; j++)
        {
            fscanf_s(f, "%d", &arr[j]);
        }
        for (int j = 0; j < 10; j++)
        {

            for (int j = 0; j < 2; j++)
            {
                fscanf_s(f, "%d", &num);
                fprintf(g, " %d", arr[j]);
            }
            for (int j = 0; j < 2; j++)
            {
                fscanf_s(f, "%d", &num);
                fprintf(g, " %d", arr[j + 10]);
            }
        }
    }

    fclose(f);
    fclose(g);

    cout << "Числа записаны в файлы g.txt" << endl;

    return 0;
}


// Добавить работоспособность к 2 элементам