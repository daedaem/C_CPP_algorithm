#include <iostream>
#include <vector>
#include <string>
using namespace std;

string inputs;
string a = "12345678";
string d = "87654321";
int main(void) {
	for (int i = 1; i <= 8; i++) {
		char cc; cin >> cc;
		inputs += cc;
	}
	if (inputs == a) cout << "ascending";
	else if (inputs == d)cout << "descending";
	else cout << "mixed";
	return 0;

}