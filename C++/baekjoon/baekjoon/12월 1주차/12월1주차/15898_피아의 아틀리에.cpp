#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int perm[3];
int permvisit[11];
int bowl[5][5];
char bowlcolor[5][5];
vector<vector<int>> grad[10];
vector<vector<char>> colors[10];
int N;
void init() {
	fill(&permvisit[0], &permvisit[10], 0);
	for (int i = 0; i < 10; i++) {
		grad[i].clear();
		colors[i].clear();
		grad[i].resize(4, vector<int>(4, 0));
		colors[i].resize(4, vector<char>(4,'W'));
	}
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				cin >> grad[i][r][c];
			}
		}
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				cin >> colors[i][r][c];
			}
		}
	}
	fill(&bowl[0][0], &bowl[4][5], 0);
	fill(&bowlcolor[0][0], &bowlcolor[4][5], 'W');
}
void print() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cout << bowl[r][c] << bowlcolor[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void rotate(int gidx, int rot_rep, int sr, int sc) {
	int rotategrad[4][4];
	char rotatecolor[4][4];
	if (rot_rep == 0) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (colors[gidx][r][c] != 'W') {
					bowlcolor[sr+r][sc+c] = colors[gidx][r][c];
				}
				if (bowl[sr + r][sc + c] + grad[gidx][r][c] <= 0) {
					bowl[sr + r][sc + c] = 0;
				}
				else if (bowl[sr + r][sc + c] + grad[gidx][r][c] >= 9) {
					bowl[sr + r][sc + c] = 9;
				}
				else  {
					bowl[sr + r][sc + c] += grad[gidx][r][c];
				}
			}
		}
	}
	if (rot_rep == 1) { 
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				rotategrad[c][4-1-r] = grad[gidx][r][c];		
				rotatecolor[c][4 - 1 - r] = colors[gidx][r][c];
			}
		}
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (rotatecolor[r][c] != 'W') {
					bowlcolor[sr + r][sc + c] = rotatecolor[r][c];
				}
				if (bowl[sr + r][sc + c] + rotategrad[r][c] <= 0) {
					bowl[sr + r][sc + c] = 0;
				}
				else if (bowl[sr + r][sc + c] + rotategrad[r][c] >= 9) {
					bowl[sr + r][sc + c] = 9;
				}
				else {
					bowl[sr + r][sc + c] += rotategrad[r][c];
				}
			}
		}
	}
	else if (rot_rep==2) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				rotategrad[4 - 1 - r][4 - 1 - c] = grad[gidx][r][c];
				rotatecolor[4 - 1 - r][4 - 1 - c] = colors[gidx][r][c];
			}
		}
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (rotatecolor[r][c] != 'W') {
					bowlcolor[sr + r][sc + c] = rotatecolor[r][c];
				}
				if (bowl[sr + r][sc + c] + rotategrad[r][c] <= 0) {
					bowl[sr + r][sc + c] = 0;
				}
				else if (bowl[sr + r][sc + c] + rotategrad[r][c] >= 9) {
					bowl[sr + r][sc + c] = 9;
				}
				else {
					bowl[sr + r][sc + c] += rotategrad[r][c];
				}
			}
		}
	}
	else if (rot_rep == 3) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				rotategrad[4-1-c][r] = grad[gidx][r][c];
				rotatecolor[4 - 1 - c][r] = colors[gidx][r][c];
			}
		}
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (rotatecolor[r][c] != 'W') {
					bowlcolor[sr + r][sc + c] = rotatecolor[r][c];
				}
				if (bowl[sr + r][sc + c] + rotategrad[r][c] <= 0) {
					bowl[sr + r][sc + c] = 0;
				}
				else if (bowl[sr + r][sc + c] + rotategrad[r][c] >= 9) {
					bowl[sr + r][sc + c] = 9;
				}
				else {
					bowl[sr + r][sc + c] += rotategrad[r][c];
				}
			}
		}
	}
}
int check() {
	int cnt = 0;
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			if (bowlcolor[r][c] == 'W') continue;
			else if (bowlcolor[r][c] == 'R') cnt += (7 * bowl[r][c]);
			else if (bowlcolor[r][c] == 'B') cnt += (5 * bowl[r][c]);
			else if (bowlcolor[r][c] == 'G') cnt += (3 * bowl[r][c]);
			else if (bowlcolor[r][c] == 'Y') cnt += (2 * bowl[r][c]);
		}
	}
	return cnt;
}
int maxx = 0;
void DFS(int dep) {
	if (dep == 3) {
		int ret = check();
		
		/*for (int i = 0; i < 3; i++) {
			cout << perm[i] << " ";
		}
		cout << "	";
		for (int i = 0; i < 3; i++) {
			cout << rvisit[i] << " ";
		}*/
		//cout << '\n';
		if (maxx < ret) {
			//print();
			maxx = ret;
		}
		return;
	}
	int backup[5][5];
	char backupcolor[5][5];
	copy(&bowl[0][0], &bowl[4][5], &backup[0][0]);
	copy(&bowlcolor[0][0], &bowlcolor[4][5], &backupcolor[0][0]);
	for (int gidx = 0; gidx < N; gidx++) {
		if (permvisit[gidx]) continue;
		perm[dep]=gidx;
		permvisit[gidx] = 1;
		for (int posr = 0; posr < 2; posr++) {
			for(int posc = 0; posc < 2; posc++) {
				for (int rotate_rep = 0; rotate_rep < 4; rotate_rep++) {
					rotate(gidx, rotate_rep, posr, posc);
					DFS(dep + 1);
					copy(&backup[0][0], &backup[4][5], &bowl[0][0]);
					copy(&backupcolor[0][0], &backupcolor[4][5], &bowlcolor[0][0]);
				}
			}
		}
		permvisit[gidx] = 0;
	}
}
void solve() {
	DFS(0);
}
int main(void) {
	freopen("15898_piaattelie.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	cout << maxx << '\n';
}