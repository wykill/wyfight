#include <iostream>  
#include <string>
using namespace std;  
  
int main(){  
    string filename = "hello'wor'k'e";
    string::size_type pos = filename.find("'");
    cout << "pos: " << pos << endl;
    while (pos != string::npos) {
        string leftSubStr = filename.substr(0, pos);
        string rightSubStr = filename.substr(pos + 1);
        filename = leftSubStr + "'\''" + rightSubStr;
        pos = filename.find("'", pos + 3);
    }
    cout << filename << endl;
}