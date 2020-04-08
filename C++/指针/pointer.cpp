#include <iostream>
using namespace std;
int main () {
    int a = 10;
    int *b = NULL;    //空指针
    // *b = 100;
    int *c = (int *)0x1100;
    // b = 0x7ffee72d9a5d;
    cout << "b = " << b << endl;
    // cout << "*b = " << *b << endl;
    cout << "c = " << c << endl;
    cout << "*c = " << *c << endl;
    cout << "the size of int* is " << sizeof(b) << endl;
    cout << "sizeof(char *) is " << sizeof(char *) << endl;
    cout << "sizeof(int *) is " << sizeof(int *) << endl;
    cout << "sizeof(long *) is " << sizeof(long *) << endl;
}