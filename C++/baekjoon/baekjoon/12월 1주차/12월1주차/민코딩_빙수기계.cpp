#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N (1000)

struct ICE {
	int cir, area;
};
struct POS {
	int r, c;
};
queue<POS> q;
vector<ICE> ices;
int N;
char maps[MAX_N + 2][MAX_N + 2];
int visit[MAX_N + 2][MAX_N + 2];
void init() {
	fill(&maps[0][0], &maps[MAX_N + 1][MAX_N + 2], '.');
	fill(&visit[0][0], &visit[MAX_N + 1][MAX_N + 2], 0);
	ices.clear();
}
void input() {
	cin >> N;
	for (int r = 1; r <= N; r++) {
		for(int c=1; c<=N;c++){
			cin >> maps[r][c];
		}
	}
}
void print() {
	for(int r=1; r<=N;r++){
		for (int c = 1; c <= N; c++) {
			cout << visit[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void BFS(int sr, int sc, int gidx) {
	POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	q.push({ sr,sc });
	visit[sr][sc] = 1;
	int cir = 0;
	int area = 1;	
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int didx = 0; didx < 4; didx++) {
			POS newdata = data;
			newdata.r += DIR[didx].r;
			newdata.c += DIR[didx].c;
			if (visit[newdata.r][newdata.c]) continue;
			if (maps[newdata.r][newdata.c] == '.') cir++;
			if (maps[newdata.r][newdata.c] == '#') {
				visit[newdata.r][newdata.c] = gidx;
				area++;
				q.push(newdata);
			}
		}
	}
	ices.push_back({cir, area});
}
bool comp(ICE a, ICE b) {
	if (a.area == b.area) return a.cir < b.cir;
	return a.area > b.area;
}
void solve() {
	int idx = 1;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (visit[r][c]) continue;
			if (maps[r][c] == '.') continue;
			BFS(r, c, idx++);
			//print();
		}
	}
	sort(ices.begin(), ices.end(), comp);
	cout << ices[0].area  << " " << ices[0].cir << '\n';
}
int main(void){
	freopen("icemachine.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	for (int tc = 1; tc <=T; tc++) {
		init();
		input();
		solve();
	}
	return 0;
}