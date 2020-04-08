#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    const int *p = &a;
    p = &b;
    int * const ptr = &a;
    *ptr = b;
    return 0; 
}