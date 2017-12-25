//
// Created by alright on 24.12.17.
//

#ifndef STUDY_C_SORTEDSTRINGS_H
#define STUDY_C_SORTEDSTRINGS_H

#include <string>
#include <algorithm>
#include <iostream>
#include <locale>
#include <vector>

using namespace std;
// Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:
class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        string_set.push_back(s);
    }
    vector<string> GetSortedStrings() {
        // отсортировать строки
        sort(begin(string_set), end(string_set));
        // получить набор из всех добавленных строк в отсортированном порядке
        return string_set;
    }
private:
    vector<string> string_set;
};


#endif //STUDY_C_SORTEDSTRINGS_H
