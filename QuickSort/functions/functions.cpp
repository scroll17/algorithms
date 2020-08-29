//
// Created by user on 27.08.2020.
//

#include <iostream>
#include <random>

#include "functions.h"

using namespace std;

template <typename T>
void show_arr(T *arr, const int &from, const int &to) {
    for(int i = from; i < to; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

template void show_arr(int *arr, const int&, const int&);
template void show_arr(long *arr, const int&, const int&);
template void show_arr(short *arr, const int&, const int&);

/** ----------------------------------------------------- */

int gen_random(const int &start, const int &end) {
    std::random_device rd;
    std::mt19937 mt(rd());

    uniform_int_distribution<int> distribution(start, end);

    return distribution(mt);
}

/** ----------------------------------------------------- */

template <typename T>
T* generate_arr(const long &size, const int &range) {
    T* arr = new T[size];

    for(int i = 0; i < size; i++) {
        int val = gen_random(0, range);

        arr[i] = val;
    }

    return arr;
}

template int* generate_arr(const long&, const int&);
template long* generate_arr(const long&, const int&);
template short* generate_arr(const long&, const int&);

/** ----------------------------------------------------- */

template<typename T>
void mix(T *arr, const int &size) {
    for(int i = 0; i < size; i++) {
        int position = gen_random(0, size);

        int temp_value = *(arr + i);

        arr[i] = arr[position];
        arr[position] = temp_value;
    }
}
