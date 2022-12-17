#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_NM (10)

struct ST {
	int r, c, d;
	char type;
};
struct POS {
	int r, c;
};
struct QD{
	int r, c, d;
};
int N, M, K;
int maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
vector<POS> A;
vector<POS> B;
vector<ST> store;
queue<QD> q;
int result;
void init() {
	store.clear();
	A.clear();
	B.clear();
	result = 0;
}
void input() {
	cin >> N >> M >> K;
	int idx = 0;
	for(int r=0; r<N;r++){
		for (int c = 0; c < M; c++) {
			char cc;  cin >> cc;
			if (cc == 'A') {
				maps[r][c] = 0;
				A.push_back({ r,c });
			}
			else if (cc == 'C') {
				maps[r][c] = ++idx;
				store.push_back({ r,c,0xf777777, 'A' });
			}
		}
	}
}
int calcDistance(int sr, int sc) {
	POS DIR[] = { {-1,0},{0,1},{1,0}, {0,-1} };
	q = {};
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0);
	q.push({ sr,sc,0 });
	visit[sr][sc] = 1;
	while (!q.empty()) {
		QD data = q.front(); q.pop();
		for (int didx = 0; didx < 4; didx++) {
			QD ndata = data;
			ndata.r += DIR[didx].r;
			ndata.c += DIR[didx].c;
			ndata.d++;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= N || ndata.c >= M) continue;
			if (visit[ndata.r][ndata.c]) continue;
			visit[ndata.r][ndata.c] = 1;
			if (maps[ndata.r][ndata.c]) {
				int sidx = maps[ndata.r][ndata.c];
				if (store[sidx - 1].d >= ndata.d) {
					store[sidx - 1].type = 'B';
					return 1;
				}
				else return 0;
			}
			q.push(ndata);
		}
	}
	return -1111111111;
}
int findstore(){
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		int ret = calcDistance(B[i].r, B[i].c);
	}
	for (int i = 0; i < store.size(); i++) {
		if (store[i].type == 'B') {
			cnt++;
		}
	}
	return cnt;
}
void makeBcomb(int start, int dep) {
	if (dep == K) {
		int ret = findstore();
		if (result < ret) result = ret;
		//for (int i = 0; i < dep; i++) {
		//	cout << B[i].c << " ";
		//}
		//cout << '\n';
		return;
	}
	for (int i = start; i < M; i++) {
		B.push_back({ N -1,i });
		makeBcomb(i + 1, dep+1);
		B.pop_back();
	}
}
void makeA(int sr, int sc) {
	POS DIR[] = { {-1,0},{0,1},{1,0}, {0,-1} };
	q = {};
	fill(&visit[0][0], &visit[MAX_NM + 1][MAX_NM + 2], 0);
	q.push({ sr,sc,0 });
	visit[sr][sc] = 1;
	while (!q.empty()) {
		QD data = q.front(); q.pop();
		for (int didx = 0; didx < 4; didx++) {
			QD ndata = data;
			ndata.r += DIR[didx].r;
			ndata.c += DIR[didx].c;
			ndata.d++;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= N || ndata.c >= M) continue;
			if (visit[ndata.r][ndata.c]) continue;
			visit[ndata.r][ndata.c] = 1;
			if (maps[ndata.r][ndata.c]) {
				int sidx = maps[ndata.r][ndata.c];
				store[sidx - 1].d = min(store[sidx - 1].d, ndata.d);
				return;
			}
			q.push(ndata);
		}
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void solve() {
	for (int i = 0; i < A.size(); i++) {
		makeA(A[i].r, A[i].c);
	}
	//print();
	makeBcomb(0,0);
}
int main(void) {
	freopen("chickenlover.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	input();
	solve();
	cout << result;
	return 0;
}