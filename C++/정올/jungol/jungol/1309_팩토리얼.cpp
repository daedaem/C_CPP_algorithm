#include <iostream>
using namespace std;
int N;
long long answer;
void solve(int num, long long sum) {
	if (num == 1) {
		cout << num << "! = " << num <<"\n";
		cout << sum << '\n';
		return;
	}
	cout << num << "! = " << num << " * " << num - 1 << "!\n";
	solve(num - 1, sum*num);
}
int main(void) {
	cin >> N;
	answer = 1;
	solve(N, 1);
	return 0;
}