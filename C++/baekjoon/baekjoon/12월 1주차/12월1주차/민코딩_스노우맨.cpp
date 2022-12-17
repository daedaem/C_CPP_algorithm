#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NM (50)

struct POS {
	int r, c, e, maxe;
};
queue<POS> q;
int maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
int N, M, SR, SC, ER, EC;
void init() {
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 2) {
				SR = r;
				SC = c;
			}
			else if (maps[r][c] == 3) {
				ER = r;
				EC = c;
			}
		}
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << visit[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int BFS() {
	POS DIR[] = { {0,1},{0,-1},{-1,0},{1,0} };
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0xf777777);
	q = {};
	q.push({ SR,SC, 0, 0 });
	visit[SR][SC] = 0;
	int maxe = 0xf777777;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		if (data.maxe >= maxe) continue;
		if (!maps[data.r][data.c] || data.e) { // 만약 땅위가아니라면
			for (int idx = 2; idx < 4; idx++) {
				POS newdata = data;
				newdata.r += DIR[idx].r;
				newdata.c += DIR[idx].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
				newdata.e++;
				if (newdata.e > newdata.maxe) newdata.maxe = newdata.e;
				if (visit[newdata.r][newdata.c] <= newdata.maxe) continue;
				visit[newdata.r][newdata.c] = newdata.maxe;
				if (maps[newdata.r][newdata.c]) newdata.e = 0;
				q.push(newdata);
			}
		}
		else if (maps[data.r][data.c]) {
			for (int idx = 0; idx < 4; idx++) {
				POS newdata = data;
				newdata.r += DIR[idx].r;
				newdata.c += DIR[idx].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
				if (idx >= 2) {
					newdata.e++;
				}
				if (idx < 2 && !maps[newdata.r][newdata.c]) continue; //
				if (newdata.e > newdata.maxe) newdata.maxe = newdata.e;
				if (visit[newdata.r][newdata.c] <= newdata.maxe) continue;
				visit[newdata.r][newdata.c] = newdata.maxe;
				if (maps[newdata.r][newdata.c]) newdata.e = 0;
				q.push(newdata);
			}
		}
	}
	return visit[ER][EC];
}
int main(void) {
	freopen("snowman.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	init();
	input();
	cout <<BFS() <<'\n';
	return 0;
}