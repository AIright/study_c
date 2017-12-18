//
// Created by alright on 12.12.17.
//

/* Дана строка. Найдите в этой строке второе вхождение
 * буквы f и выведите индекс этого вхождения.
 * Если буква f в данной строке встречается только один раз,
 * выведите число -1, а если не встречается ни разу,
 * выведите число -2. Индексы нумеруются с нуля.
*/

#ifndef STUDY_C_SECONDENTRANCE_H
#define STUDY_C_SECONDENTRANCE_H

#include <string>

using namespace std;

int second_entrance(string input) {
    int output = 0;
    int counter = 0;
    int pos = -1;

    for (char i : input) {
        pos++;
        if (i == 'f') {
            counter++;
            if (counter == 2) { break; }
        }
    }

    if (counter == 0) {
        output = -2;
    } else if (counter == 1) {
        output = -1;
    } else {
        output = pos;
    }

    return output;
}

#endif //STUDY_C_SECONDENTRANCE_H

