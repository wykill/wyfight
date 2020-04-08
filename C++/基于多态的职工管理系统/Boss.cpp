#include "Boss.hpp"

Boss::Boss(int id, string name, int Did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dId = Did;
}

void Boss::showInfo() 
{
    cout << "职工编号：" << this->m_id
        << "\t职工姓名：" << this->m_name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：" << this->showDepDesc() << endl;
}   

string Boss::getDeptName()
{
    return "老板";
}

string Boss::showDepDesc()
{
    return "安排任务给经理";
}