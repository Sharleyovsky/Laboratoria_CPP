//Laboratoria 13.11.2021
#include <iostream>
#include <vector>

using namespace std;

vector<int32_t> getRandomVector(int vectorSize) {
    vector<int32_t> randomVector;

    randomVector.reserve(vectorSize);

    for(int i = 0; i < vectorSize; i++) {
        randomVector.push_back(rand());
    }

    return randomVector;
}

void printExistingNumbers(int min, int max, int vectorSize) {
    vector<int32_t> randomVector = getRandomVector(vectorSize);
    int existingNumberCounter = 0;

    for(int i = 0; i < vectorSize; i++) {
        int number = randomVector[i];

        if(number >= min && number <= max) {
            cout << "Number: " << number << " index: " << i << endl;
            existingNumberCounter++;
        }
    }

    if(existingNumberCounter == 0) {
        cout << "Numbers from range " << min << "," << max << " have been not found in the vector." << endl;
    }
}

int main() {
    int min{0}, max{0}, vectorSize{0};

    cout << "Enter vector size:";
    cin >> vectorSize;
    cout << "Enter minimal value:";
    cin >> min;
    cout << "Enter maximal value:";
    cin >> max;

    printExistingNumbers(min, max, vectorSize);

    return 0;
}
