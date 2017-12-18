//
// Created by alright on 12.12.17.
//

/* Дано два целых числа A и B (A <= B, A >= 1, B <= 30000).
 * Выведите через пробел все чётные числа от A до B (включительно).
 *
 * Для проверки целого числа x на чётность используется
 * операция взятия остатка от деления на 2,
 * которая в C++ оформляется с помощью символа "%".
*/

#ifndef STUDY_C_EVENNUMBERS_H
#define STUDY_C_EVENNUMBERS_H

#include <string>
#include <iostream>

using namespace std;

string even_numbers(int A, int B) {
    string output = "";
    while (A <= B) {
        if ((A % 2) == 0) {
            output += std::to_string(A);
            output += " ";
            A += 2;
        } else if ((A % 2) != 0) {
            A++;
        }
        }

    return output;
}

#endif //STUDY_C_EVENNUMBERS_H



