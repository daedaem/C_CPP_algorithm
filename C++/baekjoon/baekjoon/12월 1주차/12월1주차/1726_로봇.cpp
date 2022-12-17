#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX_NM (100)

struct ST {
	int r, c, dir,d;
};
struct POS {
	int r, c;
};
POS D[] = { {},{-1,0},{0,1},{1,0},{0,-1} };
queue<ST> q;
int M, N;
int arr[MAX_NM + 2][MAX_NM + 2]; 
int visit[5][MAX_NM + 2][MAX_NM + 2];
int SR, SC, SDIR;
int ER, EC, EDIR;
void input() {
	cin >> M >> N;
	for (int r = 1; r <= M; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> arr[r][c];
		}
	}
	cin >> SR >> SC >> SDIR >> ER >> EC >> EDIR;
	if (SDIR == 1)	SDIR = 2;
	else if (SDIR == 2) SDIR = 4;
	else if (SDIR == 3) SDIR = 3;
	else if (SDIR == 4) SDIR = 1;
	if (EDIR == 1)	EDIR = 2;
	else if (EDIR == 2) EDIR = 4;
	else if (EDIR == 3) EDIR = 3;
	else if (EDIR == 4) EDIR = 1;
}
int solve() {
	q = {};
	if (SR == ER && SC == EC && SDIR == EDIR) return 0;

	fill(&visit[0][0][0], &visit[4][MAX_NM+1][MAX_NM + 2], 0);
	q.push({ SR,SC,SDIR,0 });
	visit[SDIR][SR][SC] = 1;

	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.r == ER && data.c == EC && data.dir == EDIR) return data.d;
		for (int k = 1; k <= 3; k++) {
			ST newdata = data;
			newdata.r += (D[data.dir].r*k);
			newdata.c += (D[data.dir].c*k);
			newdata.d++;
			if (newdata.r < 1 || newdata.c < 1 || newdata.r > M || newdata.c > N) break;
			if (visit[newdata.dir][newdata.r][newdata.c]) continue;
			if (arr[newdata.r][newdata.c]) break;
			visit[newdata.dir][newdata.r][newdata.c] = 1;
			q.push(newdata);
		}
		for(int i=1;i<=2;i++){
			ST newdata = data;
			if (i == 1) {
				newdata.dir = newdata.dir +1;
				if (newdata.dir > 4) newdata.dir -= 4;
			}
			else {
				newdata.dir = newdata.dir - 1;
				if (newdata.dir < 1) newdata.dir += 4;
			}
			newdata.d++;
			if (visit[newdata.dir][newdata.r][newdata.c]) continue;
			if (arr[newdata.r][newdata.c]) continue;
			visit[newdata.dir][newdata.r][newdata.c] = 1;
			q.push(newdata);
		}
	}
	return -1;
}
int main(void) {
	freopen("robot.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	cout << solve()<<'\n';
	return 0;
}