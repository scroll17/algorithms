//
// Created by user on 27.08.2020.
//

#ifndef QUICKSORT_FUNCTIONS_H
#define QUICKSORT_FUNCTIONS_H

int gen_random(const int &start, const int &end);

template<typename T>
void mix(T*, const int&);

template <typename T>
void show_arr(T*, const int&, const int&);

template <typename T>
T* generate_arr(const long&, const int&);

#endif //QUICKSORT_FUNCTIONS_H
