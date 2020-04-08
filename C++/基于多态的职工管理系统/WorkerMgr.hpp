// #ifndef __WORKERMGR__HPP
// #define __WORKERMGR__HPP
#pragma once
#include <iostream>
#include <fstream>
#include "Worker.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Boss.hpp"
using namespace std;

#define FILENAME "EmpSystem.txt"

class WorkerMgr {
public:
    WorkerMgr();

    void showMenu();

    void initWorker(int num);

    int getWorkerNum();

    void quitSystem();

    void addEmployee();

    void showEmpList();

    void deleteEmp();

    void modEmp();

    void findEmp();

    void sortList();

    void emptyList();

    int isExist(int id);

    void save();
    
    ~WorkerMgr();

private:
    Worker** m_workerArr;
    int m_workerNum;
};

// #endif