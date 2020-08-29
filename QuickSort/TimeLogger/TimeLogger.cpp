//
// Created by user on 29.08.2020.
//

#include <iostream>
#include <chrono>

#include "TimeLogger.h"

using namespace std;

// alias for "typedef"
using msec_t = std::chrono::milliseconds;

void TimeLogger::start_log() {
    this->start = chrono::steady_clock::now();
}

void TimeLogger::end_log() {
    this->end = chrono::steady_clock::now();
}

void TimeLogger::show_diff(string message) {
    auto elapsed_ms = chrono::duration_cast<msec_t>(
            this->end - this->start
    );

    cout << "--------------------------" << endl;
    cout << message << elapsed_ms.count() << " ms\n";
    cout << "--------------------------" << endl;
}