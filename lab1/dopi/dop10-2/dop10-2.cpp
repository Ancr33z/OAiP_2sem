#include <iostream>
#include<string>
#include <stdarg.h>
using namespace std;
int sort(string word, ...);
void main() {
    string word;
    getline(cin, word);
    sort(word);
}
int sort(string word, ...) {
    char first = 'a';
    for (int i = 0; i < 26; i++) {

        if (word[0] == first) {
            for (int i = 0; i < size(word); i++) {
                if (word[i] == ' ') {
                    cout << ' ';
                    break;
                }
                cout << word[i];
            }
        }
        for (int j = 0; j < size(word); j++) {
            if ((word[j] == ' ' && word[j + 1] == first)) {
                for (int q = j + 1; q < size(word); q++) {
                    cout << word[q];
                    if (word[q] == ' ') {
                        cout << ' ';
                        break;
                    }
                }
                cout << ' ';
            }
        }
        first++;
    }
    return 0;
}