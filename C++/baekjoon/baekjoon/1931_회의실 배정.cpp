#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct ST {
	int s, e;
};
struct COMP {
	bool operator()(ST a, ST b) {
		return a.e < b.e;
	}
};
priority_queue<ST, vector<ST>, COMP> pq;
int N;
vector<ST> temp;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		temp.push_back({ s,e });
	}
}
bool tempsort(ST a, ST b) {
	if (a.e == b.e) {
		return a.s < b.s;
	}
	return a.e < b.e;
}
void solve() {
	sort(temp.begin(), temp.end(), tempsort);
	pq.push(temp[0]);
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].s >= pq.top().e) {
			pq.push(temp[i]);
		}
	}
	cout << pq.size();
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}