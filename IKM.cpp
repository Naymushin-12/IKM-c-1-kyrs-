#include <iostream>
#include <string>
#include <cmath> // Для функции std::abs

using namespace std;

// Функция для вычисления НОД с использованием алгоритма Евклида
int64_t gcd(int64_t a, int64_t b) {
    while (b != 0) {
        int64_t temp = b;
        b = a % b;
        a = temp;
    }
    return std::abs(a); // Возвращаем модуль НОД
}

// Функция для проверки корректности ввода
bool corr(int64_t &num) {
    string input;
    cin >> input;

    // Проверка, что строка состоит только из цифр (может начинаться с '-')
    if (input.empty() || (input[0] != '-' && !isdigit(input[0]))) {
        return false; // Некорректный ввод
    }

    for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            return false; // Некорректный ввод
        }
    }

    // Преобразуем строку в число
    num = 0;
    bool neg = (input[0] == '-');
    
    for (size_t i = (neg ? 1 : 0); i < input.length(); ++i) {
        num = num * 10 + (input[i] - '0'); // Преобразование символа в число
    }

    if (neg) num = -num; // Устанавливаем знак

    return num >= 100000000000; // Проверяем, что число не меньше 10^11
}

int main() {
    setlocale(LC_ALL, "RU");
    int64_t m, n;

    cout << "Введите два целых числа (m и n), каждое не менее 10^11:" << endl;

    // Цикл для получения корректного ввода для m
    while (true) {
        cout << "m: ";
        if (corr(m)) {
            break; // Выход из цикла, если ввод корректен
        } else {
            cout << "Ошибка: число должно быть целым и не менее 10^11. Пожалуйста, попробуйте снова." << endl;
        }
    }

    // Цикл для получения корректного ввода для n
    while (true) {
        cout << "n: ";
        if (corr(n)) {
            break; // Выход из цикла, если ввод корректен
        } else {
            cout << "Ошибка: число должно быть целым и не менее 10^11. Пожалуйста, попробуйте снова." << endl;
        }
    }

    // Вычисление НОД
    int64_t res = gcd(m, n);
    
    // Вывод НОД
    cout << "Наибольший общий делитель (НОД) чисел " << m << " и " << n << " равен: " << res << endl;

    // Проверка взаимной простоты
    if (res == 1) {
        cout << "Числа " << m << " и " << n << " являются взаимно простыми." << endl;
    } else {
        cout << "Числа " << m << " и " << n << " не являются взаимно простыми." << endl;
    }

    return 0;
}
