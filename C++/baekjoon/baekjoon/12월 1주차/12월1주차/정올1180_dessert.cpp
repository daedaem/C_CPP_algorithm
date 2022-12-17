#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

//int perm[15 + 1];
int N;
char giho[] = { "+-." };
//vector<string> perm;
vector<char>perm;
vector <int> number;
int cnt = 0;
int calc() {
	string a;

	int result = 0;
	int permidx = 0;
	for (int i = 0; i < N; i++) {
		a+=to_string(number[i]);
		//if (i == 0) {
			//if (perm[i] == '.') {
				//a+=to_string(number[i]);
			//}
		//}
		//else {
			int num = stoi(a);
			//cout << num;
			if (perm[permidx] == '+') {
				result += num;
			}
			else if(perm[permidx] == '-') {
				result -= num;
			}
			a.clear();
			permidx = i;
		//}
	}
	cout << result << '\n';
	if (!a.empty()) {
		if (perm[permidx] == '+') {
			result += stoi(a);
		}
		else {
			result -= stoi(a);
		}
	}
	return result;
}
void DFS(int lev) {
	if (lev == N) {
		for (int i = 0; i < N; i++) {
			if (i < N - 1) {
				cout << number[i] << " " << perm[i] << " ";
			}
			else {
				cout << number[i];
			}
			
		}
		cout << '\n';
		int ret = calc();
		cout << ret << '\n';
		return;
	}
	for (int i = 0; i < 3; i++) {
		//perm.push_back(to_string(lev));
		if (i == 0) {
			perm.push_back('+');
		}
		else if (i == 1) {
			perm.push_back('-');
		}
		else if (i == 2) {
			perm.push_back('.');
		}
		DFS(lev + 1);
		perm.pop_back();
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		number.push_back(i);
	}
	DFS(1);
	return 0;

}