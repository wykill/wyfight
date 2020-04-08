//
//  main.cpp
//  fstream
//
//  Created by 吴亿 on 2020/1/30.
//  Copyright © 2020 吴亿. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//void test01() {
//    ofstream ofs;
//    ofs.open("test.txt", ios::out);
//    ofs << "姓名：www" << endl;
//    ofs << "性别：男" << endl;
//    ofs << "爱好：游泳" << endl;
//    ofs.close();
//}

void test02() {
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "打开文件失败！" << endl;
        return;
    }
//    char buf[1024] = { 0 };
//    while (ifs >> buf) {
//        cout << buf << endl;
//    }
//    while (ifs.getline(buf, 1024)) {
//        cout << buf << endl;
//    }
//    string buf;
//    while (getline(ifs, buf)) {
//        cout << buf << endl;
//    }
    
    char letter = { 0 };
    while(ifs.get(letter)) {
        cout << letter;
    }
    ifs.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    test01();
    test02();
    return 0;
}
