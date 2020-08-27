#include <iostream>
#include <chrono>
#include <random>

using namespace std;

// alias for "typedef"
using msec_t = std::chrono::milliseconds;

class TimeLogger {
    public:
       chrono::steady_clock::time_point start, end;

        void start_log() {
            this->start = chrono::steady_clock::now();
        };

        void end_log() {
            this->end = chrono::steady_clock::now();
        }

        void show_diff(string message) const {
            auto elapsed_ms = chrono::duration_cast<msec_t>(
              this->end - this->start
            );

            cout << message << elapsed_ms.count() << " ms\n";
        }
};

template<typename T = int>
void mix(T*, const int&);

template <typename T = int>
T* generate_arr(const int&, const int&);

template <typename T = int>
void show_arr(T*, const int&);

int gen_random(const int &start, const int &end);

template <typename T = int>
int partition(T *arr, const int &arr_len, const int &low, const int &high);

template <typename T = int>
void swap(T *arr, int start, int end);

template <typename T = int>
void quickSort(T *arr, const int &arr_len);

int main() {
    short arr_len = 100;
    int *arr = generate_arr(arr_len, 100);

    mix(arr, arr_len);

    TimeLogger time_log;
    time_log.start_log();

    quickSort(arr, arr_len);

    cout << "--------------------------" << endl;

    show_arr(arr, arr_len);

    time_log.end_log();
    time_log.show_diff("Test time: ");

    delete[](arr);

    return 0;
}

template <typename T >
void quickSort(T *arr, const int &arr_len) {
    int p_val = arr[arr_len / 2];

    int i = 0;
    int j = arr_len - 1;

    do {
        while (arr[i] < p_val) i++;
        while (arr[j] > p_val) j--;

        if(i <= j) {
            swap(arr, i, j);
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) quickSort(arr, j);
    if(arr_len > i) quickSort(arr + i, arr_len - i);
}

template <typename T>
void swap(T *arr, const int start, const int end) {
    T temp_var = arr[start];
    arr[start] = arr[end];
    arr[end] = temp_var;
}

int gen_random(const int &start, const int &end) {
    std::random_device rd;
    std::mt19937 mt(rd());

    uniform_int_distribution<int> distribution(start, end);

    return distribution(mt);
}

template<typename T>
void mix(T *arr, const int &size) {
    for(int i = 0; i < size; i++) {
        int position = gen_random(0, size);

        int temp_value = *(arr + i);

        arr[i] = arr[position];
        arr[position] = temp_value;
    }
}

template <typename T>
T* generate_arr(const int &size, const int &range) {
    T* arr = new T[size];

    for(int i = 0; i < size; i++) {
        int val = gen_random(0, range);

        arr[i] = val;
    }

    return arr;
}

template <typename T>
void show_arr(T *arr, const int &size) {
    for(int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}