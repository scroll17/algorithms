#include <iostream>

#include "functions/functions.h"
#include "TimeLogger/TimeLogger.h"

using namespace std;

template <typename T = int>
int partition(T *arr, const int &low, const int &high);

template <typename T = int>
int partition_v2(T *arr, const int &low, const int &high);

template <typename T = int>
void swap(T *arr, int start, int end);

template <typename T = int>
void quickSort(T *arr, const int&, const int&);

int main() {
    long arr_len = 1'000'000;

    TimeLogger time_log;

    // ------------------------------------------------
    time_log.start_log();
    short *arr = generate_arr<short>(arr_len, 10);

    time_log.end_log();
    time_log.show_diff("Gen arr time: ");

    // ------------------------------------------------
    time_log.start_log();
    quickSort<short>(arr, 0, arr_len - 1);

    time_log.end_log();
    time_log.show_diff("Sort time: ");

    // ------------------------------------------------
    show_arr<short>(arr, 0, 10);

    delete[](arr);

    return 0;
}

template <typename T>
int partition(T *arr, const int &low, const int &high) {
    T pivot = arr[high];

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return (i + 1);
}

template <typename T>
int partition_v2(T *arr, const int &low, const int &high) {
    int i = low;
    int j = high + 1;

    while (true) {
        while (arr[++i] < arr[low]) {
            if ( i == high ) break;
        }

        while (arr[--j] > arr[low]) {
            if ( j == low ) break;
        }

        if (i >= j) break;
        swap(arr, i, j);
    }

    swap(arr, low, j);
    return j;
}

template <typename T >
void quickSort(T *arr, const int &low, const int &high) {
    if(low >= high) return;

    int pi = partition_v2(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

template <typename T>
void swap(T *arr, const int start, const int end) {
    T temp_var = arr[start];
    arr[start] = arr[end];
    arr[end] = temp_var;
}