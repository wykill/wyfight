#pragma once
#include "Worker.hpp"

class Boss : public Worker {
public:
    Boss(int id, string name, int Did);

    void showInfo();

    string getDeptName();

    string showDepDesc();
};