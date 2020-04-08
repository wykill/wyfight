#include "Complex.hpp"
#include <iostream>

using namespace std;

int main()
{
    Complex();
    Complex com1(1, 2);
    Complex com2(3, -6);
    Complex resultCom;
    resultCom = com1 + com2;
    cout << resultCom << endl;
}
