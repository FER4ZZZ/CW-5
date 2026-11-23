// Задание 1
#include <iostream>
using namespace std;

// Рекурсивная функция подсчёта числа разбиений.
// n     - оставшаяся сумма, которую нужно разбить
// maxPart - максимально допустимое слагаемое (чтобы не учитывать перестановки)
long long countPartitions(int n, int maxPart) {
    // Базовые случаи:
    if (n == 0) return 1;        // одно корректное разбиение найдено
    if (n < 0)  return 0;        // перебрали — разбиения нет
    if (maxPart == 0) return 0;  // слагаемые закончились

    long long result = 0;
    // Пробуем в качестве очередного слагаемого числа от maxPart вниз до 1.
    // Ограничение maxPart не даёт учитывать перестановки (1+3 и 3+1 — одно и то же).
    for (int part = maxPart; part >= 1; --part) {
        result += countPartitions(n - part, min(part, n - part));
    }
    return result;
}

// Обёртка: разбиение числа n без ограничений на слагаемые
long long partitions(int n) {
    return countPartitions(n, n);
}

int main() {
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    if (n < 0) {
        cout << "Число должно быть неотрицательным!" << endl;
        return 1;
    }

    cout << "Количество разбиений числа " << n
         << " = " << partitions(n) << endl;
    return 0;
}