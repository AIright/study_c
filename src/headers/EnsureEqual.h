//
// Created by alright on 12/01/2018.
//

#ifndef STUDY_C_ENSUREEQUAL_H
#define STUDY_C_ENSUREEQUAL_H

#include <iostream>
#include <sstream>

using namespace std;

/* В случае, если строка left не равна строке right,
 * функция должна выбрасывать исключение runtime_error с содержанием
 * "<l> != <r>", где <l> и <r> - строки, которые хранятся в переменных left и right соответственно.
 * Обратите внимание, что вокруг знака неравенства в строке,
 * которая помещается в исключение, должно быть ровно по одному пробелу.
 * Если left == right, функция должна корректно завершаться.
 */

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        stringstream text;
        text << left << " != " << right;
        throw runtime_error(text.str());
    }
}
#endif //STUDY_C_ENSUREEQUAL_H
