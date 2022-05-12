#include <iostream>
#include <functional>
#include <chrono>

using namespace std;

void fillArray(int *arr, int size) {
    srand(time(nullptr));
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = rand() % 100;
    }
}

void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = false;

        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

void measureFunctionTime(int *arr, int size, const function<void(int*, int)>& callback) {
    auto start = chrono::high_resolution_clock::now();
    callback(arr, size);
    auto finish = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    cout << "Time elapsed: " << chrono::duration_cast<chrono::seconds>(finish-start).count() << " seconds\n";
}

int main() {
    int size{0};
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    fillArray(arr, size);
    measureFunctionTime(arr, size, &sortArray);
}