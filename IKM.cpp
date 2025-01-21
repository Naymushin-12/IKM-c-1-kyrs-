#include <iostream>
#include <string>

using namespace std;

// Функция для проверки, является ли строка положительным целым числом
bool polchislo(const string& str) {
    // Проверяем, что строка не пустая и состоит только из цифр
    if (str.empty() || (str[0] == '0' && str.size() > 1)) {
        return false; // Не допускается ноль в начале для многозначных чисел
    }

    for (char c : str) {
        if (!isdigit(c)) {
            return false; // Содержит нецифровые символы
        }
    }
    return true;
}

// Функция для вычитания двух строковых чисел
string vichit(const string& num1, const string& num2) {
    string res;
    int bor = 0;

    // Удостоверимся, что num1 >= num2
    string n1 = num1, n2 = num2;
    if (num1 < num2) {
        swap(n1, n2);
    }

    while (n2.size() < n1.size()) {
        n2 = '0' + n2;
    }

    for (int i = n1.size() - 1; i >= 0; --i) {
        int digit1 = n1[i] - '0';
        int digit2 = n2[i] - '0';

        int sub = digit1 - digit2 - bor;
        if (sub < 0) {
            sub += 10;
            bor = 1;
        }
        else {
            bor = 0;
        }
        res = char(sub + '0') + res;
    }

    // Удаляем ведущие нули
    while (res.size() > 1 && res[0] == '0') {
        res.erase(0, 1);
    }

    return res.empty() ? "0" : res;
}

// Функция для нахождения остатка от деления
string mod(const string& a, const string& b) {
    string cur = "0";

    for (char digit : a) {
        cur += digit;

        // Удаляем ведущие нули
        while (cur.size() > 1 && cur[0] == '0') {
            cur.erase(0, 1);
        }

        // Сравниваем cur и b, пока cur >= b
        while (cur >= b) {
            cur = vichit(cur, b);
        }
    }

    return cur.empty() ? "0" : cur;
}

// Функция для нахождения НОД
string gcd(const string& a, const string& b) {
    string x = a;
    string y = b;

    while (y != "0") {
        string temp = y;
        y = mod(x, y);
        x = temp;
    }

    // Удаляем ведущие нули
    while (x.size() > 1 && x[0] == '0') {
        x.erase(0, 1);
    }

    return x.empty() ? "0" : x;
}

// Проверка на взаимную простоту
bool copr(const string& m, const string& n) {
    return gcd(m, n) == "1"; // Если НОД равен 1, то числа взаимно простые
}

// Описание взаимной простоты и вывод НОД
void explain(const string& m, const string& n, bool coprime, const string& gcdValue) {
    if (coprime) {
        cout << "Числа " << m << " и " << n << " являются взаимно простыми.\n";
    }
    else {
        cout << "Числа " << m << " и " << n << " не являются взаимно простыми, есть другой делитель.\n";
    }
    cout << "Наибольший общий делитель (НОД): " << gcdValue << endl; // Выводим значение НОД
}

int main() {
    setlocale(LC_ALL, "RU");
    string m, n;

    // Вводим числа
    cout << "Введите целые числа m и n (положительные): " << endl;

    // Проверяем ввод первого числа
    while (true) {
        cin >> m;
        if (polchislo(m)) {
            break; // Ввод корректен
        }
        cout << "Ошибка: введите положительное целое число >=10^11 для m: " << endl;
    }

    // Проверяем ввод второго числа
    while (true) {
        cin >> n;
        if (polchislo(n)) {
            break; // Ввод корректен
        }
        cout << "Ошибка: введите положительное целое число >=10^11 для n: " << endl;
    }

    // Находим НОД
    string gcdValue = gcd(m, n);
    
    // Проверяем, являются ли числа взаимно простыми
    bool coprime = copr(m, n);
    
    // Выводим результаты
    explain(m, n, coprime, gcdValue);

    return 0;
}
