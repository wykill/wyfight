#include <iostream>
using namespace std;

int main () {
    for (int firstNum = 1; firstNum < 10; firstNum++) {
        for (int secondNum = 1; secondNum <= firstNum; secondNum++) {
            cout << secondNum << " * " << firstNum<< " = " << firstNum * secondNum << "\t";
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}