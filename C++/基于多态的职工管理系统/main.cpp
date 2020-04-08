#include "WorkerMgr.hpp"
#include "Employee.hpp"

int main() {
    WorkerMgr wm;
    int select;
    
    while (true) {
        system("clear");
        wm.showMenu();
        // Worker * worker = new Employee(1, "wuyi", 2);
        // worker->showInfo();
        cout << "请输入你的选择：" << endl;
        cin >> select;
        switch (select) {
            case 0:    //退出系统
                wm.quitSystem();
                break;
            case 1:    //增加职工
                wm.addEmployee();
                break;
            case 2:    //显示职工
                wm.showEmpList();
                break;
            case 3:    //删除职工
                wm.deleteEmp();
                break;
            case 4:    //修改职工
                wm.modEmp();
                break;
            case 5:    //查找职工
                wm.findEmp();
                break;
            case 6:    //排序
                wm.sortList();
                break;
            case 7:    //清空文件
                wm.emptyList();
                break;
            default:   //其他
                cout << "输入有误，请重新输入！" << endl;
                system("read -rsp 'Please Enter to continue...'");
                break;
        }
    }
    return 0;
}