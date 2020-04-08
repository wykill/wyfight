#pragma once
#include "Worker.hpp"

class Manager : public Worker {
public:
    Manager(int id, string name, int Did);

    void showInfo();

    string getDeptName();

    string showDepDesc();
};