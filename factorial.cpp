#include <iostream>

using namespace std;

long long getFactorial(int number) {
    if(number < 0) {
        cout << "Number can't be lower than 0!" << endl;
    }

    if(number < 2) {
        return 1;
    }

    return number * getFactorial(number - 1);
};

int main() {
    int number;

    cout << "Enter the number to get a factorial:";
    cin >> number;
    cout << "The result is: " << getFactorial(number) << endl;

    return 0;
}
