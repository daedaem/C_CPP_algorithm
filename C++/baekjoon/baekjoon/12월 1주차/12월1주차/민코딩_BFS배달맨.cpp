#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct POS{
	int r, c;
};
struct ST {
	int r, c, d;
};
queue<ST> q;
int visit[10 + 2][10 + 2];
int maps[10 + 2][10 + 2];
int R, C;
POS man;
void init() {

}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			char cc; cin >> cc;
			if (cc == '#') maps[r][c] = -1;
			else maps[r][c] = cc - '0';
		}
	}
	man.r = 0;
	man.c = 0;
}
int BFS(int arnum) {
	POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
	if (maps[man.r][man.c] == arnum) return 0;
	q = {};
	fill(&visit[0][0], &visit[10 + 1][10 + 2], 0);
	q.push({ man.r, man.c, 0 });
	visit[man.r][man.c] = 1;
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ST newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			newdata.d++;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= 10 || newdata.c >= 10) continue;
			if (maps[newdata.r][newdata.c] == -1) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (maps[newdata.r][newdata.c] == arnum) {
				man.r = newdata.r;
				man.c = newdata.c;
				return newdata.d;
			}
			q.push(newdata);
		}
	}
}
void solve() {
	int cnt = 0;
	for (int i = 1; i <= 4; i++) {
		int ret = BFS(i);
		cnt += ret;
	}
	cout << cnt << "ȸ"<<'\n';
}
int main(void) {
	freopen("BFSdeliver.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;
}