#include "WorkerMgr.hpp"

WorkerMgr::WorkerMgr() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在！" << endl;
        ifs.close();
        this->m_workerNum = 0;
        this->m_workerArr = NULL;
        return;
    }
    char letter;
    ifs >> letter;
    if (ifs.eof()) {
        cout << "文件内容为空！" << endl;
        ifs.close();
        this->m_workerNum = 0;
        this->m_workerArr = NULL;
        return;
    }
    ifs.close();

    int num = getWorkerNum();
    this->m_workerNum = num;
    initWorker(num);
}

void WorkerMgr::showMenu() 
{
    cout << "---------------------------------" << endl;
    cout << "-------欢迎使用职工管理系统-----" << endl;
    cout << "---------1. 增加职工信息 -------" << endl;
    cout << "---------2. 显示职工信息 -------" << endl;
    cout << "---------3. 删除职工信息 -------" << endl;
    cout << "---------4. 修改职工信息 -------" << endl;
    cout << "---------5. 查找职工信息 -------" << endl;
    cout << "---------6. 按照编号排序 -------" << endl;
    cout << "---------7. 清空所有文档 -------" << endl;
    cout << "---------8. 退出管理系统 -------" << endl;
    cout << "---------------------------------" << endl;
}

void WorkerMgr::initWorker(int num)
{
    m_workerArr = new Worker*[num];
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id, dId;
    string name;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker * worker = NULL;
        switch (dId) {
            case 1:
                worker = new Employee(id, name, dId);
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
            default:
                break;
        }
        m_workerArr[index] = worker;
        index++;
    }
}

int WorkerMgr::getWorkerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;
    int id, dId;
    string name;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }
    ifs.close();
    return num;
}

void WorkerMgr::quitSystem() 
{
    cout << "欢迎下次光临" << endl;
    system("read -rsp $'Press enter to continue...\n'");
    exit(0);
}

void WorkerMgr::addEmployee()
{
    int num;
    int newSize = 0;
    cout << "请输入要添加员工数量："  << endl;
    cin >> num;
    if (num > 0) {
        newSize = this->m_workerNum + num;
    }
    else {
        cout << "输入有误！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    Worker** workerArr = new Worker*[newSize];

    if (this->m_workerArr != NULL) {
        for (int i = 0; i < this->m_workerNum; i++) {
            workerArr[i] = this->m_workerArr[i];
        }
    }
    for (int i = 0; i < num; i++) {
        int id, dId;
        string name;
        Worker * worker = NULL;
        cout << "请输入第" << i + 1 << "个员工的编号：" << endl;
        cin >> id;
        cout << "请输入第" << i + 1 << "个员工的姓名：" << endl;
        cin >> name;
        cout << "请输入第" << i + 1 << "个员工的岗位：" << endl;
        cout << "1. 普通职工" << endl;
        cout << "2. 经理" << endl;
        cout << "3. 老板" << endl;
        cin >> dId;
        switch (dId) {
            case 1:
                worker = new Employee(id, name, dId);
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
            default:
                break;
        }
        workerArr[this->m_workerNum + i] = worker;
    }
    delete [] this->m_workerArr;
    this->m_workerArr = workerArr;
    this->m_workerNum = newSize;
    this->save();
    cout << "添加成功！" << endl;
    system("read -rsp 'Please Enter to continue...'");
}

void WorkerMgr::showEmpList() 
{
    if (m_workerNum <= 0) {
        cout << "系统中没有数据！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    for (int i = 0; i < m_workerNum; i++) {
        m_workerArr[i]->showInfo();
    }
    system("read -rsp 'Please Enter to continue...'");
}

void WorkerMgr::deleteEmp() 
{
    int id;
    cout << "请输入需要查找的编号：" << endl;
    cin >> id;
    int ret = isExist(id);
    if (ret == -1) {
        cout << "删除失败，查无此人！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    for (int i = ret; i < m_workerNum - 1; i++) {
        m_workerArr[i] = m_workerArr[i + 1];
    }
    m_workerNum--;
    cout << "删除成功！" << endl;
    save();
    system("read -rsp 'Please Enter to continue...'");
}

void WorkerMgr::modEmp() 
{
    int id;
    cout << "请输入要修改的职工id：" << endl;
    cin >> id;
    int ret = isExist(id);
    if (ret == -1) {
        cout << "修改失败，查无此人！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    Worker * worker = NULL;
    int newId, newDId;
    string newName;
    cout << "请输入新的职工编号：" << endl;
    cin >> newId;
    cout << "请输入新的职工姓名：" << endl;
    cin >> newName;
    cout << "请输入新的员工岗位：" << endl;
    cout << "1. 普通职工" << endl;
    cout << "2. 经理" << endl;
    cout << "3. 老板" << endl;
    cin >> newDId;
    switch (newDId) {
        case 1:
            worker = new Employee(newId, newName, newDId);
            break;
        case 2:
            worker = new Manager(newId, newName, newDId);
            break;
        case 3:
            worker = new Boss(newId, newName, newDId);
            break;
        default:
            break;
    }
    if (m_workerArr[ret] != NULL) {
        delete m_workerArr[ret];
    }
    m_workerArr[ret] = worker;
    save();
    cout << "修改成功！" << endl;
    system("read -rsp 'Please Enter to continue...'");
}

void WorkerMgr::findEmp()
{
    int select;
    cout << "请输入要查找的类型：" << endl;
    cout << "1. 按编号查找" << endl;
    cout << "2. 按姓名查找" << endl;
    cin >> select;
    if (select == 1) {
        int id;
        cout << "请输入要查找的职工编号：" << endl;
        cin >> id;
        int ret = isExist(id);
        if (ret == -1) {
            cout << "查找失败，查无此人！" << endl;
            system("read -rsp 'Please Enter to continue...'");
            return;
        }
        m_workerArr[ret]->showInfo();
        system("read -rsp 'Please Enter to continue...'");
    }
    else if (select == 2) {
        string name;
        cout << "请输入要查找的职工姓名：" << endl;
        cin >> name;
        bool flag = false;
        for (int i = 0; i < m_workerNum; i++) {
            if (m_workerArr[i]->m_name == name) {
                flag = true;
                m_workerArr[i]->showInfo();
            }
        }
        if (!flag) {
            cout << "查找失败，查无此人！" << endl;
        }
        system("read -rsp 'Please Enter to continue...'");
    }
    else {
        cout << "输入有误！" << endl;
        system("read -rsp 'Please Enter to continue...'");
    }  
}

void WorkerMgr::sortList()
{
    if (m_workerArr == NULL) {
        cout << "数据为空！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    int select;
    cout << "请输入排序方式：" << endl;
    cout << "1. 编号升序排列" << endl;
    cout << "2. 编号降序排列" << endl;
    cin >> select;
    if (select != 1 && select != 2) {
        cout << "排序失败，输入有误！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    for (int i = 0; i < m_workerNum - 1; i++) {
        for (int j = 0; j < m_workerNum - i - 1; j++) {
            if (select == 1) {
                if (m_workerArr[j]->m_id > m_workerArr[j + 1]->m_id) {
                    Worker * tmp = m_workerArr[j];
                    m_workerArr[j] = m_workerArr[j + 1];
                    m_workerArr[j + 1] = tmp;
                }
            }
            else {
                if (m_workerArr[j]->m_id < m_workerArr[j + 1]->m_id) {
                    Worker * tmp = m_workerArr[j];
                    m_workerArr[j] = m_workerArr[j + 1];
                    m_workerArr[j + 1] = tmp;
                }
            }
        }
    }
    save();
    cout << "排序成功！" << endl;
    system("read -rsp 'Please Enter to continue...'");
}

void WorkerMgr::emptyList() 
{
    if (m_workerArr == NULL) {
        cout << "数据已为空！" << endl;
        system("read -rsp 'Please Enter to continue...'");
        return;
    }
    while (true) {
        cout << "确定要清空系统吗？" << endl;
        cout << "1. 确定" << endl;
        cout << "2. 取消" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            for (int i = 0; i < m_workerNum; i++) {
                delete m_workerArr[i];
                m_workerArr[i] = NULL;
            }
            delete [] m_workerArr;
            m_workerArr = NULL;
            m_workerNum = 0;
            save();
            cout << "清空成功！" << endl;
            system("read -rsp 'Please Enter to continue...'");
            break;
        } else if (select == 2) {
            break;
        } else {
            cout << "输入有误，请重新输入！" << endl;
            system("read -rsp 'Please Enter to continue...'");
            system("clear");
            showMenu();
        }
    }
}

int WorkerMgr::isExist(int id) 
{
    if (m_workerNum <= 0) {
        return -1;
    }
    for (int i = 0; i < m_workerNum; i++) {
        if (m_workerArr[i]->m_id == id) {
            return i;
        }
    }
    return -1;
}

void WorkerMgr::save() 
{
    ofstream ofs;
    ofs.open("EmpSystem.txt", ios::out);
    for (int i = 0; i < m_workerNum; i++) {
        if (m_workerArr[i] != NULL) {
            ofs << m_workerArr[i]->m_id << " " << m_workerArr[i]->m_name << " " << m_workerArr[i]->m_dId << endl;
        }
        else {
            ofs << endl;
        }
    }
    ofs.close();
}

WorkerMgr::~WorkerMgr() {
}