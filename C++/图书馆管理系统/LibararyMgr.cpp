#include "LibararyMgr.hpp"
#include <iostream>
using namespace std;

void LibararyMgr::showMenu() {
    cout << "1. 学生用户登陆" << endl;
    cout << "2. 教师用户登陆" << endl;
    cout << "3. 管理员用户登陆" << endl;
    cout << "0. 退出登陆" << endl;
}

void LibararyMgr::loginByStudent() 
{
    cout << "loginByStudent" << endl;
}

void LibararyMgr::loginByTeacher()
{
    cout << "loginByTeacher" << endl;
}

void LibararyMgr::loginByAdmin()
{
    cout << "loginByAdmin" << endl;
}