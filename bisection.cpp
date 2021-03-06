#include <iostream>
#include <functional>
#include <chrono>

using namespace std;

void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

int findNumber(int *arr, int left, int right, int number) {
    if(left > right) {
        cout << "The number you were looking for doesn't exist in this array! \n";
        return 0;
    }

    int mid = (left + right) / 2;

    if(arr[mid] == number) {
        return number;
    }

    if(arr[mid] < number) {
        left = mid + 1;
        return findNumber(arr, left, right, number);
    }

    right = mid - 1;
    return findNumber(arr, left, right, number);
}

void measureFunctionTime(int *arr, int left, int right, int number, const function<int(int*, int, int, int)>& callback) {
    auto start = chrono::high_resolution_clock::now();
    int output = callback(arr, left, right, number);
    auto finish = chrono::high_resolution_clock::now();
    cout << "Output: " << output << endl;
    cout << "Time elapsed: " << chrono::duration_cast<chrono::nanoseconds>(finish-start).count() << " nanoseconds\n";
}

int main() {
    int size{0}, number{0};
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the number you are looking for from 1 to " << size << ": ";
    cin >> number;

    int *arr = new int[size];
    fillArray(arr, size);

    int left{0}, right{size - 1};
    measureFunctionTime(arr, left, right, number, &findNumber);
}