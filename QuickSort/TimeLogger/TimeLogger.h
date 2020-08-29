//
// Created by user on 29.08.2020.
//

#ifndef QUICKSORT_TIMELOGGER_H
#define QUICKSORT_TIMELOGGER_H

#include <iostream>
#include <chrono>

using msec_t = std::chrono::milliseconds;

class TimeLogger {
public:
    std::chrono::steady_clock::time_point start, end;

    void start_log();
    void end_log();

    void show_diff(std::string message);
};


#endif //QUICKSORT_TIMELOGGER_H
