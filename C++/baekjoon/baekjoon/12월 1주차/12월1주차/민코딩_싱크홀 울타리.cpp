#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_NM (100)
struct POS {
	int r, c;
};
struct ST {
	int nr, nc, sr, sc, er, ec;
	int w, h;
};
vector<ST> sinks;
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int visit[MAX_NM + 2][MAX_NM + 2];
int maps[MAX_NM + 2][MAX_NM + 2];
int N, M;
queue<POS> q;
void init() {
	sinks.clear();
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
		}
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout<< visit[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void BFS(int sr,int sc, int idx) {
	q = {};
	q.push({ sr,sc });
	visit[sr][sc] = idx;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
			if (!maps[newdata.r][newdata.c]) continue;
			if (visit[newdata.r][newdata.c]) continue;
			visit[newdata.r][newdata.c] = idx;
			sinks[idx - 1].sr = min(sinks[idx - 1].sr, newdata.r);
			sinks[idx - 1].sc = min(sinks[idx - 1].sc, newdata.c);
			sinks[idx - 1].er = max(sinks[idx - 1].er, newdata.r);
			sinks[idx - 1].ec = max(sinks[idx - 1].ec, newdata.c);
			sinks[idx - 1].w = sinks[idx - 1].ec - sinks[idx - 1].sc+1;
			sinks[idx - 1].h = sinks[idx - 1].er - sinks[idx - 1].sr+1;
			q.push(newdata);
		}
	}
}
void solve() {
	int idx = 1;
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0);
	int maxx = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!maps[r][c]) continue;
			if (visit[r][c]) continue;
			sinks.push_back({ r,c,r,c,r,c,0,0 });
			BFS(r,c,idx);
			int lens = 2 * (sinks[idx-1].w + sinks[idx-1].h) + 4;
			if (maxx < lens) {
				maxx = lens;
			}
			idx++;
		}
	}
	//print();
	cout << maxx << '\n';
}
int main(void) {
	freopen("sinkhall.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();

	return 0;
}