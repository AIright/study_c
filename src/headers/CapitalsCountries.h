//
// Created by alright on 18.12.17.
//

#ifndef STUDY_C_CAPITALSCOUNTRIES_H
#define STUDY_C_CAPITALSCOUNTRIES_H

#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



/*Реализуйте справочник столиц стран.
 * На вход программе поступают следующие запросы: CHANGE_CAPITAL, DUMP, ABOUT, RENAME
 * Формат ввода
 * В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов.
 * Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.
 */

/* CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital,
 * либо добавление такой страны с такой столицей, если раньше её не было.
 * В ответ на запрос CHANGE_CAPITAL country new_capital выведите
 * Introduce new country country with capital new_capital, если страны country раньше не существовало;
 * Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
 * Country country has changed its capital from old_capital to new_capital, если страна country
 * до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
 */
void CHANGE_CAPITAL(const string& country, const string& new_capital, map<string, string>& countries) {
    if (!countries.count(country)) {
        countries[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    } else if (countries.count(country)) {
        if (countries[country] == new_capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        } else {
            cout << "Country " << country << " has changed its capital from "
                 << countries[country] << " to " << new_capital << endl;
            countries[country] = new_capital;
        }
    }
}

/* RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
 * В ответ на запрос RENAME old_country_name new_country_name выведите
 * Incorrect rename, skip, если новое название страны совпадает со старым,
 * страна old_country_name не существует или страна new_country_name уже существует;
 * Country old_country_name with capital capital has been renamed to new_country_name,
 * если запрос корректен и страна имеет столицу capital.
 */
void RENAME(const string& old_country_name, const string& new_country_name, map<string, string>& countries) {
    if (countries.count(new_country_name) || !countries.count(old_country_name) || new_country_name == old_country_name) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        countries[new_country_name] = countries[old_country_name];
        countries.erase(old_country_name);
        cout << "Country " << old_country_name << " with capital "
             << countries[new_country_name] << " has been renamed to " << new_country_name << endl;
    }
}

/* ABOUT country — вывод столицы страны country.
 * В ответ на запрос ABOUT country выведите
 * Country country doesn't exist, если страны с названием country не существует;
 * Country country has capital capital, если страна country существует и имеет столицу capital.
*/
void ABOUT(const string& country, const map<string, string>& countries) {
    if (!countries.count(country)) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << countries[country] << endl;
    }
}

/* DUMP — вывод столиц всех стран.
* В ответ на запрос DUMP выведите
* There are no countries in the world, если пока не было добавлено ни одной страны;
* разделённые пробелами пары country/capital, описывающие столицы всех стран и упорядоченные по названию страны,
* если в мире уже есть хотя бы одна страна.
*/
void DUMP(const map<string, string>& countries) {
    if (countries.size() == 0) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& c : countries) {
            cout << c.first << "/" << c.second << " ";
        }
        cout << endl;
    }
}

int CapitalsCountries_main() {
    int tries;
    string param1, param2, param3;
    map<string, string> countries;
    cin >> tries;
    for (int i=0; i<tries; i++) {
        cin >> param1;
        if (param1 == "DUMP") {
            DUMP(countries);
        } else if (param1 == "ABOUT") {
            cin >> param2;
            ABOUT(param2, countries);
        } else if (param1 == "RENAME" || param1 == "CHANGE_CAPITAL") {

            cin >> param2 >> param3;
            if (param1 == "RENAME") {
                RENAME(param2, param3, countries);
            } else if (param1 == "CHANGE_CAPITAL") {
                CHANGE_CAPITAL(param2, param3, countries);
            }
        }
    }
    return 0;
};

#endif //STUDY_C_CAPITALSCOUNTRIES_H
