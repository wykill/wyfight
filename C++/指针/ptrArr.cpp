#include <iostream>
// #include <stdio.h>
using namespace std;

int main () {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int * ptr = arr;
    char* ptrChar = (char *)ptr;
    char letter = 'a';
    char * lptr = &letter;
    // cout << "sizeof ptr is " << sizeof(*ptrChar) << endl;
    cout << "ptr is " << ptr << endl;
    cout << "ptrChar is " << ptrChar << endl;
    cout << "lptr is " << lptr << endl;
    cout << "*lptr is " << *lptr << endl;
    cout << "Char is " << '1' << endl;
    cout << "sizeof(int) is " << sizeof(int) << endl;
    cout << (ptrChar[0] == 0x01) << endl;
    cout << "*(ptr+4) is " << *(ptr + 4) << endl;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        cout << *ptr << endl;
        ptr++;
    }
    cout << *ptr << endl;   //shu
    ptr++;
    ptrChar = (char *)ptr;
    cout << ptrChar[0] << endl;
    cout << *ptr << endl;

    // cout << "ptrChar is " << ptrChar << endl;
    // ptr++;
    // cout << "arr[1] is " << *ptr << endl;
    return 0;
}