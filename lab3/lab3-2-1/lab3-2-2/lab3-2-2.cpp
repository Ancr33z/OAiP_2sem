#include <fstream>
#include <iostream>

using namespace std;

void ifFile(char inputString[256]);
void fromFile();

char smallest[256];

int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0;
    char inputString[256];
    cout << "Введите строку символов: ";
    cin.getline(inputString, sizeof(inputString));



    ifFile(inputString);

    fromFile();
   


    cout << '\n' << "Самая короткая группа: " << smallest << '\n';
    cout << "\nПрограмма успешно выполнена";
    return 0;
}

void ifFile(char inputString[256]) 
{
    int i = 0;
    ofstream file1("file1.txt");
    while (inputString[i] != '\0')
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
}

void fromFile()
{
    ifstream outFile("file1.txt");

    char buff[256];
    char currentChar;

    outFile >> buff;
    strcpy_s(smallest, buff);

    do
    {
        outFile >> buff;

        if (strlen(buff) < strlen(smallest) && buff[0] != '\0')
        {
            strcpy_s(smallest, buff);

        }

    } while (outFile.get(currentChar));

    outFile.close();

}