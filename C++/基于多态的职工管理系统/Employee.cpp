#include "Employee.hpp"

Employee::Employee(int id, string name, int Did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dId = Did;
}

void Employee::showInfo() 
{
    cout << "职工编号：" << this->m_id
        << "\t职工姓名：" << this->m_name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：" << this->showDepDesc() << endl;
}   

string Employee::getDeptName()
{
    return "普通职工";
}

string Employee::showDepDesc()
{
    return "完成经理交给的任务";
}