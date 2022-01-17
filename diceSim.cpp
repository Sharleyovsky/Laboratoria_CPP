//Laboratoria 28.11.2021

#include <iostream>
#include <vector>
#include <random>

using namespace std;

int getRandomNumber(int min, int max) {
    int range = max - min + 1;

    return rand() % range + min;;
}

vector<int32_t> getNumbersToThrow(int throwsAmount) {
    vector<int32_t> numbers;
    numbers.reserve(throwsAmount);

    for(int i = 0; i < throwsAmount; i++) {
        int number = getRandomNumber(0, 6);
        numbers.push_back(number);
    }

    return numbers;
}

void throwDice(int throwsAmount) {
    vector<int32_t> numbers = getNumbersToThrow(throwsAmount);

    for (int i = 0; i < throwsAmount; i++) {
        int winningNumber = getRandomNumber(0, 6);
        string result = "LOST";

        if(winningNumber == numbers[i]) {
            result = "WON";
        }

        cout << "Dice " << "number " << i + 1 << " landed on "
             << numbers[i] << " winning number: " << winningNumber
             << " result: " << result << endl;
    }
}

int main() {
    int throwsAmount{0};

    cout << "Please enter how many times dice should be thrown:";
    cin >> throwsAmount;

    if(throwsAmount < 1) {
        cout << "The number has to be bigger than 0!" << endl;
        return 0;
    }

    throwDice(throwsAmount);
    return 0;
}

