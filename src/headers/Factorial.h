//
// Created by alright on 16.12.17.
//
/* Напишите функцию, которая
 * называется Factorial
 * возвращает int
 * принимает int и возвращает факториал своего аргумента.
 * Гарантируется, что аргумент функции по модулю не превышает 10.
 * Для отрицательных аргументов функция должна возвращать 1.
 * Пояснение:
 * В этой задаче на проверку вам надо прислать файл с реализацией функции Factorial.
 * Этот файл не должен содержать функцию main.
 * Если в нём будет функция main, вы получите ошибку компиляции.
 */
#ifndef STUDY_C_FACTORIAL_H
#define STUDY_C_FACTORIAL_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long int factorial(int a) {
    int out = 1;
    if (a <= 1) {
        return 1;
    } else {
        for (int i = 1; i <= a; i++) {
            out *= i;
        }
        return out;
    }
}

#endif //STUDY_C_FACTORIAL_H
