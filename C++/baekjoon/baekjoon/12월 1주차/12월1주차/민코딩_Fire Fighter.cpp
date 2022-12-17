#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX_N (20)
struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
struct FF {
	int idx;
	int r, c;
	int from, to;
};
queue<ST> q;
queue<FF> fireq;
int visit[MAX_N + 2][MAX_N + 2];
int visit2[400 + 1][MAX_N + 2][MAX_N + 2];
int maps[MAX_N + 2][MAX_N + 2];
int N;
int SR, SC;
int idx;
FF firehos[400+1];
void input() {
	cin >> N;
	idx = 1;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			char cc; cin >> cc;
			if (cc == 'A') {
				maps[r][c] = idx;
				firehos[idx] = {idx, r,c,0,0 };
				idx++;
			}
			else if (cc == '_') maps[r][c] = 0;
			else if (cc == '#') maps[r][c] = -1;
			else if (cc == '$') maps[r][c] = -2;
		}
	}
	cin >> SR >> SC;
}
void gotoff() {
	static POS D[] = { {-1,0},{0,1},{1,0}, {0,-1} };
	q = {};
	fill(&visit[0][0], &visit[MAX_N + 1][MAX_N + 2], 0);
	q.push({ SR,SC, 0 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ST newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			newdata.d++;
			if (newdata.r<0 || newdata.c<0 || newdata.r>N || newdata.c>N) continue;
			if (maps[newdata.r][newdata.c] == -1) continue;
			if (maps[newdata.r][newdata.c] == -2) continue;
			if (visit[newdata.r][newdata.c]) continue;
			visit[newdata.r][newdata.c] = 1;
			if (maps[newdata.r][newdata.c] > 0) {
				int num = maps[newdata.r][newdata.c];
				firehos[num].from = newdata.d;
			}
			q.push(newdata);
		}
	}
}
void backto() {
	static POS D[] = { {-1,0},{0,1},{1,0}, {0,-1} };
	fireq = {};
	fill(&visit2[0][0][0], &visit2[400][MAX_N + 1][MAX_N + 2], 0);
	for (int i = 1; i < idx; i++) {
		fireq.push({ i, firehos[i].r, firehos[i].c, firehos[i].from,0 });
	}
	while (!fireq.empty()) {
		FF data = fireq.front(); fireq.pop();
		for (int a = 0; a < 4; a++) {
			FF newdata = data;
			newdata.r += D[a].r;
			newdata.c += D[a].c;
			newdata.to++;
			if (newdata.r<0 || newdata.c<0 || newdata.r>N || newdata.c>N) continue;
			if (maps[newdata.r][newdata.c] == -1) continue;
			if (visit2[newdata.idx][newdata.r][newdata.c]) continue;
			visit2[newdata.idx][newdata.r][newdata.c] = 1;
			if (maps[newdata.r][newdata.c] == -2) {
				int fidx = newdata.idx;
				firehos[fidx].to = newdata.to;
			}
			fireq.push(newdata);
		}
	}
}
void solve() {
	gotoff();
	backto();
	int minn = 0xf777777;
	for (int i = 1; i < idx; i++) {
		int res = firehos[i].from + firehos[i].to;
		if (res < minn) minn = res;
	}
	cout << minn;
}
int main(void) {
	freopen("firefighter.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();

	return 0;
}