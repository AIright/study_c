//
// Created by alright on 13/01/2018.
//

#ifndef STUDY_C_TIMESERVER_H
#define STUDY_C_TIMESERVER_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
        } catch (system_error&) {
        }
        return LastFetchedTime;
    };
private:
    string LastFetchedTime = "00:00:00";
};

#endif //STUDY_C_TIMESERVER_H
