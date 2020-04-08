#include "Complex.hpp"

inline Complex& __doapl(Complex* ths, const Complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline Complex& 
Complex::operator += (const Complex& r)
{
    return __doapl(this, r);
}

inline Complex
operator+ (const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

inline Complex
operator+ (const Complex& l, double r)
{
    return Complex(l.real() + r, l.imag());
}

inline Complex
operator+ (double l, const Complex& r)
{
    return Complex(l + r.real(), r.imag());
}

inline std::ostream&
operator<< (std::ostream& os, const Complex& comp)
{
    return os << "[" << comp.real() << ", " << comp.imag() << "]";
}