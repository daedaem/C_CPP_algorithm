#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct POS {
	int r, c;
};
queue<POS> q;
vector<POS> fires;
queue<POS> fireq;
char maps[50 + 1][50 + 1];
int visit[50 + 1][50 + 1];
int firevisit[50 + 1][50 + 1];
int R, C;
POS me;
int ER, EC;
void print() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << maps[r][c];
		} cout << '\n';
	}
	cout << '\n';
}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'S') {
				me.r = r;
				me.c = c;
				q.push({ r,c });
			}
			else if (maps[r][c] == '*') {
				fires.push_back({ r,c });
			}
			else if (maps[r][c] == 'D') {
				ER = r;
				EC = c;
			}
		}
	}
}
int solve() {
	POS D[] = { {-1,0},{0,1} ,{1,0},{0,-1} };
	vector<POS> mypos;
	mypos.push_back({ me.r, me.c });

	int cnt = 0;
	while (1) {
		cnt++;
		if (mypos.empty()) return 0;
		for (int i = 0; i < mypos.size(); i++) {
			q.push({ mypos[i].r, mypos[i].c });
		}
		for (int i = 0; i < fires.size(); i++) {
			fireq.push({ fires[i].r, fires[i].c });
		}
		mypos.clear();
		fires.clear();
		while (!fireq.empty()) {
			POS data = fireq.front(); fireq.pop();
			for (int i = 0; i < 4; i++) {
				POS newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= R || newdata.c >= C) continue;
				if (firevisit[newdata.r][newdata.c]) continue;
				if (maps[newdata.r][newdata.c] == 'D') continue;
				if (newdata.r == me.r && newdata.c == me.c) continue;
				if (maps[newdata.r][newdata.c] == 'X') continue;
				maps[newdata.r][newdata.c] = '*';
				firevisit[newdata.r][newdata.c] = 1;
				fires.push_back(newdata);
			}
		}
		while (!q.empty()) {
			POS data = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				POS newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= R || newdata.c >= C) continue;
				if (visit[newdata.r][newdata.c]) continue;
				if (maps[newdata.r][newdata.c] == '*') continue;
				if (maps[newdata.r][newdata.c] == 'X') continue;
				if (newdata.r == ER && newdata.c == EC) return cnt;
				maps[newdata.r][newdata.c] = 'S';
				visit[newdata.r][newdata.c] = 1;
				mypos.push_back(newdata);
			}
		}
	}
	return 0;
}
int main(void) {
	freopen("1082_escapeinfire.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	int ret = solve();
	if (ret) cout << ret;
	else cout << "impossible";

	return 0;
}
