//
// Created by alright on 19.12.17.
//

#ifndef STUDY_C_BUSSTOPS1_H
#define STUDY_C_BUSSTOPS1_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:
// NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием
// bus и stop_count остановками с названиями stop1, stop2, ...
void NEW_BUS(map<string, vector<string>>& routes, vector<string>& buses) {
    string bus;
    int stop_count;
    cin >> bus >> stop_count;
    vector<string> stops(stop_count);
    for (auto i=0; i<stop_count; i++) {
        cin >> stops[i];
    }
    buses.push_back(bus);
    routes[bus] = stops;
}

/* BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
 * На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов,
 * проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS.
 * Если остановка stop не существует, выведите No stop.
 */
void BUSES_FOR_STOP(map<string, vector<string>>& routes, const vector<string> buses) {
    string stop;
    vector<string>::iterator it;
    int check = 0;
    cin >> stop;
    for (const auto& bus : buses) {
        it = find(routes[bus].begin(), routes[bus].end(), stop);
        if (it != routes[bus].end()) {
            if (check == 0) {
                cout << "Stop " << stop << ": ";
            }
            cout << bus << " ";
            check++;
        }
    }
    if (check == 0) {
        cout << "No stop" << endl;
    } else {
        cout << endl;
    }
}

/* STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов,
 * на которые можно пересесть на каждой из остановок.
 * На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке,
 * в котором они были заданы в соответствующей команде NEW_BUS.
 * Описание каждой остановки stop должно иметь вид
 * Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке,
 * в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus.
 * Если через остановку stop не проезжает ни один автобус, кроме bus,
 * вместо списка автобусов для неё выведите no interchange.
 * Если маршрут bus не существует, выведите No bus.
 */
void STOP_FOR_BUS(map<string, vector<string>>& routes, const vector<string> buses) {
    string bus;
    cin >> bus;
    if (!routes.count(bus)) {
        cout << "No bus" << endl;
    } else {
        vector<string>::iterator it;
        int check = 0;
        for (const auto& stop : routes[bus]) {
            cout << "Stop " << stop << ": ";
            for (const auto& b : buses) {
                if (b != bus) {
                    it = find(routes[bus].begin(), routes[bus].end(), stop);
                    if (it != routes[bus].end()) {
                        cout << bus << " ";
                        check++;
                    }
                }
            }
            if (check == 0) {
                cout << "no interchange" << endl;
            } else {
                cout << endl;
            }
        }
    }
}

/* ALL_BUSES — вывести список всех маршрутов с остановками.
 * На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
 * Описание каждого маршрута bus должно иметь вид
 * Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке,
 * в котором они были заданы в соответствующей команде NEW_BUS.
 * Если автобусы отсутствуют, выведите No buses.
 */
void ALL_BUSES(map<string, vector<string>>& routes) {
    if (routes.size() == 0) {
        cout << "No buses" << endl;
    } else {
        for (const auto& bus : routes) {
            cout << "Bus " << bus.first << ": ";
            for (const auto& stop : bus.second) {
                cout << stop << " ";
            }
            cout << endl;
        }
    }
}

int BusStops1_main() {
    int tries;
    string param1;
    vector<string> buses;
    map<string, vector<string>> routes;
    cin >> tries;
    for (int i=0; i<tries; i++) {
        cin >> param1;
        if (param1 == "ALL_BUSES") {
            ALL_BUSES(routes);
        }
        else if (param1 == "STOP_FOR_BUS") {
            STOP_FOR_BUS(routes, buses);
        }
        else if (param1 == "BUSES_FOR_STOP") {
            BUSES_FOR_STOP(routes, buses);
        }
        else if (param1 == "NEW_BUS") {
            NEW_BUS(routes, buses);
        }
    }
    return 0;
};

#endif //STUDY_C_BUSSTOPS1_H
