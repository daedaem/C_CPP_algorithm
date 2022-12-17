#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_NM (300)
struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
POS DIR[] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
int dist[MAX_NM + 2][MAX_NM + 2];
int H, W, T, SR, SC, ER, EC;
struct COMP {
	bool operator()(ST a, ST b) {
		if (a.d == b.d) {
			return maps[a.r][a.c] < maps[b.r][b.c];
		}
		return (a.d > b.d);
	}
};
priority_queue<ST, vector<ST>, COMP> q;
void init() {
	fill(&maps[0][0], &maps[MAX_NM+1][MAX_NM+2], 0);
	fill(&dist[0][0], &dist[MAX_NM + 1][MAX_NM + 2], 0xf777777);
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char cc; cin >> cc;
			if (cc == 'S') {
				SR = r;
				SC = c;
				maps[r][c] = 1;
			}
			else if (cc == 'E') {
				ER = r;
				EC = c;
				maps[r][c] = 1;
			}
			else if (cc == '#') {
				maps[r][c] = -1;
			}
			else if (cc == '.') {
				maps[r][c] = 1;
			}
			else if (cc == 'R') {
				maps[r][c] = 0;
			}
		}
	}
}
void BFS() {
	q = {};
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0);
	fill(&dist[0][0], &dist[MAX_NM + 1][MAX_NM + 2], 0xf777777);
	q.push({ SR,SC, 0 });
	visit[SR][SC] = 1;
	dist[SR][SC] = 0;
	while (!q.empty()) {
		ST data = q.top(); q.pop();
		if (data.r == ER && data.c == EC) break;
		for (int idx = 0; idx < 8; idx++) {
			ST newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= H || newdata.c >= W) continue;
			if (maps[newdata.r][newdata.c] == -1) continue;
			if (!maps[newdata.r][newdata.c] && !maps[data.r][data.c])continue;
			newdata.d += maps[newdata.r][newdata.c];
			if (dist[newdata.r][newdata.c] > newdata.d) {
				dist[newdata.r][newdata.c] = newdata.d;
				visit[newdata.r][newdata.c] = visit[data.r][data.c];
				q.push(newdata);
			}
			else if (dist[newdata.r][newdata.c] == newdata.d) {
				visit[newdata.r][newdata.c] += visit[data.r][data.c];
				visit[newdata.r][newdata.c] %= 1000000007;
			}
		}
	}
}
int main(void) {
	freopen("boardgamemake.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		BFS();
		if (dist[ER][EC] == 0xf777777) cout << "#" << tc << " " << -1 << '\n';
		else cout << "#" << tc << " " << dist[ER][EC] << " " << visit[ER][EC] << '\n';
	}
	return 0;
}
#endif
#if 0 // 틀림
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX_HW (300)

struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
char maps[MAX_HW + 2][MAX_HW + 2];
struct COMP {
	bool operator()(ST a, ST b) {
		return a.d > b.d;
	}
};
POS DIR[] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
int DIST[MAX_HW + 2][MAX_HW + 2];
int visit[MAX_HW + 2][MAX_HW + 2];
priority_queue<ST, vector<ST>, COMP> q;
int H, W, T, SR, SC, ER, EC;
int maxx, maxcnt;
void init() {
	maxx = 0xf777777;
	maxcnt = 0;
}
void input() {
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'S') {
				SR = r;
				SC = c;
			}
			else if (maps[r][c] == 'E') {
				ER = r;
				EC = c;
			}
		}
	}
}
void BFS() {
	q = {};
	fill(&DIST[0][0], &DIST[H + 1][W + 1], 0xf777777);
	fill(&visit[0][0], &visit[H + 1][W + 1], 0);
	DIST[SR][SC] = 0;
	visit[SR][SC] = 1;
	q.push({ SR,SC,0 });
	while (!q.empty()) {
		ST data = q.top(); q.pop();
		if (data.r == ER && data.c == EC) {
			break;
		}
		for (int idx = 0; idx < 8; idx++) {
			ST ndata = data;
			ndata.r += DIR[idx].r;
			ndata.c += DIR[idx].c;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= H || ndata.c >= W) continue;
			if (maps[ndata.r][ndata.c] == '#') continue;
			if (maps[ndata.r][ndata.c] == 'R') {
				if (maps[data.r][data.c] == 'R') continue;
				//if (DIST[1][ndata.r][ndata.c]) continue;
				ndata.d--;
			}
			// 그냥 일반이면
			//if (DIST[0][ndata.r][ndata.c]) continue;
			ndata.d++;
			//if (DIST[ndata.r][ndata.c] < ndata.d) continue;
			if (DIST[ndata.r][ndata.c] == ndata.d) {
				visit[ndata.r][ndata.c] = (visit[ndata.r][ndata.c] + visit[data.r][data.c]) % 1000000007;
			}
			else if(DIST[ndata.r][ndata.c] > ndata.d){
				DIST[ndata.r][ndata.c] = ndata.d;
				visit[ndata.r][ndata.c] = visit[data.r][data.c];
				q.push(ndata);
			}
		}
	}
}
int main(void) {
	freopen("boardgamemake.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		BFS();
		if (DIST[ER][EC] == 0xf777777) {
			cout << "#" << tc << " " << -1 << '\n';
		}
		else cout << "#" << tc << " " << DIST[ER][EC] << " " << visit[ER][EC] << '\n';
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX_HW (300)

struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
POS DIR[] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
char maps[MAX_HW + 2][MAX_HW + 2];
int visit[2][MAX_HW + 2][MAX_HW + 2];
queue<ST> q;
int H, W, T, SR, SC, ER, EC;
int maxx, maxcnt;
void init() {
	maxx = 0xf777777;
	maxcnt = 0;
}
void input() {
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'S') {
				SR = r;
				SC = c;
			}
			else if (maps[r][c] == 'E') {
				ER = r;
				EC = c;
			}
		}
	}
}
void BFS() {
	q = {};
	fill(&visit[0][0][0], &visit[1][H+1][W+1], 0xf777777);
	visit[0][SR][SC] = 1;
	q.push({ SR,SC,0 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.d >= maxx) continue;
		for (int idx = 0; idx < 8; idx++) {
			ST ndata = data;
			ndata.r += DIR[idx].r;
			ndata.c += DIR[idx].c;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= H || ndata.c >= W) continue;
			if (maps[ndata.r][ndata.c] == '#') continue;
			if (ndata.r==ER && ndata.c==EC) {
				if ((ndata.d + 1) < maxx) {
					maxx = ndata.d + 1;
					maxcnt = 1;
					continue;
				}
				else if ((ndata.d + 1) == maxx) {
					maxcnt = (maxcnt+1) % 1000000007;
					continue;
				}
				else continue;
			}
			if (maps[ndata.r][ndata.c] == 'R') {
				if (maps[data.r][data.c] == 'R') continue;
				//if (visit[1][ndata.r][ndata.c]) continue;
				if (visit[1][ndata.r][ndata.c] < ndata.d) continue;
				visit[1][ndata.r][ndata.c] = ndata.d;
				q.push(ndata);
				continue;
			}
			// 그냥 일반이면
			//if (visit[0][ndata.r][ndata.c]) continue;
			ndata.d++;
			if (visit[0][ndata.r][ndata.c] < ndata.d) continue;
			visit[0][ndata.r][ndata.c] = ndata.d;
			q.push(ndata);
		}
	}
}
int main(void) {
	freopen("boardgamemake.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		BFS();
		if (maxx == 0xf777777) {
			cout << "#" << tc << " " << -1<< '\n';
		}
		else cout << "#" << tc << " " << maxx <<" "<<maxcnt << '\n';
	}
	return 0;
}
#endif