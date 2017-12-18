//
// Created by alright on 16.12.17.
//
/* Напишите функцию, которая
 * называется IsPalindrom
 * возвращает bool
 * принимает параметр типа string и возвращает, является ли переданная строка палиндромом
 * Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.
 * Пояснение
 * В этой задаче на проверку вам надо прислать файл с реализацией функции IsPalindrom.
 * Этот файл не должен содержать функцию main.
 * Если в нём будет функция main, вы получите ошибку компиляции.
*/

#ifndef STUDY_C_PALINDROM_H
#define STUDY_C_PALINDROM_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string input) {
    vector<char> v1, v2;
    for (char i : input) {
        v1.push_back(i);
        v2.insert(v2.begin(), i);
    }
    if (v1 == v2) {
        return true;
    } else {
        return false;
    }
}


/* Напишите функцию, которая
 * называется PalindromFilter
 * возвращает vector<string>
 * принимает vector<string> words и int minLength и возвращает все строки из вектора words,
 * которые являются палиндромами и имеют длину не меньше minLength
 * Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
 * Пояснение
 * В этой задаче вам надо прислать на проверку файл с реализацией функции PalindromFilter,
 * а также других функций, если это необходимо (например, функции проверки на палиндром).
 * Этот файл не должен содержать функцию main.
 * Если в нём будет функция main, вы получите ошибку компиляции.
*/

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> out;
    for (string i : words) {
        if ((IsPalindrom(i)) && (i.length() >= minLength)) {
            out.push_back(i);
        }
    }
    return out;
}


#endif //STUDY_C_PALINDROM_H