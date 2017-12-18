//
// Created by alright on 17.12.17.
//
/* Напишите функцию UpdateIfGreater,
 * которая принимает два целочисленных аргумента: first и second.
 * Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
 * При этом изменение параметра second должно быть видно на вызывающей стороне.
 * Пояснение
 * В этой задаче на проверку вам надо прислать файл с реализацией функции UpdateIfGreater.
 * Этот файл не должен содержать функцию main.
 * Если в нём будет функция main, вы получите ошибку компиляции.
*/

#ifndef STUDY_C_MAXIMIZATOR_H
#define STUDY_C_MAXIMIZATOR_H

#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
//        cout << "Update second variable to " << first << endl;
        second = first;
    }
}

#endif //STUDY_C_MAXIMIZATOR_H
