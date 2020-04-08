#include <iostream>
#include "LibararyMgr.hpp"
using namespace std;

int main()
{
    while (true) {
        LibararyMgr libMgr;
        libMgr.showMenu();
        int select;
        cout << "请输入你的选择：" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            libMgr.loginByStudent();
            break;
        case 2:
            libMgr.loginByTeacher();
            break;
        case 3:
            libMgr.loginByAdmin();
            break;
        default:
            system("read -rsp 'Please Enter to continue...'");
            return 0;
        }
    }
}