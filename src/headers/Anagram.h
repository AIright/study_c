//
// Created by alright on 18.12.17.
//
/* Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом.
 * Например, слово «eat» можно получить перестановкой букв слова «tea»,
 * поэтому эти слова являются анаграммами друг друга.
 * Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.
 * Указание
 * Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем.
 * Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква.
 * Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==),
 * то слова являются анаграммами друг друга, в противном случае не являются.
 * При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.
 * Формат ввода
 * Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить.
 * Гарантируется, что все слова состоят лишь из строчных латинских букв.
 * Формат вывода
 * Выведите N строк: для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.
 */

#ifndef STUDY_C_ANAGRAM_H
#define STUDY_C_ANAGRAM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string Anagram(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return "NO";
    } else {
        map<char, int> counter_s1, counter_s2;
        for (const auto &item : s1) {
            ++counter_s1[item];
        }
        for (const auto &item : s2) {
            ++counter_s2[item];
        }
        for (const auto &item : counter_s1) {
            if (item.second != counter_s2[item.first]) {
                return "NO";
            }
        }
        return "YES";
    }
}

int Anagram_main() {
    int tries;
    string string1, string2;
    cin >> tries;
    for (int i=0; i<tries; i++) {
        cin >> string1 >> string2;
        cout << Anagram(string1, string2) << endl;
    }
    return 0;
};




#endif //STUDY_C_ANAGRAM_H
