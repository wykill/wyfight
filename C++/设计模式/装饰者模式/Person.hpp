#ifndef _PERSON_HPP_
#define _PERSON_HPP_
#include <iostream>

class Person {
public:
    virtual void show() {
        ::std::cout << "person" << ::std::endl;
    };
};

#endif