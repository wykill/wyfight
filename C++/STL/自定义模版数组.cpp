#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyArray {
public:
    MyArray() : m_array(NULL), m_size(0), m_capacity(0)
    {}
    MyArray(int capacity) {
        m_capacity = capacity;
        m_array = new T[capacity];
        m_size = 0;
    }
    MyArray(MyArray<T> const& myArr) {
        if (m_array != NULL) {
            delete [] m_array;
            m_array = NULL;
        }
        if (myArr.capacity() != 0) {
            m_array = new T[myArr.capacity()];
            for (int i = 0; i < myArr.size(); i++) {
                m_array[i] = myArr[i];
            }
        }
        m_size = myArr.size();
        m_capacity = myArr.capacity();
    }
    ~MyArray() {
        if (m_array != NULL) {
            delete [] m_array;
            m_array = NULL;
        }
        m_size = 0;
        m_capacity = 0;
    }

    T& operator[](int i) const {
        if (i >= m_size) {
            cout << "容器没有这么大！" << endl;
            cout << "最大的是 " << m_array[m_size];
            return m_array[m_size];
        }
        return m_array[i];
    }

    void push_back(T const& ele) {
        if (m_size != m_capacity) {
            m_array[m_size++] = ele;
        }
        else {
            m_capacity = 2 * m_capacity + 1;
            T* tmp_arr = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                tmp_arr[i] = m_array[i];
            }
            tmp_arr[m_size] = ele;
            if (m_array != NULL) {
                delete [] m_array;
            }
            m_array = tmp_arr;

            m_size++;
        }
    }

    void pop_back() {
        if (m_size == 0) {
            cout << "容器为空！" << endl;
        }
        else {
            m_size--;
        }
    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    }
private:
    T* m_array;
    int m_size;
    int m_capacity;
};

class Person {
public:
    Person() : m_name(""), m_age(0)
    {}
    Person(std::string name, int age) : m_name(name), m_age(age)
    {}
    void operator=(Person const& p) {
        m_name = p.m_name;
        m_age = p.m_age;
    }
    std::string m_name;
    int m_age;
};

ostream& operator<<(ostream & out, Person const& p) {
    out << "name: " << p.m_name << ", age: " << p.m_age << endl;
    return out;
}

void printArr(MyArray<int> myArr) {
    for (int i = 0; i < myArr.size(); i++) {
        cout << myArr[i] << " ";
    }
    cout << endl;
}

void printArr2(MyArray<Person> myArr) {
    for (int i = 0; i < myArr.size(); i++) {
        cout << myArr[i];
    }
    //cout << endl;
}

void test01() {
    MyArray<int> myArr;
    myArr.push_back(1);
    myArr.push_back(2);
    myArr.push_back(3);
    MyArray<int> myArr2(myArr);
    printArr(myArr);
    printArr(myArr2);
}

void test02() {
    Person p1("zhangsan", 10);
    Person p2("lisi", 20);
    Person p3("wangwu", 30);
    Person p4("wy", 40);
    Person p5("demo", 50);
    MyArray<Person> myArr;
    myArr.push_back(p1);
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl; 
    myArr.push_back(p2);
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl; 
    myArr.push_back(p3);
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl; 
    myArr.push_back(p4);
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl; 
    myArr.push_back(p5);
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    myArr.pop_back();
    cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    // myArr.pop_back();
    // cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    // myArr.pop_back();
    // cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    // myArr.pop_back();
    // cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    // myArr.pop_back();
    // cout << "myArr.size is " << myArr.size() << ", myArr.Capacity is " << myArr.capacity() << endl;
    // myArr.pop_back();

    MyArray<Person> myArr2(myArr);
    printArr2(myArr);
    cout << "============" << endl;
    printArr2(myArr2);
}

int main() {
    //test01();
    test02();
    return 0;
}