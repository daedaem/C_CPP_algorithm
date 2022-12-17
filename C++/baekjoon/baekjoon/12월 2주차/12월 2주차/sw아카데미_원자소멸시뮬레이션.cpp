#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_N (1000)
#define MAX_XY (4000)
struct POS {
	int r, c;
};
struct AT {
	int r, c;
	int dir, e, alive;
};
POS DIR[] = { {-1,0},{1,0},{0,-1},{0,1} };
//AT atoms[MAX_N + 2];
int maps[MAX_XY + 2][MAX_XY + 2];
vector<AT> atoms;
int T, N, result;
void init() {
	atoms.clear();
	memset(maps, 0, sizeof(maps));
	//fill(&maps[0][0], &maps[MAX_XY + 1][MAX_XY + 2], 0);
	result = 0;
}
void input() {
	cin >> N;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int x, y, dir, e;
		cin >> x >> y >> dir >> e;
		if (dir == 0) {
			atoms.push_back({ (y + 1000) * 2, (x + 1000) * 2,1,e, true });
			maps[(y + 1000) * 2][(x + 1000) * 2]++;
		}
		else if (dir == 1) {
			atoms.push_back({ (y + 1000) * 2, (x + 1000) * 2,0,e, true });
			maps[(y + 1000) * 2][(x + 1000) * 2]++;
		}
		else {
			atoms.push_back({(y + 1000) * 2, (x + 1000) * 2, dir, e, true});
			maps[(y + 1000) * 2][(x + 1000) * 2]++;
		}
	}
}
void moveAndUpdate() {
	
	for (int i=0; i <atoms.size(); i++) {
		if (!atoms[i].alive) continue;
		int nr = atoms[i].r;
		int nc = atoms[i].c;
		int dy = nr+DIR[atoms[i].dir].r;
		int dx = nc+DIR[atoms[i].dir].c;
		
		if (dy > MAX_XY || dy < 0 || dx > MAX_XY || dx < 0) {
			maps[nr][nc] =0;
			atoms[i].alive = false;
		}
		else {
			maps[nr][nc] = 0;
			maps[dy][dx]++;
			atoms[i].r = dy;
			atoms[i].c = dx;
		}
	}
	for (int i = 0; i < atoms.size(); i++) {
		if (!atoms[i].alive) continue;
		int r = atoms[i].r;
		int c = atoms[i].c;
		
		if (maps[r][c] >= 2) {

			for (int j = 0; j < atoms.size(); j++) {
				if (i == j) continue;
				if (!atoms[j].alive) continue;

				if (r == atoms[j].r && c == atoms[j].c) {
					result += atoms[j].e;
					atoms[j].alive = false;
				}
			}
			maps[r][c] = 0;
			result += atoms[i].e;
			atoms[i].alive = false;
		}

	}
	
}
int check() {
	for (int i =0; i < N; i++) {
		if (atoms[i].alive) return 0;
	}
	return true;
}
void solve() {
	//int en = 2000;
	if (atoms.size() == 0 || atoms.size() == 1) {
		result = 0;
		return;
	}
	while (1) {
		moveAndUpdate();
		int ret= check();
		if (ret) return;
	}
}
int main(void) {
	freopen("atom_erase_simulation.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << result << '\n';
	}
}