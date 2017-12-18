//
// Created by alright on 02.12.17.
//

/* На вход вашей программе в стандартном вводе даны действительные
 * коэффициенты A, B и C уравнения Ax² + Bx + C = 0.
 * Выведите все его различные действительные корни в любом порядке.
 * Гарантируется, что хотя бы один из коэффициентов не равен нулю. */

#include <cmath>
#include <iostream>
using namespace std;

void equation(double a, double b, double c)
{
    double d, x1, x2;

    d = pow(b, 2) - (4 * a * c);

    if ((a != 0) || (b != 0)) {
        if ((a == 0) && (c != 0)) {
            x1 = (-c) / b;
            cout << x1;
        } else if ((c == 0) && ((b == 0) || (a == 0))) {
            x1 = 0;
            cout << x1;
        } else if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << x1 << " " << x2;
        } else if (d == 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            cout << x1;
        }
    }
};
