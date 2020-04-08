#ifndef _COMPLEX_HPP
#define _COMPLEX_HPP
#include <iostream>
using namespace std;

class Complex {
public:
    Complex (double r = 0, double i = 0) 
        : re(r), im(i)
    { }
    Complex& operator+=(const Complex&);
    double real() const {return re;}
    double imag() const {return im;}

private:
    double re;
    double im;

    friend Complex& __doapl (Complex*, const Complex&);
};

extern inline std::ostream&
operator<< (std::ostream& os, const Complex& comp);

extern inline Complex
operator+ (const Complex& l, const Complex& r);

extern inline Complex
operator+ (const Complex&, double);

extern inline Complex
operator+ (double, const Complex&);

#endif