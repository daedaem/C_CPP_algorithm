#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX_NM (3000)
int N, M, K;
int SR, SC, ER, EC;
struct ST {
	int r, c, d;
};
struct POS {
	int r, c;
};
//vector<ST> v;
int maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
queue<ST> q;
POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1}};
void init() {
	fill(&maps[1][1], &maps[MAX_NM + 1][MAX_NM + 2], 0);
	fill(&visit[1][1], &visit[MAX_NM + 1][MAX_NM + 2], 0);
}
int calc(int sr, int sc, int dy, int dx,int dis) {
	int ret = abs(sr - dy) + abs(sc - dx);
	if (ret > dis) return 0;
	return 1;
}
void makepath(int nr, int nc, int dis) {
	//maps[nr][nc] = -1;

	for (int d = 0; d <= dis; d++) {
		int lens = dis - d;
		if (nr - d >= 1 && nc - lens >= 1) maps[nr - d][nc - lens] = -1;
		if (nr - d >= 1 && nc + lens <= M) maps[nr - d][nc + lens] = -1;
		if (nr + d <= N && nc - lens >= 1) maps[nr + d][nc - lens] = -1;
		if (nr + d <= N && nc + lens <= M) maps[nr + d][nc + lens] = -1;

		//for (int c = 0; c <= dis - d; c++) {
			/*if (nr - d >= 1 && nc + c <= M)maps[nr - d][nc + c] = -1;
			if (nr - d >= 1 && nc - c>=1) maps[nr - d][nc - c] = -1;
			if (nr + d <= N && nc + c <=M) maps[nr + d][nc + c] = -1;
			if (nr + d <= N && nc - c>=1) maps[nr + d][nc - c] = -1;*/
		//}
	}
	//for (int r = sr; r <= er; r++) {
	//	for (int c = sc; c <= ec; c++) {
	//		int ret = calc(r, c, nr, nc, dis);
	//		if (!ret) continue;
	//		maps[r][c] = -1;
	//	}
	//}
}
void input() {
	cin >> N >> M >> K;
	SR = 1, SC = 1;
	ER = N, EC = M;
	for (int i = 0; i < K; i++) {
		int a, b, d; cin >> a >> b >> d;
		makepath(a,b,d);
	}
}
void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int BFS() {
	q = {};
	fill(&visit[1][1], &visit[MAX_NM + 1][MAX_NM + 2], 0);
	visit[SR][SC] = 1;
	q.push({ SR,SC,0 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ST newdata = data;
			newdata.r += DIR[i].r;
			newdata.c += DIR[i].c;
			newdata.d++;
			if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (maps[newdata.r][newdata.c] == -1) continue;
			if (newdata.r == ER && newdata.c == EC) return newdata.d;
			visit[newdata.r][newdata.c] = 1;
			//maps[newdata.r][newdata.c] = newdata.d;
			q.push(newdata);
		}
	}
	return 0;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	int ret = BFS();
	if (ret) cout << "YES\n" << ret<<'\n';
	else cout << "NO\n";
	print();
	return 0;
}