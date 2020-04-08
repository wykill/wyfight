#pragma once
#include "Worker.hpp"

class Employee : public Worker {
public:
    Employee(int id, string name, int Did);

    void showInfo();

    string getDeptName();

    string showDepDesc();
};