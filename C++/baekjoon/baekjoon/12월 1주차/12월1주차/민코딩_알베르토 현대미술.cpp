#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maps[6 + 1][6 + 1];
int N;
struct POS {
	int n;
	char cmd;
};
//vector<POS> order;
void makearr(int n, char cmd) {
	int Rdr[] = { -1,-1,1,1 };
	int Rdc[] = { 1,-1,-1,1 };
	int Ldr[] = { -1,-1,1,1 };
	int Ldc[] = { -1,1,1,-1 };
	if (cmd == 'R') {
		int cnt = 1;
		int dir = 0;
		int sr, sc, nr, nc;
		sr = 5; sc = n;
		nr = 5; nc = n;
		while (1) {
			if (maps[nr][nc]&& maps[nr][nc] > cnt) maps[nr][nc] = cnt;
			else if(!maps[nr][nc]) maps[nr][nc] = cnt;
			nr += Rdr[dir];
			nc += Rdc[dir];
			if (nr == 0 && nc == 5) {
				dir = 2;
			}
			if (nc > 5) {
				nr -= Rdr[dir];
				nc -= Rdc[dir];
				dir = 1; 
				nr += Rdr[dir];
				nc += Rdc[dir];
			}
			else if (nc < 0) {
				nr -= Rdr[dir];
				nc -= Rdc[dir];
				dir = 3;
				nr += Rdr[dir];
				nc += Rdc[dir];
			}
			else if (nr > 5) {
				nr -= Rdr[dir];
				nc -= Rdc[dir];
				dir = 0;
				nr += Rdr[dir];
				nc += Rdc[dir];
			}
			else if (nr < 0) {
				nr -= Rdr[dir];
				nc -= Rdc[dir];
				dir = 2;
				nr += Rdr[dir];
				nc += Rdc[dir];
			}
			if (nr == sr && nc == sc) break;
			cnt++;
		}
	}
	else {
		int cnt = 1;
		int dir = 3;
		int sr, sc, nr, nc;
		sr = 5; sc = n;
		nr = 5; nc = n;
		while (1) {
			if (maps[nr][nc] && maps[nr][nc] > cnt) maps[nr][nc] = cnt;
			else if (!maps[nr][nc]) maps[nr][nc] = cnt;
			nr += Ldr[dir];
			nc += Ldc[dir];
			if (nr == 0 && nc == 0) {
				dir = 2;
			}
			if (nc > 5) {
				nr -= Ldr[dir];
				nc -= Ldc[dir];
				dir = 3;
				nr += Ldr[dir];
				nc += Ldc[dir];
			}
			else if (nc < 0) {
				nr -= Ldr[dir];
				nc -= Ldc[dir];
				dir = 1;
				nr += Ldr[dir];
				nc += Ldc[dir];
			}
			else if (nr > 5) {
				nr -= Ldr[dir];
				nc -= Ldc[dir];
				dir = 0;
				nr += Ldr[dir];
				nc += Ldc[dir];
			}
			else if (nr < 0) {
				nr -= Ldr[dir];
				nc -= Ldc[dir];
				dir = 2;
				nr += Ldr[dir];
				nc += Ldc[dir];
			}
			if (nr == sr && nc == sc) break;
			cnt++;
		}
	}
}
void print() {
	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 6; c++) {
			if(!maps[r][c]) cout << "_";
			else cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
int main(void) {
	freopen("art.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;

	fill(&maps[0][0], &maps[5][6], 0);
	for (int i = 0; i < N; i++) {
		int n;
		char cmd;
		cin >> n >> cmd;
		makearr(n,cmd);
	}
	print();
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
int arr[6][6] = { 0 };
struct Node {
	int y, x;
};
int rightDirectY[4] = { -1, -1, 1, 1 };
int rightDirectX[4] = { 1, -1, -1, 1 };
int leftDirectY[4] = { -1, -1, 1, 1 };
int leftDirectX[4] = { -1, 1, 1, -1 };
vector<Node> shotRight(int index) {
	vector<Node> result;
	int turn = 0;
	int nowY = 5;
	int nowX = index;
	while (1) {
		if (turn == 4) break;
		int ny = nowY + rightDirectY[turn];
		int nx = nowX + rightDirectX[turn];
		if (ny < 0 || nx < 0 || ny >= 6 || nx >= 6) {
			turn++;
			continue;
		}
		result.push_back({ nowY, nowX });
		nowY = ny;
		nowX = nx;
	}
	return result;
}
vector<Node> shotLeft(int index) {
	vector<Node> result;
	int turn = 0;
	int nowY = 5;
	int nowX = index;
	while (1) {
		if (turn == 4) break;
		int ny = nowY + leftDirectY[turn];
		int nx = nowX + leftDirectX[turn];
		if (ny < 0 || nx < 0 || ny >= 6 || nx >= 6) {
			turn++;
			continue;
		}
		result.push_back({ nowY, nowX });
		nowY = ny;
		nowX = nx;
	}
	return result;
}
void fillColor(int arr[6][6], vector<Node> axis) {
	int color = 1;
	for (Node ax : axis) {
		if (arr[ax.y][ax.x] == 0) arr[ax.y][ax.x] = color;
		else if (arr[ax.y][ax.x] > color) arr[ax.y][ax.x] = color;
		color++;
	}
}
int main() {
	int n;
	cin >> n;
	int index;
	char ch;
	for (int i = 0; i < n; i++) {
		cin >> index >> ch;
		vector<Node> ret;
		if (ch == 'R') ret = shotRight(index);
		if (ch == 'L') ret = shotLeft(index);
		fillColor(arr, ret);
	}
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			if (arr[y][x] == 0) cout << '_';
			else cout << arr[y][x];
		}
		cout << '\n';
	}
	return 0;
}
#endif 