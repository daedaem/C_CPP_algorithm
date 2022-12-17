#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N (15)
#define MAX_M (30)
struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
struct COMP {
	bool operator()(ST a, ST b) {
		if (a.d == b.d) {
			if (a.r == b.r) return a.c > b.c;
			return a.r > b.r;
		}
		return a.d > b.d;
	}
};
struct CONV {
	int r, c, dir, d;
};
struct CCOMP {
	bool operator()(CONV a, CONV b) {
		if (a.d == b.d) {
			return 	a.dir > b.dir;
		}
		return a.d > b.d;
	}
}; struct PE {
	int nr, nc;
	int campr, campc;
	int convr, convc;
	bool arrive;
};

vector<POS> camp;
PE people[MAX_M + 1];
int N, M;
int maps[MAX_N + 2][MAX_N + 2];
int campmaps[MAX_N + 2][MAX_N + 2];
int campvisit[MAX_N + 2][MAX_N + 2];
int convisit[MAX_N + 2][MAX_N + 2];
void init() {
	for (int i = 1; i <= MAX_M; i++) {
		people[i] = { 0,0,0,0,0,0 };
	}
	fill(&maps[0][0], &maps[MAX_N + 1][MAX_N + 2], 0);
	fill(&campmaps[0][0], &campmaps[MAX_N + 1][MAX_N + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> maps[r][c];
			if (maps[r][c]) {
				camp.push_back({ r,c });
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> people[i].convr >> people[i].convc;
	}
}
int checkallarived() {
	for (int i = 1; i <= M; i++) {
		if (!people[i].arrive) return 0;
	}
	return 1;
}
void moveToCamp(int pidx) {
	POS DIR[] = { {-1,0},{0,-1},{0,1},{1,0} };
	priority_queue<ST, vector<ST>, COMP> pq;
	fill(&campvisit[0][0], &campvisit[MAX_N + 1][MAX_N + 2], 0);
	int SR = people[pidx].convr;
	int SC = people[pidx].convc;
	pq.push({ SR,SC,0 });
	campvisit[SR][SC] = 1;
	while (!pq.empty()) {
		ST data = pq.top(); pq.pop();
		for (int didx = 0; didx < 4; didx++) {
			ST newdata = data;
			newdata.r += DIR[didx].r;
			newdata.c += DIR[didx].c;
			newdata.d++;
			if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>N) continue;
			if (campvisit[newdata.r][newdata.c]) continue;
			if (campmaps[newdata.r][newdata.c]) continue;
			if (maps[newdata.r][newdata.c]) {
				//campmaps[newdata.r][newdata.c] = pidx;
				//maps[newdata.r][newdata.c] = 0;
				people[pidx].campr = newdata.r;
				people[pidx].campc = newdata.c;
				people[pidx].nr = newdata.r;
				people[pidx].nc = newdata.c;
				return;
			}
			campvisit[newdata.r][newdata.c] = 1;
			pq.push(newdata);
		}
	}
}
void moveToConv(int pidx) {
	POS DIR[] = { {-1,0},{0,-1},{0,1},{1,0} };
	priority_queue<CONV, vector<CONV>, CCOMP> pq;
	fill(&convisit[0][0], &convisit[MAX_N + 1][MAX_N + 2], 0);
	int SR = people[pidx].nr;
	int SC = people[pidx].nc;
	int ER = people[pidx].convr;
	int EC = people[pidx].convc;
	pq.push({ SR,SC,-1,0 });
	convisit[SR][SC] = 1;
	while (!pq.empty()) {
		CONV data = pq.top(); pq.pop();
		for (int didx = 0; didx < 4; didx++) {
			CONV newdata = data;
			newdata.r += DIR[didx].r;
			newdata.c += DIR[didx].c;
			if (newdata.dir == -1) newdata.dir = didx;
			newdata.d++;
			if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>N) continue;
			if (convisit[newdata.r][newdata.c]) continue;
			if (campmaps[newdata.r][newdata.c]) continue;
			if (newdata.r == ER && newdata.c == EC) {
				people[pidx].nr += DIR[newdata.dir].r;
				people[pidx].nc += DIR[newdata.dir].c;
				if (people[pidx].nr == ER && people[pidx].nc == EC) {
					people[pidx].arrive = true;
					//campmaps[newdata.r][newdata.c] = pidx;
				}
				return;
			}
			convisit[newdata.r][newdata.c] = 1;
			pq.push(newdata);
		}
	}
}
void mapupdate() {
	for (int pidx = 1; pidx <= M; pidx++) {
		if (!people[pidx].campr && !people[pidx].campc) continue;
		maps[people[pidx].campr][people[pidx].campc] = 0;
		campmaps[people[pidx].campr][people[pidx].campc] = pidx;
		if (!people[pidx].arrive) continue;
		campmaps[people[pidx].convr][people[pidx].convc] = pidx;
	}
}
int solve() {
	for (int time = 1; ; time++) {
		for (int pidx = 1; pidx <= M; pidx++) {
			if (time == pidx) {
				moveToCamp(pidx);
			}
			if (time > pidx) {
				if (people[pidx].arrive) continue;
				moveToConv(pidx);
			}
		}
		mapupdate();
		int ret = checkallarived();
		//모두 도착했으면 끝

		if (ret) return time;
	}
	return -111111;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("codetreebread.txt", "r", stdin);
	for (int tc = 1; tc <= 1; tc++) {
		init();
		input();
		cout << solve() << '\n';
	}
	return 0;
}