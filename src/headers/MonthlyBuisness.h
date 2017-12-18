// Created by alright on 17.12.17.
//
/* У каждого из нас есть ежемесячные дела, каждое из которых
 * нужно выполнять в конкретный день каждого месяца:
 * оплата счетов за электричество, абонентская плата за связь и пр.
 * Вам нужно реализовать работу со списком таких дел, а именно,
 * обработку следующих операций:
 * ADD i s
 * Добавить дело с названием s в день i.
 * NEXT
 * Закончить текущий месяц и начать новый.
 * Если новый месяц имеет больше дней, чем текущий,
 * добавленные дни изначально не будут содержать дел.
 * Если же в новом месяце меньше дней,
 * дела со всех удаляемых дней необходимо будет переместить
 * на последний день нового месяца.
 * Обратите внимание, что количество команд этого типа
 * может превышать 11.
 * DUMP i
 * Вывести все дела в день i.
 * Изначально текущим месяцем считается январь.
 * Количества дней в месяцах соответствуют Григорианскому
 * календарю с той лишь разницей, что в феврале всегда 28 дней.
 * Указание
 * Для дописывания всех элементов вектора v2 в конец вектора v1
 * удобно использовать метод insert:
 * v1.insert(end(v1), begin(v2), end(v2));
 * Формат ввода
 * Сначала число операций Q, затем описания операций.
 * Названия дел s уникальны и состоят только из латинских букв,
 * цифр и символов подчёркивания. Номера дней i являются целыми
 * числами и нумеруются от 1 до размера текущего месяца.
 * Формат вывода
 * Для каждой операции типа DUMP в отдельной строке выведите
 * количество дел в соответствующий день,
 * а затем их названия, разделяя их пробелом.
 * Порядок вывода дел в рамках каждой операции значения не имеет.
 */

#ifndef STUDY_C_MONTHLYBUISNESS_H
#define STUDY_C_MONTHLYBUISNESS_H

#include <iostream>
#include <vector>

using namespace std;

// Добавить дело с названием s в день i.
void ADD(const string& s, const int& day, vector<vector<string>>& month) {
    if (day > 0 && day <= month.size()) {
       month[day - 1].push_back(s);
    }
}

// Закончить текущий месяц и начать новый.
// Если новый месяц имеет больше дней, чем текущий, добавленные
// дни изначально не будут содержать дел.
// Если же в новом месяце меньше дней,
// дела со всех удаляемых дней необходимо будет
// переместить на последний день нового месяца.
void NEXT(int& current_month, const vector<int>& months_days, vector<vector<string>>& month) {
    // Если месяц 12й, то сбрасываем на 1
    if (current_month == 11) {
        current_month = 0;
    } else {
        current_month++;
    }
    // Если текущий месяц дольше следующего,
    // то перекидываем последние дела текущего месяца в конец следующего
    // иначе, просто увеличиваем число дней
    if (month.size() > months_days[current_month]) {
        int new_days = months_days[current_month] - 1; // индекс последнего дня
        int difference = month.size() - months_days[current_month];
        for (int i = 0; i < difference; i++) {
            month[new_days].insert(end(month[new_days]),
            begin(month[month.size() - 1 - i]), end(month[month.size() - 1 - i]));
        }
    }
    month.resize(months_days[current_month]);
}

// Вывести все дела в день i.
void DUMP(const vector<vector<string>>& daily_buisness, const int& day) {
    if (day > 0) {
        cout << daily_buisness[day - 1].size() << " ";
        for (auto k : daily_buisness[day - 1]) {
            cout << k << " ";
        }
    }
    cout << endl;
}

int MonthlyBuisness() {
    vector<vector<string>> month(31);
    vector<int> months_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    int operation_counter, day;
    string operation, buisness;
    cin >> operation_counter;
    for (int i = 0; i < operation_counter; i++) {
        cin >> operation;
        if (operation == "ADD" || operation == "DUMP") {
            cin >> day;
            if (operation == "ADD") {
                cin >> buisness;
                ADD(buisness, day, month);
            } else {
                DUMP(month, day);
            }
        } else if (operation == "NEXT") {
            NEXT(current_month, months_days, month);
        }
    }

    return 0;
};

#endif //STUDY_C_MONTHLYBUISNESS_H
