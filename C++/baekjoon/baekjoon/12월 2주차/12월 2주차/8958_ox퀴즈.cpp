#include <iostream>
#include <string>
using namespace std;
string words;
int T;
int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> words;
		int result, cnt;
		result = cnt = 0;
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == 'O') {
				cnt++;
				result += cnt;
			}
			else {
				cnt = 0;
				result += cnt;
			}
		}
		cout << result << '\n';
	}
	return 0;
}