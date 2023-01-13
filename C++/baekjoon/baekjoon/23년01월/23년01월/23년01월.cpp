#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N, maxk;

vector<int> perm;
vector<int> arr;
void init() {
	arr.clear();
}
void input() {
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	maxk = sqrt(N);
	if ((int)pow(2, maxk) == N) maxk -= 1;
}
void changeArr(int rangeNum) {
	int rn = pow(2, rangeNum);
	deque<int> dq;
	for (int i = 0; i < rn; i++) {
		arr[i];
	}
}
int maxx = 0;
void DFS(int dep) {
	if (dep == 2) {
		for (auto i : perm) cout << i << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= maxk; i++) {
		perm.push_back(i);
		DFS(dep+1);
		perm.pop_back();
	}
}
void solve() {
	DFS(0);
	changeArr(1);
}
int main(void) {
	cin >> N;
	init();
	input();
	solve();
	return 0;
}
