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
            stringstream fullCommandStream(command);
            string oneCommand;
            fullCommandStream >> oneCommand;
            fullCommandStream.ignore(1);
            if (oneCommand != "Add" && oneCommand != "Del" && oneCommand != "Find" && oneCommand != "Print") {
                cout << "Unknown command: " << oneCommand << endl;
            } else if (oneCommand == "Add") {
                Date date;
                string event, datestring;
                try {
                    fullCommandStream >> datestring >> event;
                    stringstream datestream(datestring);
                    datestream >> date;
                    if (event == "") {
                        throw invalid_argument("Wrong date format: " + datestring);
                    } else {
                        db.AddEvent(date, event);
                    }
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                }
            } else if (oneCommand == "Del") {
                try {
                    Date date;
                    string event;
                    fullCommandStream >> date >> event;
                    if (!event.empty()) {
                        if (db.DeleteEvent(date, event)) {
                            cout << "Deleted successfully" << endl;
                        } else {
                            cout << "Event not found" << endl;
                        }
                    } else {
                        cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                    }
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                }
            } else if (oneCommand == "Find") {

                try {
                    Date date;
                    fullCommandStream >> date;
                    db.Find(date);
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                }
            } else if (oneCommand == "Print") {
                db.Print();
            }
        }
    }
    return 0;
};

/* REAL SOLUTION
 * int main() {
  try {
    Database db;

    string command_line;
    while (getline(cin, command_line)) {
      stringstream ss(command_line);

      string command;
      ss >> command;

      if (command == "Add") {

        string date_str, event;
        ss >> date_str >> event;
        const Date date = ParseDate(date_str);
        db.AddEvent(date, event);

      } else if (command == "Del") {

        string date_str;
        ss >> date_str;
        string event;
        if (!ss.eof()) {
          ss >> event;
        }
        const Date date = ParseDate(date_str);
        if (event.empty()) {
          const int count = db.DeleteDate(date);
          cout << "Deleted " << count << " events" << endl;
        } else {
          if (db.DeleteEvent(date, event)) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        }

      } else if (command == "Find") {

        string date_str;
        ss >> date_str;
        const Date date = ParseDate(date_str);
        for (const string& event : db.Find(date)) {
          cout << event << endl;
        }

      } else if (command == "Print") {

        db.Print();

      } else if (!command.empty()) {

        throw logic_error("Unknown command: " + command);

      }
    }
  } catch (const exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}
 */