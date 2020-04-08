#ifndef _DECRATOR_HPP_
#define _DECRATOR_HPP_
#include "Person.hpp"
#include <iostream>

class Decrator : public Person {
public:
    Decrator(Person* p) : p_(p) {}
    virtual void show() {
        p_->show();
        ::std::cout << "Decrator" << ::std::endl;
    }
protected:
    Person* p_;
};

#endif