#ifndef _HAT_HPP_
#define _HAT_HPP_
#include "Decrator.hpp"
#include <iostream>

class Hat : public Decrator {
public:
    Hat(Person* p) : Decrator(p) {}
    virtual void show() {
        p_->show();
        ::std::cout << "hat" << ::std::endl;
    }
};

#endif