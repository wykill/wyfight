#include <iostream>
#include "Person.hpp"
#include "Boy.hpp"
#include "Decrator.hpp"
#include "Hat.hpp"
#include "Clothes.hpp"

int main()
{
    // Person* xiaoming = new Boy();
    // Decrator* dec = new Decrator(xiaoming);
    // Hat* hat = new Hat(dec);
    // Clothes* clothes = new Clothes(hat);
    // clothes->show();
    int a = 10;
    double b = 20;
    double d = a / b;
    std::cout << d << std::endl;
    return 0;
}