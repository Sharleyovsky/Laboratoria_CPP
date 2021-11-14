//Laboratoria 13.11.2021
#include <iostream>

using namespace std;

const int arraySize = 1024;

int * getRandomArray() {
    int randomArray[arraySize];

    for(int & i : randomArray) {
        i = rand();
    }

    return randomArray;
}

void printExistingNumbers(int min, int max) {
    int *randomArray = getRandomArray();
    int existingNumberCounter = 0;

    for(int i = 0; i < arraySize; i++) {
        int number = randomArray[i];

        if(number >= min && number <= max) {
            cout << "Number: " << number << " index: " << i << endl;
            existingNumberCounter++;
        }
    }

    if(existingNumberCounter == 0) {
        cout << "Numbers from range " << min << "," << max << " have been not found in the array." << endl;
    }
}

int main() {
    int min{0}, max{0};

    cout << "Enter minimal value: ";
    cin >> min;
    cout << "Enter maximal value: ";
    cin >> max;

    printExistingNumbers(min, max);

    return 0;
}
