//
// Created by alright on 16/01/2018.
//

#include "FinalTask.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>

int read_command() {
    Database db;
    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
        if (!command.empty()) {
            stringstream command1(command);
            string com;
            command1 >> com;
            if (com != "Add" && com != "Del" && com != "Find" && com != "Print") {
                cout << "Unknown command: " << com << endl;
            } else if (com == "Add") {
                Date date;
                string event;
                try {
                    command1 >> date >> event;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                }
                db.AddEvent(date, event);
            } else if (com == "Del") {
                Date date;
                string event;
                try {
                    command1 >> date >> event;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                }
                if (!event.empty()) {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
            } else if (com == "Find") {
                Date date;
                try {
                    command1 >> date;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                }
                db.Find(date);
            } else if (com == "Print") {
                db.Print();
            }
        }
    }
    return 0;
}