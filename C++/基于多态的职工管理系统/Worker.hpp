#pragma once
#include <string>
#include <iostream>
using namespace std;
class Worker {
public:
    virtual void showInfo() = 0;
    virtual string showDepDesc() = 0;
    virtual string getDeptName() = 0;
    virtual ~Worker() {}

    int m_id;
    string m_name;
    int m_dId;
};