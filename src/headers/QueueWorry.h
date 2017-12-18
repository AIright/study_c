//
// Created by alright on 17.12.17.
//

/* Люди стоят в очереди, но никогда не уходят из её начала,
 * зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и
 * начинать беспокоиться из-за того, что очередь не продвигается.
 * Реализуйте обработку следующих операций над очередью:
 * WORRY i: пометить i-го человека с начала очереди
 * (в нумерации с 0) как беспокоящегося;
 * QUIET i: пометить i-го человека как успокоившегося;
 * COME k: добавить k спокойных человек в конец очереди;
 * COME -k: убрать k человек из конца очереди;
 * WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 * Изначально очередь пуста.
 * Формат ввода
 * Количество операций Q, затем описания операций.
 * Для каждой операции WORRY i и QUIET i гарантируется,
 * что человек с номером i существует в очереди на момент операции.
 * Для каждой операции COME -k гарантируется, что k не больше текущего
 * размера очереди.
 * Формат вывода
 * Для каждой операции WORRY_COUNT выведите одно
 * целое число — количество беспокоящихся людей в очереди.
 */


#ifndef STUDY_C_QUEUEWORRY_H
#define STUDY_C_QUEUEWORRY_H

#include <iostream>
#include <vector>

using namespace std;

void WORRY(const int& i, vector<string>& v) {
    v[i] = "WORRY";
}

void QUIET(const int& i, vector<string>& v) {
    v[i] = "QUIET";
}

void COME(const int& k, vector<string>& v) {
    if (k > 0) {
        v.resize(v.size() + k, "QUIET");
    } else if (k < 0) {
        v.resize(v.size() + k);
    }
}

void WORRY_COUNT(vector<string>& v) {
    int counter = 0;
    for (auto i : v) {
        if (i == "WORRY") {
            counter++;
        }
    }
    cout << counter << endl;
}


int queue() {
    vector<string> queue;
    string operation;
    int operation_value, operation_counter;
    cin >> operation_counter;
    for (int j = 0; j < operation_counter; j++) {
        cin >> operation;
        if (operation != "WORRY_COUNT") {
            cin >> operation_value;
        } else if (operation == "WORRY_COUNT") {
            WORRY_COUNT(queue);
        }
        if (operation == "WORRY") {
            WORRY(operation_value, queue);
        } else if (operation == "QUIET") {
            QUIET(operation_value, queue);
        } else if (operation == "COME") {
            COME(operation_value, queue);
        }
    }
    return 0;
}

#endif //STUDY_C_QUEUEWORRY_H
