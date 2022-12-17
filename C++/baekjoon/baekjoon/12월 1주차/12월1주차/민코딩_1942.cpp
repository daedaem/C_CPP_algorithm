#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<deque<int>> dq(4);
int N;
vector<int>order;
void init() {
	cin >> N;
	for (int i = 0; i < dq.size(); i++) {
		dq[i].clear();
	}
	order.resize(N);
	for (int i = 0; i < N; i ++) {
		cin >>order[i];
		order[i]--;
	}
}
void input() {
	cin >>N;
}
void push(int nr) {
	if (dq[nr].size() == 10) return;
	dq[nr].push_back(1);
}
void check() {
	for (int c = 0; c <10; c++) {
		int cnt = 0;
		for (int r = 0; r < 4; r++) {
			if (dq[r].size() < c+1) break;
			cnt++;
		}
		if (cnt == 4) {
			for (int r = 0; r < 4; r++) {
				dq[r][c] = 0;
			}
		}
	}
	for (int r = 0; r < 4; r++) {
		deque<int> bowl;
		while (!dq[r].empty()) {
			int num = dq[r].back(); dq[r].pop_back();
			if (num) bowl.push_back(num);
		}
		while (!bowl.empty()) {
			dq[r].push_back(bowl.back()); bowl.pop_back();
		}
	}
	//	int cs = 0;
	//	int end = dq[r].size();
	//	if (end<=1) continue;
	//	while (1) {
	//		int ce = cs + 1;
	//		if (cs == end) break;
	//		if (!dq[r][cs]) {
	//			while (1) {
	//				if (ce == end) break;
	//				if (dq[r][ce]) {
	//					dq[r][cs] = dq[r][ce];
	//					dq[r][ce] = 0;
	//					break;
	//				}
	//				ce++;
	//			}
	//		}
	//		cs++;
	//	}
	//}
}
void print() {
	for (int r = 0; r < 4; r++) {
		for (int c = 9; c >=0; c--) {
			if (dq[r].size() > c) {
				cout << dq[r][c] << " ";
			}
			else cout << 0 << " ";
		}
		cout << '\n';
	}
	cout << '\n';

}
void solve() {
//10개이상이면 넣지 마라
	for (int i = 0; i < N; i++) {
		push(order[i]);
		check();
		//cout << "#" << i + 1 << '\n';
	//	print();
	}
	print();

}
int main(void) {
	freopen("1942.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;
}