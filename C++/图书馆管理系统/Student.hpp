#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include "Person.hpp"
#include <iostream>

class Student : public Person {
public:
    virtual void showMenu();
};

#endif