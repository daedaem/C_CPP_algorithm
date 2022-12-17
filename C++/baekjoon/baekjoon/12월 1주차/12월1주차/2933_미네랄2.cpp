#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX_RC (100)
#define MAX_N (100)

int R, C, N;
char maps[MAX_RC+2][MAX_RC+2];
int visit[MAX_RC + 2][MAX_RC + 2];
vector<int> draws;
int minerals;
int maxheight;
struct POS {
	int r, c;
};
queue<POS> q;
vector<vector<POS>> groups;
POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
void init() {
	draws.clear();
	minerals = 0;
	for(int i=0; i< groups.size();i++){
		groups[i].clear();
	}
}
void input() {
	cin >> R >> C;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'x') minerals++;
		}
	}
	cin >> N;
	draws.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> draws[i];
		draws[i] = R - draws[i] + 1;
	}
}
int breakmineral(int diridx, int sr){
	if (diridx) { // ������->��
		for (int c = C; c >= 1; c--) {
			if (maps[sr][c] == 'x') {
				maps[sr][c] = '.';
				return 1;
			}
		}
	}
	else { //��->��
		for (int c = 1; c <=C; c++) {
			if (maps[sr][c] == 'x') {
				maps[sr][c] = '.';
				return 1;
			}
		}
	}
	return 0;
}
void print() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
}

void makegroup(int sr,int sc,int gidx) {
	q = {};
	vector<POS> v;
	q.push({ sr,sc });
	v.push_back({ sr,sc });
	visit[sr][sc] = gidx+1;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			POS ndata = data;
			ndata.r += DIR[dir].r;
			ndata.c += DIR[dir].c;
			if (ndata.r<1 || ndata.c<1 || ndata.r>R || ndata.c>C) continue;
			if (visit[ndata.r][ndata.c]) continue;
			if (maps[ndata.r][ndata.c] == '.') continue;
			visit[ndata.r][ndata.c] = gidx + 1;
			v.push_back({ ndata.r, ndata.c });
			q.push(ndata);
		}
	}
	groups.push_back({ v });
}
void mapupdate() {
	fill(&maps[0][0], &maps[MAX_RC+1][MAX_RC+2], '.');
	for(int i=0; i<groups.size();i++){
		for (int k = 0; k<groups[i].size(); k++) {
			int r = groups[i][k].r;
			int c = groups[i][k].c;
			maps[r][c] = 'x';
		}
	}
}
int findmaxh(int gidx) {
	int maxgap = 0;
	for (int z = 1; z <= R; z++) {
		for (int k = 0; k < groups[gidx].size(); k++) {
			int r = groups[gidx][k].r;
			int c = groups[gidx][k].c;
			if (maps[r + z][c] == 'x') return maxgap;
			if (z + r > R) return maxgap;
		}
		maxgap = z;
	}
	return maxgap;
}
void gravity() {
	for (int i = 0; i < groups.size(); i++) {
		//print();
		int maxgap = 0;
		for (int k = 0; k < groups[i].size(); k++) {
			int r = groups[i][k].r;
			int c = groups[i][k].c;
			maps[r][c] = '.';
		}
		maxgap = findmaxh(i);
		
		for (int k = 0; k < groups[i].size(); k++) { 
			int r = groups[i][k].r;
			int c = groups[i][k].c;
			maps[r+maxgap][c] = 'x';
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int cc = 0; cc < groups.size(); cc ++ ) {
			groups[cc].clear();
		}
		if (!minerals) return;
		if (i % 2) {
			breakmineral(1, draws[i]);
		}
		else {
			breakmineral(0, draws[i]);
		}
		minerals--;

		fill(&visit[0][0], &visit[MAX_RC + 1][MAX_RC + 2], 0);
		int idx = 1;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				if (visit[r][c]) continue;
				if (maps[r][c] == '.') continue;
				makegroup(r,c,idx++);
			}
		}
		gravity();
	}
	print();
}
int main(void) {

	freopen("2933_mineral.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	T = 1;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
	}
	return 0;
}
