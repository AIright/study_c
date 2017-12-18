//
// Created by alright on 12.12.17.
//

/* В stdin даны два натуральных числа.
 * Найти их наибольший общий делитель.
*/

#ifndef STUDY_C_MAXCOMMONDIVISOR_H
#define STUDY_C_MAXCOMMONDIVISOR_H

#include <iostream>
#include <algorithm>

using namespace std;

// The Real solution
int max_common_divisor(int a, int b) {
    int div = 0;

    while (a > 0 && b > 0) {

        // возьмём большее из чисел и заменим его остатком от деления на второе
        // действительно, если a и b делятся на x, то a - b и b делятся на x
        // тогда и a % b и b делятся на x, так что можно a заменить на a % b
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }

    }

    // если одно из чисел оказалось равно нулю, значит, на последней итерации
    // большее число разделилось на меньшее
    div =  a + b;

    return div;
}

/* This is my code (LoL)
 * int max_common_divisor(int a, int b) {
    int div = 0;
    int min = 0;
    bool even = false;

    if (b % a == 0) {
        div = a;
    } else if (a % b == 0) {
        div = b;
        a = b; // for false in second for loop
    } else if (a < b) {
        min = a;
    } else {
        min = b;
    }
    if (min != 0) {
        if ((a % 2 == 0) && (b % 2 == 0)) {
            even = true;
        }
    }

    if ((div != a) && (even)) {
        for (int i = 2; i <= min; i+=2) {
            if ((a % i == 0) && (b % i == 0)) {
                div = i;
            }
        }
    } else if ((div != a) && (!even)) {
        for (int i = 1; i <= min; i++) {
            if ((a % i == 0) && (b % i == 0)) {
                div = i;
            }
        }
    }

    return div;
}

*/




#endif //STUDY_C_MAXCOMMONDIVISOR_H
