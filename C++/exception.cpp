#include <iostream>
using namespace std;

int main(){
	try {
		throw 6;
	}
	catch(int& x) {
		cout << x << endl;
	}
	return 0;
}