#ifndef _CLOTHES_HPP_
#define _CLOTHES_HPP_
#include "Decrator.hpp"
#include <iostream>

class Clothes : public Decrator {
public:
    Clothes(Person* p) : Decrator(p) {}
    virtual void show() {
        p_->show();
        ::std::cout << "clothes" << ::std::endl;
    }
};

#endif