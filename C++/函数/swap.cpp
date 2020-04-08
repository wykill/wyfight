#include "swap.hpp"

void swap(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return;
}