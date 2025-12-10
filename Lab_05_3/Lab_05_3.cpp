#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип функції
double k_func(const double x);

#ifndef _TEST
int main()
{
    double zp, zk, z, y, dz;
    int n;

    cout << "zp = "; cin >> zp;
    cout << "zk = "; cin >> zk;
    cout << "n = "; cin >> n;

    // Розрахунок кроку
    dz = (zk - zp) / n;
    z = zp;

    // Вивід шапки таблиці
    cout << fixed << setprecision(4);
    cout << "--------------------------------" << endl;
    cout << "|" << setw(10) << "z" << " |" << setw(15) << "Result (y)" << " |" << endl;
    cout << "--------------------------------" << endl;

    // Цикл для проходження по інтервалу
    while (z <= zk + dz / 2) // +dz/2 для компенсації похибки float
    {
        // Головна формула варіанту 7:
        // y = k(z^2 + 1) - k(z^2 - 1) + 2k(z)

        y = k_func(z * z + 1) - k_func(z * z - 1) + 2 * k_func(z);

        cout << "|" << setw(10) << z << " |" << setw(15) << y << " |" << endl;

        z += dz;
    }
    cout << "--------------------------------" << endl;

    return 0;
}
#endif

// Реалізація функції k(x)
double k_func(const double x)
{
    // Перевірка умови |x| >= 1
    if (abs(x) >= 1)
    {
        // Формула для першого випадку
        return (exp(x) + sin(x)) / (pow(cos(x), 2) + 1);
    }
    else
    {
        // Формула для другого випадку (|x| < 1)
        // k(x) = (1 / e^x) * SUM(x^i / i!) від i=0 до 5

        double S = 0;
        double a = 1; // Перший член ряду при i=0: (x^0 / 0!) = 1
        S = a;        // Додаємо його до суми

        // Цикл від i=1 до 5 (як вказано над знаком суми у формулі)
        for (int i = 1; i <= 5; i++)
        {
            // Рекурентне співвідношення: R = x / i
            a *= x / i;
            S += a;
        }

        // Повертаємо результат, помножений на коефіцієнт перед сумою
        return (1.0 / exp(x)) * S;
    }
}