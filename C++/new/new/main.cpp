//
//  main.cpp
//  new
//
//  Created by 吴亿 on 2020/1/15.
//  Copyright © 2020 吴亿. All rights reserved.
//

#include <iostream>
using namespace std;

int* func() {
    int *p = new int(10);
    return p;
}

void test() {
    int *pointer = func();
    cout << *pointer << endl;
    cout << *pointer << endl;
    cout << *pointer << endl;
    cout << "before delete:pointer address is " << pointer << endl;
    delete pointer;
    
    cout << "after delete:pointer address is " << pointer << endl;
    cout << *pointer << endl;
    
    cout << "after delete:pointer address is " << pointer << endl;
    cout << *pointer << endl;
    
    cout << "after delete:pointer address is " << pointer << endl;
    cout << *pointer << endl;
}

void test02() {
    int *p = new int[10];
    cout << "sizeof int* is " << sizeof(p) << endl;
    cout << "sizeof int is " << sizeof(int) << endl;
    for (int i = 0; i < 10; i++) {
        p[i] = i + 100;
    }
    for (int i = 0; i < 10; i++) {
        cout << p[i] << endl;
    }
    delete[] p;
    //delete[] p;
    cout << "after delete[]: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << p[i] << endl;
    }
    cout << "*p is " << *p << endl;
    cout << "*p+1 is " << *(p + 1) << endl;
    cout << "*p+10 is " << *(p + 10) << endl;
}

int funcTest(int a, int b = 10);

int funcTest(int a = 10, int b) {
    return a + b;
}

int main(int argc, const char * argv[]) {
    test02();
    cout << funcTest() << endl;
    //int &a = 10;
    //cout << "&a is " << a << endl;
    return 0;
}


