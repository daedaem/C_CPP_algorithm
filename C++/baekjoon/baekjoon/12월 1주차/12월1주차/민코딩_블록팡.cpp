#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 그전에 visit 초기화전체 스캔하면서 좌우 4각형에 같은게 있는지 보고 있으면 ff시작
//ff하고 나면 gravity 하고
//
struct POS {
	int r, c;
};
vector<vector<int>> maps;
vector<vector<int>> visit;
queue<POS> q;
int N, K;
void init() {
	for (int i = 0; i < maps.size(); i++) {
		maps[i].clear();
		visit[i].clear();
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < 10; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
void input() {
	cin >> N >> K;
	maps.resize(N, vector<int>(10));
	visit.resize(N, vector<int>(10));

	for (int r = 0; r < N; r++) {
		string a; cin >> a;
		for (int c = 0; c < a.size(); c++) {
			maps[r][c] = a[c] - '0';
		}
	}
}
int BFS(int sr, int sc, int num) {
	POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	q.push({ sr,sc });
	visit[sr][sc] = 1;
	int cnt = 1;
	vector<POS> erase;
	erase.push_back({ sr,sc });
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int idx = 0; idx < 4; idx++) {
			POS newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= 10) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (maps[newdata.r][newdata.c] != num) continue;
			erase.push_back({ newdata.r,newdata.c });
			visit[newdata.r][newdata.c] = 1;
			q.push(newdata);
			cnt++;
		}
	}
	if (cnt < K) return 0;
	else {
		for (int i = 0; i < erase.size(); i++) {
			maps[erase[i].r][erase[i].c] = 0;
		}
	}
	return 1;
}
void printvisit() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < 10; c++) {
			cout << visit[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int check() {
	for (int r = 0; r < N; r++) {
		fill(visit[r].begin(), visit[r].end(), 0);
	}
	int cnt = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < 10; c++) {
			if (visit[r][c]) continue;
			if (!maps[r][c]) continue;
			cnt += BFS(r,c, maps[r][c]);
			//print();
		}
	}
	return cnt;
}
void gravity() {
	for (int c = 0; c < 10; c++) {
		deque<int> temp;
		for (int r = N - 1; r >= 0; r--) {
			if (!maps[r][c]) continue;
			temp.push_back(maps[r][c]);
			maps[r][c] = 0;
		}
		int idx = N-1;
		while (!temp.empty()) {
			int num = temp.front(); temp.pop_front();
			maps[idx][c] = num;
			idx--;
		}
	}
}
void solve() {
	//print();
	while (1) {
		//printvisit();
		int ret = check();
		//print();
		if (!ret) break;
		gravity();
		//print();
	}
	print();
}
int main(void) {
	freopen("blockpang.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
}