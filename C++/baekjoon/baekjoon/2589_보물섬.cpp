#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

#define MAX_LW (50)

struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int L, W, R, C;
char maps[MAX_LW + 2][MAX_LW + 2];
int visit[MAX_LW + 2][MAX_LW + 2];
int maxr, maxc, maxd;
//unordered_map<POS, int> um;
vector<POS> ground;
queue<ST>q;
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'L') ground.push_back({ r,c });
		}
	}
}
void BFS(int r, int c) {
	q = {};
	fill(&visit[0][0], &visit[MAX_LW + 1][MAX_LW + 2], 0);
	q.push({ r,c,0 });
	visit[r][c] = 1;
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ST newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			newdata.d++;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= R || newdata.c >= C) continue;
			if (maps[newdata.r][newdata.c] == 'W')  continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (maxd < newdata.d) maxd = newdata.d;
			visit[newdata.r][newdata.c] = 1;
			q.push({ newdata.r, newdata.c, newdata.d });
		}
	}
}
void solve() {
	for (int i = 0; i < ground.size(); i++) {
		int r = ground[i].r;
		int c = ground[i].c;
		if (maps[r][c] == 'W') continue;
		BFS(r, c);
	}
	cout << maxd;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}