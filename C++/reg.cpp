#include <iostream>
#include <regex>
using namespace std;

bool valid(smatch const& m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched && (m[4].str() == m[6].str());
	}
}

int main(){
	// string pattern("[^c]ei");
	// pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
	// regex r(pattern);
	// string str("receipt freind theif receive");
	// smatch result;
	// for (sregex_iterator it(str.begin(), str.end(), r), end_it; it != end_it; ++it) {
	// 	cout << it->prefix().str() << "\t" << it->prefix().length() << endl;
	// 	cout << it->str() << endl;
	// 	cout << it->suffix().str() << endl;
	// }
	// if (regex_search(str, result, r)) {
	// 	cout << result.str() << endl;
	// }

	// string pattern("\\d{5}[-]?(\\d{4})?");
	// regex r(pattern);
	// smatch result;
	// string str("11111");
	// if (regex_search(str, result, r)) {
	// 	cout << result.str() << endl;
	// }

	// string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	string pattern = "[+-]?(\\d)+([.](\\d)+)?";
	regex r(pattern);
	smatch m;
	string s;
	while(cin >> s) {
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
			cout << it->str() << endl;
			if (valid(*it)) {
				cout << "success input: " << it->str() << endl;
			}
			else {
				cout << "err Input: " << it->str() << endl;
			}
		}
	}
	return 0;
}