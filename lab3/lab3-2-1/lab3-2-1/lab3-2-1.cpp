#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int count = 0;
    char buff[256];
    char currentChar;
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    if (!file1.is_open()) {
        cout << "Ошибка открытия файла FILE1.txt" << endl;
        return 1;
    }


    do
    {
        file1.getline(buff, 250);

        if (buff[0] == 'A')
        {
            file2 << buff;
            file2 << '\n';
        }
    } while (!file1.eof());
    file1.close();
    file2.close();
    ifstream file2count("FILE2.txt");

    do
    {
        file2count >> buff;
        if (buff != NULL)
            count++;
    } while (!file2count.eof());

    file2.close();

    cout << count-1;
    return 0;
}