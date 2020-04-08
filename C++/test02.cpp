#include <iostream>
using namespace std;

// template<class T>
// class AutoReg {
// public:
//     AutoReg() {
//         std::unique_ptr<T> t(new T);
//     }
// };

class Person
{
public:
    Person(int m) {
        age = new int(m);
    }
    int * const getAge() const {
        return age;
    }
private:
    int * age;
};

int main() {
    // AutoReg<int>();
    // int a = 10, b = 20;
    // const int * c = &a;
    // int * const d = &a;
    // *d = 100;
    Person p(100);
    *p.getAge() = 200;
    cout << *p.getAge() << endl;
    return 0;
}