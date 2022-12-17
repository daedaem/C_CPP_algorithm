#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
#define MAX_WH (1000)
struct ST {
	int r, c, d;
};
struct POS {
	int r, c;
};
vector<ST> q;
vector<POS> fire;
int visit[MAX_WH + 2][MAX_WH + 2];
char maps[MAX_WH + 2][MAX_WH + 2];
int T;
int H, W, SR, SC;

void init() {
	q.clear();
	fire.clear();
}
void print() {
	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= W; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}		cout << '\n';

}
void input() {
	cin >> W >> H;
	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= W; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == '@') {
				SR = r;
				SC = c;
				q.push_back({ SR,SC,1 });
			}
			else if (maps[r][c] == '*') {
				fire.push_back({ r,c });
			}
		}
	}
}
int BFS() {
	/* 지도 밖으로 나가는데 1초 걸리는데 생각없이 0으로 해서 틀림 */
	if (SR == 1 || SC == 1 || SR == H || SC == W) return 1;

	POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };

	fill(&visit[0][0], &visit[MAX_WH + 1][MAX_WH + 2], 0);
	visit[SR][SC] = 1;
	vector<ST> newpath;
	vector<POS> newfire;
	while (1) {
		// 불붙이기
		newfire.clear();
		for (int i = 0; i < fire.size(); i++) {
			for (int idx = 0; idx < 4; idx++) {
				int dy = fire[i].r + D[idx].r;
				int dx = fire[i].c + D[idx].c;
				if (dy<1 || dx<1 || dy>H || dx>W) continue;
				if (maps[dy][dx] == '#') continue;
				if (maps[dy][dx] == '*') continue;
				maps[dy][dx] = '*';
				newfire.push_back({ dy,dx });
			}
		}
		fire.clear();
		fire.resize(newfire.size());
		copy(newfire.begin(), newfire.end(), fire.begin());

		//길가기
		// 만약에 newpath에 사이즈가 없으면 break;
		// 아니면 다시 채워넣고
		newpath.clear();
		if (q.empty()) break;
		for (int z = 0; z < q.size(); z++) {
			ST data = q[z];
			for (int i = 0; i < 4; i++) {
				ST newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				newdata.d++;
				if (newdata.r<1 || newdata.c<1 || newdata.r>H || newdata.c>W) continue;
				if (maps[newdata.r][newdata.c] == '.' && (newdata.r == 1 || newdata.c == 1 || newdata.r == H || newdata.c == W)) {
					return newdata.d;
				}
				if (visit[newdata.r][newdata.c]) continue;
				if (maps[newdata.r][newdata.c] == '#') continue;
				if (maps[newdata.r][newdata.c] == '*') continue;
				newpath.push_back({ newdata.r, newdata.c, newdata.d });
				maps[newdata.r][newdata.c] = '@';
				visit[newdata.r][newdata.c] = 1;
			}
		}
		if (newpath.empty()) break;
		q.clear();
		q.resize(newpath.size());
		copy(newpath.begin(), newpath.end(), q.begin());
	}
	return -1;
}
void solve() {
	int ret = BFS();
	if (ret == -1) cout << "IMPOSSIBLE\n";
	else cout << ret << '\n';
}

int main(void) {
	freopen("fire.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		solve();
	}
	return 0;
}
#endif
//
#if 0
#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;i++)
using PP = pair<int, int>;

const int Nmax = 1009, INF = 1e8;
int TC, R, C, fire[Nmax][Nmax], a[Nmax][Nmax], sr, sc, ans;
int dr[4] = { 1,-1,0,0 }, dc[4] = { 0,0,1,-1 };

int main() {
	freopen("fire.txt", "r", stdin);
	ios_base::sync_with_stdio(0);    cin.tie(0);
	cin >> TC;
	while (TC--) {
		vector <PP> F, G;
		ans = -1;
		cin >> C >> R;
		REP(i, 1, R) {
			string S;   cin >> S;
			REP(j, 1, C) {
				a[i][j] = fire[i][j] = INF;
				if (S[j - 1] == '#') fire[i][j] = -1;
				else if (S[j - 1] == '*') {
					fire[i][j] = 0;   F.push_back({ i,j });
				}
				else if (S[j - 1] == '@') {
					sr = i;   sc = j;
				}
			}
		}
		//불
		while (!F.empty()) {
			for (auto f : F) {
				int ar = f.first, ac = f.second, tt = fire[ar][ac] + 1;
				REP(k, 0, 3) {
					int fr = ar + dr[k], fc = ac + dc[k];
					if (fr<1 || fr>R || fc<1 || fc>C) continue;
					if (fire[fr][fc] > tt) {
						fire[fr][fc] = tt;    G.push_back({ fr,fc });
					}
				}
			}
			F = G;    G.clear();
		}

		queue <PP> Q;
		a[sr][sc] = 0;    Q.push({ sr,sc });
		while (!Q.empty()) {
			int br = Q.front().first, bc = Q.front().second, tt = a[br][bc] + 1;
			Q.pop();
			REP(k, 0, 3) {
				int gr = br + dr[k], gc = bc + dc[k];
				if (gr<1 || gr>R || gc<1 || gc>C) {
					ans = tt;     break;
				}
				if (fire[gr][gc] > tt && a[gr][gc] > tt) {
					a[gr][gc] = tt;   Q.push({ gr,gc });
				}
			}
			if (ans > 0) break;
		}
		if (ans > 0) cout << ans << "\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}

#endif