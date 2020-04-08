//
//  main.cpp
//  newOperator
//
//  Created by 吴亿 on 2020/1/29.
//  Copyright © 2020 吴亿. All rights reserved.
//

#include <iostream>
using namespace std;

class addClass
{
friend ostream& operator<< (ostream& out, addClass ac);
public:
    addClass(int num) : m_Num(num) {}
    addClass& operator++() {
        m_Num++;
        return *this;
    }
    
    addClass operator++(int) {
        addClass ac = *this;
        m_Num++;
        return ac;
    }
    
    addClass operator+ (addClass& ac) {
        addClass tmp(m_Num);
        tmp.m_Num += ac.m_Num;
        return tmp;
    }

    int m_Num;
};

ostream& operator<< (ostream& out, addClass ac) {
    out << ac.m_Num;
    return out;
}

void test01() {
    addClass ac(100);
    cout << ++(++ac) << endl;
    cout << ac << endl;
}

void test02() {
    addClass ac(100);
    cout << (ac++)++ << endl;
    cout << ac << endl;
}

void test03() {
    addClass ac1(100);
    addClass ac2(200);
    addClass ac3(300);
    cout << ac1 + ac2 + ac3 << endl;
    cout << ac1 << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //test01();
    //test02();
    test03();
    //int a = 10;
    //cout << ++(++a) + (a++) + ++(++a) << endl;
    return 0;
}
