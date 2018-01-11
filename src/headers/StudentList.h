//
// Created by alright on 10.01.18.
//

#ifndef STUDY_C_STUDENTLIST_H
#define STUDY_C_STUDENTLIST_H

/* Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
 * Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.
 * Формат ввода
 * Первая строка содержит одно целое число N от 0 до 10000 — число студентов.
 * Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов
 * — имя и фамилию очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.
 * Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.
 * Следующие M строк содержат строку длиной от 1 до 15 символов — запрос,
 * и целое число от 0 до 1000000000 — номер студента (нумерация начинается с 1).
 * Формат вывода
 * Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.
 * Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.
 * Для остальных запросов выведите bad request.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct student {
    string name;
    string surname;
    int bday;
    int bmonth;
    int byear;
};


int StudentList_main() {
    vector<student> students;
    int input_tries = 0;
    int output_tries = 0;
    cin >> input_tries;
    for (int i=0; i<input_tries; i++) {
        student buf;
        cin >> buf.name >> buf.surname >> buf.bday >> buf.bmonth >> buf.byear;
        students.push_back(buf);
    }
    cin >> output_tries;
    int size = students.size();
    for (int i=0; i<output_tries; i++) {
        string command;
        int number;
        cin >> command >> number;
        if ((command != "name" && command != "date") || number <= 0 || number > size ) {
            cout << "bad request" << endl;
        } else if (command == "name") {
            cout << students[number - 1].name << " "
                 << students[number - 1].surname << endl;
        } else if (command == "date") {
            cout << students[number - 1].bday << '.'
                 << students[number - 1].bmonth << '.'
                 << students[number - 1].byear << endl;
        }
    }
    return 0;
}

#endif //STUDY_C_STUDENTLIST_H
