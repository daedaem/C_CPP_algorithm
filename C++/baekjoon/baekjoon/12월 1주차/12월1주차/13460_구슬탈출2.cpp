#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_NM (10)

struct GOO {
	int rr, rc, br, bc;
	int dcnt;
	vector<vector<char>> newmap;
};
struct POS {
	int r, c;
};
POS DIR[] = { {-1,0},{0,1},{1,0}, {0,-1} };
queue<GOO> q;
vector<vector<char>> maps;
int visit[MAX_NM + 2][MAX_NM + 2][MAX_NM + 2][MAX_NM + 2];
int N, M;
int BR, BC, RR, RC, ER, EC;
void init() {
	maps.clear();
	//fill(&visit[0][0][0][0], &visit[MAX_NM + 1][MAX_NM + 1][MAX_NM + 1][MAX_NM + 2], 0);
}
void input() {
	cin >> N >> M;
	
	maps.resize(N,vector<char>(M,0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'O') {
				ER = r;
				EC = c;
			}
			else if (maps[r][c] == 'R') {
				RR = r;
				RC = c;
			}
			else if (maps[r][c] == 'B') {
				BR = r;
				BC = c;
			}
		}
	}
}
int goomove(int sr, int sc,int dir) {
	if (dir == 0) {
		while (sr >= 0) {
			if (sr < 0 || maps[sr][sc] == '#') {
				sr += 1;
				return sr;
			}
			else if (sr == ER && sc == EC) {
				return sr;
			}
			sr--;
		}
	}
	else if (dir == 1) {
		while (sc < M) {
			if (sc == M || maps[sr][sc] == '#') {
				sc -= 1;
				return sc;
			}
			else if (sr == ER && sc == EC) {
				return sc;
			}
			sc++;
		}
	}
	else if (dir == 2) {
		while (sr < N) {
			if (sr == N || maps[sr][sc] == '#') {
				sr -= 1;
				return sr;
			}
			else if (sr == ER && sc == EC) {
				return sr;
			}
			sr++;
		}
	}
	else if (dir == 3) {
		while (sc >= 0) {
			if (sc < 0 || maps[sr][sc] == '#') {
				sc += 1;
				return sc;
			}
			else if (sr == ER && sc == EC) {
				return sc;
			}
			sc--;
		}
	}
}
void print(vector<vector<char>>maps) {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
int BFS() {
	q = {};
	fill(&visit[0][0][0][0], &visit[MAX_NM + 1][MAX_NM + 1][MAX_NM + 1][MAX_NM + 2], 0);
	vector<vector<char>> nmap(N, vector<char>(M, 0));
	copy(maps.begin(), maps.end(), nmap.begin());
	//cout << "Before"<< '\n';
	//print(nmap);
	q.push({ RR,RC,BR,BC,0, nmap});
	visit[RR][RC][BR][BC] = 1;
	while (!q.empty()) {
		GOO data = q.front(); q.pop();
		if (data.dcnt == 10) continue;
		for (int didx = 0; didx < 4; didx++) {
			GOO newdata = data;
			newdata.dcnt++;
			if (didx == 0) {
				newdata.rr = goomove(newdata.rr, newdata.rc, didx);
				newdata.br = goomove(newdata.br, newdata.bc, didx);
				if (newdata.br == ER && newdata.bc == EC) continue;
				if (newdata.rr == ER && newdata.rc == EC) return newdata.dcnt;
				if (newdata.rr == newdata.br && newdata.bc == newdata.rc) {//�ڸ��� ������
					if (data.rr < data.br) { // ���� ���尡 �� ���� �־�����
						newdata.br = newdata.rr + 1;
					}
					else {
						newdata.rr = newdata.br + 1;
					}   
				}
			}
			else if (didx == 1) {
				newdata.rc = goomove(newdata.rr, newdata.rc, didx);
				newdata.bc = goomove(newdata.br, newdata.bc, didx);
				if (newdata.br == ER && newdata.bc == EC) continue;
				if (newdata.rr == ER && newdata.rc == EC) return newdata.dcnt;
				if (newdata.rr == newdata.br && newdata.bc == newdata.rc) {//�ڸ��� ������
					if (data.rc < data.bc) { // ������簡 �� ������ �־�����
						newdata.rc = newdata.bc - 1;
					}
					else {
						newdata.bc = newdata.rc - 1;
					}
				}
			}
			else if (didx == 2) {
				newdata.rr = goomove(newdata.rr, newdata.rc, didx);
				newdata.br = goomove(newdata.br, newdata.bc, didx);
				if (newdata.br == ER && newdata.bc == EC) continue;
				if (newdata.rr == ER && newdata.rc == EC) return newdata.dcnt;
				if (newdata.rr == newdata.br && newdata.bc == newdata.rc) {//�ڸ��� ������
					if (data.br < data.rr) { // ���� ���尡 �� �ؿ� �־�����
						newdata.br = newdata.rr - 1;
					}
					else {
						newdata.rr = newdata.br - 1;
					}
				}
			}
			else if (didx == 3) {
				newdata.rc = goomove(newdata.rr, newdata.rc, didx);
				newdata.bc = goomove(newdata.br, newdata.bc, didx);
				if (newdata.br == ER && newdata.bc == EC) continue;
				if (newdata.rr == ER && newdata.rc == EC) return newdata.dcnt;
				if (newdata.rr == newdata.br && newdata.bc == newdata.rc) {//�ڸ��� ������
					if (data.rc > data.bc) { // ������簡 �� �޿� �־�����
						newdata.rc = newdata.bc + 1;
					}
					else {
						newdata.bc = newdata.rc + 1;
					}
				}
			}
			if (visit[newdata.rr][newdata.rc][newdata.br][newdata.bc]) continue;
			newdata.newmap[data.rr][data.rc] = '.';
			newdata.newmap[data.br][data.bc] = '.';
			newdata.newmap[newdata.rr][newdata.rc] = 'R';
			newdata.newmap[newdata.br][newdata.bc] = 'B';
			visit[newdata.rr][newdata.rc][newdata.br][newdata.bc] = 1;
			q.push(newdata);
			/*cout << "#"<<newdata.dcnt << '\n';
			print(newdata.newmap);*/
		}
	}
	return -1;
}
int main(void) {
	freopen("escapegoosle2.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	cout <<BFS() << '\n';
	return 0;
}

