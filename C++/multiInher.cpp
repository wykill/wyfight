#include <iostream>
using namespace std;

class Base1 {
public:
	Base1() {
		cout << "Base1 constructor" << endl;
	}
	virtual void print() {
		cout << "Base1" << endl;
	}
	virtual ~Base1() {
		cout << "Base1 destructor" << endl;	
	}
};

class Base2 {
public:
	Base2() {
		cout << "Base2 constructor" << endl;
	}
	virtual void print() {
		cout << "Base2" << endl;
	}
	virtual ~Base2() {
		cout << "Base2 destructor" << endl;
	}
};

class D1 : public Base1 {
public:
	D1() {
		cout << "D1 construcotr" << endl;
	}
	virtual void print() {
		cout << "D1" << endl;
	}
	virtual ~D1() {
		cout << "D1 construcotr" << endl;
	}
};

class D2 : public Base2 {
public:
	D2() {
		cout << "D2 construcotr" << endl;
	}
	virtual void print() {
		cout << "D2" << endl;
	}
	virtual ~D2() {
		cout << "D2 construcotr" << endl;
	}
};

class Component {
public:
	Component() {
		cout << "Component constructor" << endl;
	}
};

class MI : public D1, public D2 {             // MI has a Component, is a D1, is a D2  继承+组合， 构造函数顺序：父类构造函数 > 组合类的构造函数 > 子类构造函数
public:
	MI() {
		cout << "MI construcotr" << endl;
	}
	virtual void print() {
		cout << "MI" << endl;
	}
	virtual ~MI() {
		cout << "MI construcotr" << endl;
	}
private:
	Component com;
};

int main() {
	Base1& base1 = *(new MI);
	base1.print();
	delete &base1;
	cin.get();
	return 0;
}