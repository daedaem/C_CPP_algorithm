#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct HR {
	int h;
	int idx;
};
int T;
int N;
int result[1000000 + 1];
struct COMP {
	bool operator()(HR a, HR b) {
		if (a.h == b.h) {
			return a.idx > b.idx;
		}
		return a.h < b.h;
	}
};
priority_queue<HR, vector<HR>, COMP> pq;
//priority_queue<HR> pq;

vector<int> orders;
void input() {
	orders.clear();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		pq.push({ h, i });
	}
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		orders.push_back(num);
	}

}
int solve() {
	int idx = 1;
	while (!pq.empty()) {
		//int oriid = orders.front(); orders.pop_front();
		result[pq.top().idx] = idx;
		//if (oriid != idx) return 0;
		idx++;
		pq.pop();
	}
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i] != result[i]) return 0;
	}
	return 1;
}
int main(void) {
	freopen("min_cardmake.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		int ret = solve();
		if (ret) cout << "YES\n";
		else cout << "NO\n";
		fill(&result[0], &result[N - 1], 0);
	}
	return 0;
}