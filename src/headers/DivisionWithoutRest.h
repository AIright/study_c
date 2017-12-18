/* Дано два натуральных числа A и B, не превышающих 1 000 000.
 * Напишите программу, которая вычисляет целую часть
 * частного от деления A на B.
 * Если B = 0, выведите "Impossible". */

#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


string division_without_rest(int a, int b)
{
    int c, d;
    string res;
    if (b == 0) {
        res = "Impossible";
    } else if (b != 0) {
        c = a/b;
        d = c % 1;
        res = std::to_string(c - d);
    }
    return res;
}