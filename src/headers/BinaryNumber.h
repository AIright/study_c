//
// Created by alright on 14.12.17.
//
/* На вход дано целое положительное число N.
 * Выведите его в двоичной системе счисления без ведущих нулей.
 * Подсказка
 * число N можно считывать в переменную типа int
 * в этой задаче вам может пригодиться контейнер vector;
 * напоминаем, что добавление значения x в конец вектора v
 * делается так: v.push_back(x);
*/

#ifndef STUDY_C_BINARYNUMBER_H
#define STUDY_C_BINARYNUMBER_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string binary_number(int a) {
    vector<int> v = {};
    stringstream out_stream;
    string out;
    while (a > 0) {
        v.insert(v.begin(), a % 2);
        a /= 2;
    }
    if (v.empty()) {
        v = {0};
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(out_stream, ""));
    out = out_stream.str().c_str();
    return out;
}


#endif //STUDY_C_BINARYNUMBER_H
