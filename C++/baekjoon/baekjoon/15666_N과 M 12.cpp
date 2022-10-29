#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, M;
vector<int>arr;
vector<int>temp;
set<vector<int>>s;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int b; cin >> b;
		arr.push_back(b);
	}
	sort(arr.begin(), arr.end());
}

void DFS(int start, int dep) {
	if (dep == M) {
		auto it = s.begin();
		s.insert(temp);
		return;
	}
	int before = 0;
	for (int i = start; i < N; i++) {
		if (temp.size() && temp.back()>arr[i]) continue;
		before = arr[i];
		temp.push_back(arr[i]);
		DFS(start, dep + 1);
		temp.pop_back();
	}
}
void print() {
	for (auto v : s) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	DFS(0, 0);
	print();
	return 0;
}