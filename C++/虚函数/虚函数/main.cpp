//
//  main.cpp
//  虚函数
//
//  Created by 吴亿 on 2020/1/29.
//  Copyright © 2020 吴亿. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class AbstractDrinking
{
public:
    virtual ~AbstractDrinking() = 0;
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void addWater() = 0;
    virtual void addSth() = 0;
    void makeDrink() {
        boil();
        brew();
        addWater();
        addSth();
    }
};

AbstractDrinking::~AbstractDrinking() {
    cout << "AbstractDrinkingx析构调用" << endl;
}

class Coffee : public AbstractDrinking
{
public:
    ~Coffee() {
        cout << "Tea析构调用" << endl;
    }
    void boil() {
        cout << "煮开水..." << endl;
    }
    void brew() {
        cout << "加咖啡..." << endl;
    }
    void addWater() {
        cout << "冲咖啡..." << endl;
    }
    void addSth() {
        cout << "加牛奶和糖 ..." << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    ~Tea() {
        cout << "Tea析构调用" << endl;
    }
    void boil() {
        cout << "煮农夫山泉..." << endl;
    }
    void brew() {
        cout << "加茶叶..." << endl;
    }
    void addWater() {
        cout << "泡茶..." << endl;
    }
    void addSth() {
        cout << "加蜂蜜..." << endl;
    }
};

void test01() {
    cout << "泡咖啡开始。。。。。。" << endl;
    AbstractDrinking * abs = new Coffee;
    abs->makeDrink();
    delete abs;
    cout << "泡茶开始。。。。。。" << endl;
    abs = new Tea;
    abs->makeDrink();
    delete abs;
    abs = NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test01();
    return 0;
}
