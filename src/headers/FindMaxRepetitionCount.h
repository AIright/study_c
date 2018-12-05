//
// Created by Integr on 05/12/2018.
//

#ifndef STUDY_C_FINDMAXREPETITIONCOUNT_H
#define STUDY_C_FINDMAXREPETITIONCOUNT_H

//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <set>
//#include <vector>
//#include <string>
//#include <tuple>
//
//using namespace std;

/*
Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и определяющую,
 какое максимальное количество повторов она содержит.
 Две записи (объекты типа Region) считаются различными, если они отличаются хотя бы одним полем.

int FindMaxRepetitionCount(const vector<Region>& regions);

Если все записи уникальны, считайте максимальное количество повторов равным 1.
 Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для хранения ответа.
Вывод
3
1

Пояснение
В этой задаче вам надо прислать на проверку файл с реализацией функции FindMaxRepetitionCount,
 а также дополнительных функций, если это необходимо. Этот файл не должен содержать типы Lang и Region.
 В противном случае вы получите ошибку компиляции.
*/

//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};
//
//int FindMaxRepetitionCount(const vector<Region> &regions) {
//    map<tuple<string, string, map<Lang, string>, int64_t>, int> regions_counter;
//    int max_match = 0;
//    if (regions.empty()) {
//        return 0;
//    } else {
//        for (const auto& [name, par_name, names, pop] : regions) {
//            tuple key = make_tuple(name, par_name, names, pop);
//            regions_counter[key]++;
//            if (regions_counter[key] > max_match) {
//                max_match = regions_counter[key];
//            }
//        }
//    }
//    return max_match;
//};
//
//
//void test() {
//    cout << FindMaxRepetitionCount({}) << endl;
//    cout << FindMaxRepetitionCount(
//            {
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Russia",
//                            "Eurasia",
//                            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                            89
//                    },
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Russia",
//                            "Eurasia",
//                            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                            89
//                    },
//            }) << endl;
//
//    cout << FindMaxRepetitionCount(
//            {
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Russia",
//                            "Eurasia",
//                            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}},
//                            89
//                    },
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Moscow",
//                            "Toulouse",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
//                            89
//                    },
//                    {
//                            "Moscow",
//                            "Russia",
//                            {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
//                            31
//                    },
//            }) << endl;
//};
//
//int main() {
//    test();
//    return 0;
//};


#endif //STUDY_C_FINDMAXREPETITIONCOUNT_H
