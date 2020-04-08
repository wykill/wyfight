#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person {
public:
    Person(std::string const& name, int age) : m_name(name), m_age(age)
    {
    }

    ::std::string m_name;
    int m_age;
};

class MyCompare {
public:
    bool operator()(Person const& p1, Person const& p2) const {
        return p1.m_age > p2.m_age;
    }
};

void printMap(map<Person, ::std::string, MyCompare> const& pMap)
{
    for (map<Person, ::std::string>::const_iterator it = pMap.begin(); it != pMap.end(); it++) {
        cout << "Person name is " << it->first.m_name << ", Person age is " << it->first.m_age << endl;
    }
}

void test01() 
{
    Person p1("zhangsan", 10);
    Person p2("lisi", 20);
    Person p3("wangwu", 30);
    Person p4("wy", 40);
    Person p5("demo", 50);
    map<Person, ::std::string, MyCompare> perContainer;
    perContainer.insert(make_pair(p1, p1.m_name));
    perContainer.insert(make_pair(p2, p2.m_name));
    perContainer.insert(make_pair(p3, p3.m_name));
    perContainer.insert(make_pair(p4, p4.m_name));
    perContainer.insert(make_pair(p5, p5.m_name));
    printMap(perContainer);
}

int main () {
    test01();
    return 0;
}