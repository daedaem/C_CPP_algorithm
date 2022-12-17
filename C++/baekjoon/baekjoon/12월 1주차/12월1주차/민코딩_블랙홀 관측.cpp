#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maps[5+2][5+2];
int record[5 + 2][5 + 2];
deque<int> dq;
vector<int> path;
int SR = 3, SC = 3;
struct POS {
	int r, c;
};
POS DIR[] = { {0,-1},{1,0},{0,1},{-1,0} };
void input() {
	for (int r = 1; r <= 5; r++) {
		for (int c = 1; c <= 5; c++) {
			cin >> maps[r][c];
		}
	}
}
void makepath() {
	int idx = 0;
	for (int i = 1; i < 5; i++) {
		for (int rep = 0; rep < 2; rep++) {
			for (int j = 1; j <= i; j++) {
				path.push_back(idx);
			}
			idx = (idx + 1) % 4;
		}
	}
	for (int i = 1; i <= 5; i++) {
		path.push_back(idx);
	}
}
void print() {
	for (int r = 0; r <= 5; r++) {
		for (int c = 0; c <= 5; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int move(){
	int nowr = SR;
	int nowc = SC;
	int nextr = SR + DIR[path[0]].r;
	int nextc = SC + DIR[path[0]].c;
	maps[nextr][nextc] = 0;
	for (int i = 1; i < path.size(); i++) {
		maps[nowr][nowc] = maps[nextr][nextc];
		nowr = nextr;
		nowc = nextc;
		maps[nextr][nextc] = 0;
		nextr += DIR[path[i]].r;
		nextc += DIR[path[i]].c;
	}
	int cnt = 0;
	for (int c = 1; c <= 5; c++) {
		if (c == 3) continue;
		cnt += maps[3][c];
	}
	return cnt;
}
void solve() {
	int minn=0xf777777;
	makepath();
	for (int i = 0; i < 6; i++) {
		int ret = move();
		if (minn > ret) minn = ret;
	}
	cout << minn << '\n';
}
int main(void) {
	freopen("blackhallsee.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}