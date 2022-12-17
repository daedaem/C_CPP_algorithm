#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>


using namespace std;

int main() {
	string a = "1 2 3 4";
	for (int i = 0; i < a.size(); i++) {
		//cout <<a[i] <<" "<<isdigit(a[i]) << "\n";
		
		if (isdigit(a[i])) {
			atoi(*a[i]);
		}
	}
}