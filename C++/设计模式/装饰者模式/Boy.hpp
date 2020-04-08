#ifndef _BOY_HPP_
#define _BOY_HPP_
#include <iostream>
#include "Person.hpp"

class Boy : public Person {
    virtual void show() {
        ::std::cout << "This is Boy!" << ::std::endl;
    }
};

#endif