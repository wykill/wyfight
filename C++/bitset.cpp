#include <iostream>
#include <bitset>
using namespace std;

int main(){
	bitset<64> bitvec(32);
	bitset<32> bv("1");
	bitvec.set(0);
	cout << bitvec.to_string() << endl;
	cout << true << endl;
	cout << bv << endl;
	cout << bitvec.count() << endl;
	return 0;
}