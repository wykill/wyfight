#include <iostream>
#include <string>
#include "CircleLinkList.h"
#include "CircleLinkList.cpp"    // 模版情况下需要包含cpp文件，编译期！！不然会出现编译错误

struct Person {
    Person() : m_name(""), m_age(0) {}
    Person(::std::string name, int age) : m_name(name), m_age(age) {}
    ::std::string m_name;
    int m_age;
};

::std::ostream& operator<< (::std::ostream& os, Person per)
{
    os << "name is " << per.m_name << ", age is " << per.m_age << ::std::endl;
    return os;
}

bool operator== (Person const& per1, Person const& per2)
{
    return (per1.m_name == per2.m_name && per1.m_age == per2.m_age);
}

template <typename T>
void printList(CircleLinkList<T> const& list)
{
    ::std::cout << "-----------------" << ::std::endl;
    list.print(9);
    ::std::cout << "listSize is " << list.size() << ::std::endl;
}

void test01()
{
    CircleLinkList<int> list= CircleLinkList<int>();
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(2);
    printList(list);

    LinkNode<int>* node = list.findVal(4);
    if (node == NULL) {
        ::std::cout << "not find value" << ::std::endl;
    } else {
    ::std::cout << "findNode, val is " << node->value << ::std::endl;

    }

    list.erase(4);
    list.erase(0);
    printList(list);

    list.deleteAll();
    printList(list);
}

void test02()
{
    CircleLinkList<Person> list= CircleLinkList<Person>();
    list.insert(Person("aaa", 10));
    list.insert(Person("bbb", 20));
    list.insert(Person("ccc", 30));
    list.insert(Person("ddd", 40));
    list.insert(Person("aaa", 20));
    list.insert(Person("bbb", 10));
    printList(list);

    LinkNode<Person>* node = list.findVal(Person("aaa", 20));
    if (node == NULL) {
        ::std::cout << "not find value" << ::std::endl;
    } else {
    ::std::cout << "findNode, val is " << node->value << ::std::endl;

    }

    list.erase(4);
    list.erase(0);
    printList(list);

    list.deleteAll();
    printList(list);
}

// 约瑟夫问题
void test03()
{
    CircleLinkList<Person> list= CircleLinkList<Person>();
    list.insert(Person("aaa", 10));
    list.insert(Person("bbb", 20));
    list.insert(Person("ccc", 30));   
    list.insert(Person("ddd", 40));
    list.insert(Person("eee", 20));
    list.insert(Person("fff", 10));
    int start = 0;
    while (list.size() != 1) {
        start = list.erase(start, 2);    // c->f->d->b->e   
    }
    printList(list);
}

int main()
{
    // test01();
    // test02();
    test03();
    // ::std::cout << "hello world" << ::std::endl;
    return 0;
}