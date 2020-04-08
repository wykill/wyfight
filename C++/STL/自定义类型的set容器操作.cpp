#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Person {
public:
    Person (::std::string name, int age) : m_name(name), m_age(age)
    {}
    // bool operator<(Person const& p) {
    //     return m_age < p.m_age;
    // }
    ::std::string m_name;
    int m_age;
};

class MyCompare {
public:
    bool operator()(Person const& p1, Person const& p2) const {
        return p1.m_age > p2.m_age;
    }
};

class MyCompare2 {
public:
    bool operator()(int p1, int p2) const {
        return p1 > p2;
    }
};

void printSet(set<Person, MyCompare > const& pSet) 
{
    for (set<Person>::iterator it = pSet.begin(); it != pSet.end(); it++) {
        cout << "name is " << it->m_name << ", age is " << it->m_age << endl; 
    }
}

void printISet(set<int, MyCompare2 > const& iSet) {
    for (set<int>::iterator it = iSet.begin(); it != iSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() 
{   
    Person p1("zhangsan", 10);
    Person p2("lisi", 20);
    Person p3("wangwu", 30);
    Person p4("wy", 40);
    Person p5("demo", 50);
    set<Person, MyCompare> pSet;
    
    pSet.insert(p1);
    pSet.insert(p2);
    pSet.insert(p3);
    pSet.insert(p4);
    pSet.insert(p5);
    
    printSet(pSet);
    
    set<int, MyCompare2> iSet;
    for (int i = 0; i < 10; i++) {
        iSet.insert(i);
    }
    printISet(iSet);
}

int main() {
    test01();
    return 0;
}