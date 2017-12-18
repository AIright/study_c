//
// Created by alright on 04.12.17.
//

/* В стандартном потоке даны три строки, разделённые пробелом.
 * Каждая строка состоит из строчных латинских букв
 * и имеет длину не более 30 символов.
 * Выведите в стандартный вывод лексикографически минимальную из них. */

#include <iostream>
#include <string>
using namespace std;

void low_string(string a, string b, string c)
{
    if (a <= b && a <= c) {
        cout << a;
    }
    else if (b <= a && b <= c) {
        cout << b;
    }
    else cout << c;
}

