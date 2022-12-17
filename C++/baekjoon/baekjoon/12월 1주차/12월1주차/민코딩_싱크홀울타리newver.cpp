#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int maps[100 + 2][100 + 2];
int visit[100 + 2][100 + 2];
struct POS {
	int r, c;
};
queue<POS> q;
void init() {
	fill(&visit[1][1], &visit[100 + 1][100 + 2], 0);
	fill(&maps[1][1], &maps[100 + 1][100 + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> maps[r][c];
		}
	}
}
void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cout<< maps[r][c]<< " ";
		}
		cout << '\n';
	}
		cout << '\n';
}
int BFS(int sr, int sc) {
	POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	visit[sr][sc] = 1;
	q.push({ sr,sc });
	int minr=sr, maxr=sr, minc=sc, maxc=sc;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (!maps[newdata.r][newdata.c]) continue;
			visit[newdata.r][newdata.c]=1;
			q.push({ newdata.r,newdata.c });
			minr = min(newdata.r, minr);
			minc = min(newdata.c, minc);
			maxr = max(newdata.r, maxr);
			maxc = max(newdata.c, maxc);
		}
	}
	return 2 * ((maxr - minr + 1) + (maxc - minc + 1))+4;
}
void solve() {
	//print();
	int maxx = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (visit[r][c]) continue;
			if (!maps[r][c])  continue;
			int ret = BFS(r, c);
			if (maxx < ret) maxx = ret;
		}
	}
	cout << maxx<<'\n';
}
int main(void) {
	freopen("sinkhall.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr); 
	init();
	input();  
	solve(); 
	return 0;
}