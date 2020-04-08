#include <iostream>
#include <ctime>
#include "SpeechMgr.hpp"
using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    SpeechMgr sMgr;
    int select = 0;
    while (true) {
        // system("clear");
        sMgr.printInfo();   //打印提示信息
        cout << "请输入你的选择：" << endl;
        cin >> select;
        switch (select) {
            case 1:
                // 比赛开始
                sMgr.startContest();
                // sMgr.showSpeakers();
               break; 
            case 2:
                // 查往届记录
                sMgr.showHistory();
                break;
            case 3:
                // 清除记录
                sMgr.clearRecord();
                break;
            case 0:
                sMgr.quitSystem();  //退出系统
                break;
            default:
                system("clear");
                break;
        }
        system("clear");
        // system("read -rsp 'Please Enter to continue...'");
    }
    return 0;
}