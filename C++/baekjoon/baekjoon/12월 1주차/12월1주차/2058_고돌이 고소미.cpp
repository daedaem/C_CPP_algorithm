#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N (25)

int maps[MAX_N + 2][MAX_N + 2];
int visit[MAX_N + 2][MAX_N + 2][MAX_N + 2][MAX_N + 2];
struct POS {
	int r, c;
};
struct ST{
	int dor, doc, sor, soc, d;
};
queue<ST> q;
POS D[] = { {0,0},{-1,0},{-1,1},{0,1},{1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
int N;
int DOSR, DOSC, DOER, DOEC;
int SOSR, SOSC, SOER, SOEC;
void input() {
	cin >> N;
	cin >> DOSR >> DOSC >> DOER >> DOEC;
	cin >> SOSR >> SOSC >> SOER >> SOEC;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> maps[r][c];
		}
	}
}
int checkContact(ST data) {
	for (int i = 0; i <= 8; i++) {
		int dy = data.dor+D[i].r;
		int dx = data.doc+D[i].c;
		if (dy == data.sor && dx == data.soc) return 1;
	}
	return 0;
}
int solve() {
	q = {};
	fill(&visit[1][1][1][1], &visit[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 2], 0);
	visit[DOSR][DOSC][SOSR][SOSC] = 1;
	q.push({ DOSR, DOSC, SOSR, SOSC, 0 });
	if (DOSR == DOER && DOSC == DOEC && SOSR == SOER && SOSC == SOEC) return 0;

	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int R = 0; R < 9; R++) {
			for (int S = 0; S < 9; S++) {
				ST newdata = data;
				newdata.dor += D[R].r;
				newdata.doc += D[R].c;
				newdata.sor += D[S].r;
				newdata.soc += D[S].c;
				newdata.d++;
				if (newdata.dor<1 || newdata.doc<1 || newdata.dor>N || newdata.doc>N) continue;
				if (newdata.sor<1 || newdata.soc<1 || newdata.sor>N || newdata.soc>N) continue;
				if (maps[newdata.dor][newdata.doc]) continue;
				if (maps[newdata.sor][newdata.soc]) continue;
				if (visit[newdata.dor][newdata.doc][newdata.sor][newdata.soc]) continue;
				if (checkContact(newdata)) continue;
				if (newdata.dor == DOER && newdata.doc == DOEC && newdata.sor == SOER && newdata.soc == SOEC) return newdata.d;
				visit[newdata.dor][newdata.doc][newdata.sor][newdata.soc] = 1;
				q.push(newdata);
			}
		}
	}
	return -1;
}
int main(void) {
	freopen("godolgosomi.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	cout <<solve()<<'\n';
	return 0;
}
