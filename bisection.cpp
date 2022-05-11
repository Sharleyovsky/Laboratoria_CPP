#include <iostream>
#include <ctime>
#include <functional>

using namespace std;

void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void measureFunctionTime(int *arr, int left, int right, int number, function<int(int*, int, int, int)> callback) {
    time_t begin, end;
    time(&begin);
    int output = callback(arr, left, right, number);
    cout << "Output: " << output << endl;
    time(&end);
    time_t elapsed = end - begin;
    printf("Time measured: %lld seconds.\n", elapsed);
}

// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// 0 + 9 = 9 // 2 = 4

int findNumber(int *arr, int left, int right, int number) {
    if(left > right) {
        cout << "Nie znaleziono danej liczby!" << endl;
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