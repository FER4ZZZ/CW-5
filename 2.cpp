// Задание 2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const string inFile  = "input.txt";   // файл-источник
    const string outFile = "output.txt";  // файл-приёмник

    ifstream fin(inFile);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << inFile << endl;
        return 1;
    }

    vector<int> numbers;
    int x;
    // Считываем все числа из файла до конца
    while (fin >> x) {
        numbers.push_back(x);
    }
    fin.close();

    // Сортируем по возрастанию
    sort(numbers.begin(), numbers.end());

    ofstream fout(outFile);
    if (!fout.is_open()) {
        cerr << "Не удалось открыть файл " << outFile << endl;
        return 1;
    }

    // Записываем отсортированные числа (по одному в строке)
    for (int num : numbers) {
        fout << num << '\n';
    }
    fout.close();

    cout << "Готово! " << numbers.size()
         << " чисел записано в " << outFile << endl;
    return 0;
}