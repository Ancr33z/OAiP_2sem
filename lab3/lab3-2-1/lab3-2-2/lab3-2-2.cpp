#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0;
    char buff[256];
    char smallest[256];
    ofstream file1("file1.txt");
    char currentChar;

    char inputString[256];
    cout << "Введите строку символов: ";
    cin.getline(inputString, sizeof(inputString));
    while(inputString[i] != '\0')
    {
        if (inputString[i] != '0')
            file1 << inputString[i];
        else
        {
            inputString[i] = ' ';
            file1 << inputString[i];
        }
        i++;
    }

    file1.close();

    ifstream outFile("file1.txt");

    do
    {
        outFile >> buff;

        if (strlen(buff) < strlen(smallest))
        {
            strcpy_s(smallest, buff);
             
        }
    } while (outFile.get(currentChar));

    cout << '\n' << "Самая короткая группа: " << smallest << '\n';
    cout << "\nПрограмма успешно выполнена";
    return 0;
}
