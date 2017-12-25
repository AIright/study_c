//
// Created by alright on 23.12.17.
//
/* Условие
 * В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
 * Между собой число и строки разделены пробелом.
 * Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв,
 * и выведите их в стандартный поток вывода.
 * Ограничения
 * 0 <= N <= 1000
 * 1 <= |S| <= 15
 * Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
 */

#ifndef STUDY_C_LOWERCASESORT_H
#define STUDY_C_LOWERCASESORT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/* real solution
int main() {
    // считываем вектор строк
    int n;
    cin >> n;
    vector<string> v(n);
    for (string& s : v) {
        cin >> s;
    }

    // сортируем
    sort(begin(v), end(v),
            // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
         [](const string& l, const string& r) {
             // сравниваем лексикографически...
             return lexicographical_compare(
                     // ... все символы строки l ...
                     begin(l), end(l),
                     // ... со всеми символами строки r ...
                     begin(r), end(r),
                     // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
                     [](char cl, char cr) { return tolower(cl) < tolower(cr); }
             );
         }
    );

    // выводим отсортированный вектор
    for (const string& s : v) {
        cout << s << ' ';
    }

    return 0;
} */

// my solution
bool CompareString(string x, string y) {
    locale loc;
    string bufx, bufy;
    for (auto i : x) {
        bufx += tolower(i, loc);
    }
    cout << endl;
    for (auto i : y) {
        bufy += tolower(i, loc);
    }
    return bufx < bufy;
}

void PrintVector(const vector<string>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int LowercaseSort_main() {
    int vector_length;
    cin >> vector_length;
    vector<string> symbols(vector_length);
    for (auto& i : symbols) {
        cin >> i;
    }
    sort(symbols.begin(), symbols.end(), CompareString);
    PrintVector(symbols);
    return 0;
};


#endif //STUDY_C_LOWERCASESORT_H
