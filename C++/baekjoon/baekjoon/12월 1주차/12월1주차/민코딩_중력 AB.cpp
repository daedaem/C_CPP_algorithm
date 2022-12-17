#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define A (1)
#define B (2)
#define MAX_NM (50)
int N, M;
vector<deque<int>>dq;
int maps[MAX_NM + 2][MAX_NM + 2];

void init() {	
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> N >> M;
	dq.resize(M);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			char cc; cin >> cc;
			if (cc == 'A') {
				maps[r][c] = A;
				dq[c].push_front(A);
			}
			else if (cc == 'B') {
				maps[r][c] = B;
				dq[c].push_front(B);
			}
			else {
				maps[r][c] = 0;
			}
		}
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (maps[r][c] == A) cout << 'A';
			else if (maps[r][c] == B) cout << 'B';
			else if (!maps[r][c]) cout << '_';
		}
		cout << '\n';
	}
	cout << '\n';
}
int gravity(int nc) {
	deque<int> tempq;
	int before = dq[nc].size();
	while (!dq[nc].empty()) {
		tempq.push_back(dq[nc].front()); dq[nc].pop_front();
	}
	dq[nc].clear();
	int flag = 0;
	while (tempq.size()>=2) {
		int ff = tempq.front(); tempq.pop_front();
		int bb = tempq.front(); tempq.pop_front();
		if (ff!= bb) {
			dq[nc].push_back(ff);
			tempq.push_front(bb);
		}
	}
	while(!tempq.empty()) {
		dq[nc].push_back(tempq.front()); tempq.pop_front();
	}
	int after = dq[nc].size();
	int cidx = 0;
	for (int r = 0; r < N; r++) {
		if (r >= dq[nc].size()) {
			maps[N-r-1][nc] = 0;
		}
		else maps[N-r-1][nc] = dq[nc][r];
	}
	if (after != before)return 0;
	else return 1;
}
void solve() {
	for (int c = 0; c < M; c++) {
		//print();
		while (!gravity(c));
		//cout << "afeter\n";
	}
	print();
}
int main(void) {
	freopen("gravityAB.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;
}
