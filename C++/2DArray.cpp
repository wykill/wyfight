#include <iostream>
using namespace std;
//函数声明  返回值类型，函数名，形参列表
//  声明可以写多次，但是定义只能有一次   ！！！
int getMax(int , int);
int getMax(int , int);
int getMax(int , int);

int main() {
    int arr[][3] = {1, 2, 3, 4};
    cout << "rows are " << sizeof(arr)/sizeof(arr[0]) << endl;
    // for (int i = 0; i < arr.length; i++) {
    //     for (int j = 0; j < arr[i].length(); j++) {
    //         cout << arr[i][j] << "\t";
    //     }
    //     cout << endl;
    // } 
    cout << sizeof(arr[1]) << endl;
    cout << "首地址为：" << (long)arr << endl;
    cout << "第一行首地址：" << (long)arr[1] << endl;
    cout << (long)&arr[1][2] << endl;
    cout << getMax(1, 200) << endl;
    return 0;
}

int getMax(int a, int b) {
    return a > b ? a : b;
}