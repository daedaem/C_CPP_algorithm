#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_NM (50)
#define LAKE (0)
#define NG (1)
#define YG (2)
#define GREEN (1)
#define RED (2)

struct POS {
	int r, c;
};
struct GR {
	int r, c, type, time;
};
queue<GR> q;
int N, M, G, R, maxx;
int perm[2500];
int maps[MAX_NM + 2][MAX_NM + 2];
int visit[3][MAX_NM + 2][MAX_NM + 2];
vector<POS> ground;
void init() {
	ground.clear();
	fill(&perm[0], &perm[MAX_NM + 1], 0);
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> N >> M >> G >> R;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == YG) {
				ground.push_back({ r,c });
			}
		}
	}
}

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << visit[1][r][c] << " ";
		}
		cout << "	";
		for (int c = 0; c < M; c++) {
			cout << visit[2][r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int BFS() {
	static POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	fill(&visit[0][0][0], &visit[2][N + 1][M + 1], 0);
	int flowercnt = 0;
	for (int i = 0; i < ground.size(); i++) {
		if (!perm[i]) continue;
		if (perm[i] == GREEN) {
			q.push({ ground[i].r, ground[i].c, GREEN ,1 });
			visit[GREEN][ground[i].r][ground[i].c] = 1;
		}
		else if (perm[i] == RED) {
			q.push({ ground[i].r, ground[i].c, RED ,1 });
			visit[RED][ground[i].r][ground[i].c] = 1;
		}
	}
	while (!q.empty()) {
		GR data = q.front(); q.pop();
		if (visit[GREEN][data.r][data.c] && visit[RED][data.r][data.c]) continue;
		for (int i = 0; i < 4; i++) {
			GR newdata = data;
			newdata.r += DIR[i].r;
			newdata.c += DIR[i].c;
			newdata.time++;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
			if (maps[newdata.r][newdata.c] == LAKE) continue;
			if (visit[newdata.type][newdata.r][newdata.c]) continue;
			if (newdata.type == RED) {
				if (visit[GREEN][newdata.r][newdata.c] == newdata.time) {
					visit[RED][newdata.r][newdata.c] = newdata.time;
					flowercnt++;
					continue;
				}
				else if (visit[GREEN][newdata.r][newdata.c] && visit[GREEN][newdata.r][newdata.c] < newdata.time) continue;
			}
			if (newdata.type == GREEN) {
				if (visit[RED][newdata.r][newdata.c] == newdata.time) {
					visit[GREEN][newdata.r][newdata.c] = newdata.time;
					flowercnt++;
					continue;
				}
				else if (visit[RED][newdata.r][newdata.c] && visit[RED][newdata.r][newdata.c] < newdata.time) continue;
			}
			visit[newdata.type][newdata.r][newdata.c] = newdata.time;
			q.push(newdata);
		}
	}
	return flowercnt;
}
void DFS(int dep, int gcnt, int rcnt) {
	if (dep == ground.size()) {
		if (gcnt || rcnt) return;
		int ret = BFS();
		if (maxx < ret) {
			maxx = ret;
		}
		return;
	}

	perm[dep] = 0;
	DFS(dep + 1, gcnt, rcnt);

	if (gcnt > 0) {
		perm[dep] = GREEN;
		DFS(dep + 1, gcnt - 1, rcnt);
		perm[dep] = 0;

	}
	if (rcnt > 0) {
		perm[dep] = RED;
		DFS(dep + 1, gcnt, rcnt - 1);
		perm[dep] = 0;
	}
}
void solve() {
	maxx = 0;
	DFS(0, G, R);
}
int main(void) {
	freopen("18809_gaaaarden.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	//cin >> T;
	T = 1;
	for (int i = 1; i <= T; i++) {
		init();
		input();
		solve();
		cout << maxx << '\n';
		//cout <<"#"<< i<<" "<< maxx << '\n';
	}
	return 0;
}