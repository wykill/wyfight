#include "Manager.hpp"

Manager::Manager(int id, string name, int Did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dId = Did;
}

void Manager::showInfo() 
{
    cout << "职工编号：" << this->m_id
        << "\t职工姓名：" << this->m_name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：" << this->showDepDesc() << endl;
}   

string Manager::getDeptName()
{
    return "经理";
}

string Manager::showDepDesc()
{
    return "听从老板的指示，给职工分派任务";
}