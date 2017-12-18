//
// Created by alright on 17.12.17.
//

/* Реализуйте функцию void Reverse(vector<int>& v),
 * которая переставляет элементы вектора в обратном порядке.
 */

#ifndef STUDY_C_REVERSE_H
#define STUDY_C_REVERSE_H

#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
    std::vector<int> temp;
    for (auto i : v) {
        temp.insert(temp.begin(), i);
    }
    v = temp;
}

/* Реализуйте функцию vector<int> Reversed(const vector<int>& v),
 * возвращающую копию вектора v, в которой числа переставлены в
 * обратном порядке.
 */

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> temp;
    for (auto i : v) {
        temp.insert(temp.begin(), i);
    }
    return temp;
}

#endif //STUDY_C_REVERSE_H
