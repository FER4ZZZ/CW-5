#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    // Считываем строку целиком, включая пробелы
    cout << "Введите строку: ";
    getline(cin, line);

    // Проходим по всем символам и заменяем пробелы на '_'
    for (char &c : line) {
        if (c == ' ') {
            c = '_';
        }
    }

    cout << "Результат: " << line << endl;
    return 0;
}