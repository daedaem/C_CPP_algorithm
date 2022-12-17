#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAXN (5)

struct POS {
	int r, c;
};
struct ST {
	int r, c, dir;
};
deque<ST> A;
deque<ST> B;

POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<int> order[2];
int flank[MAXN + 2][MAXN + 2];
int maps[MAXN + 2][MAXN + 2];
int N;
void input() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cin >> flank[r][c];
		}
	}
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int r = 0; r < N; r++) {
			char cc; cin >> cc;
			if (cc == 'U') order[i].push_back(0);
			else if (cc == 'R') order[i].push_back(1);
			else if (cc == 'D') order[i].push_back(2);
			else if (cc == 'L') order[i].push_back(3);
		}
	}
	A.push_back({ 0,0,order[0][0] });
	B.push_back({ 4,4,order[1][0] });
	maps[0][0] = 1;
	maps[4][4] = 2;
}
void movingA(int oidx) {
	// A해마
	// 움직이기전에 맵 지우기
	int lens = A.size();
	for (int hidx = lens-1; hidx>=0 ; hidx--) {
		if (hidx == 0) {
			int dy = A[hidx].r;
			int dx = A[hidx].c;
			int dir = A[hidx].dir;
			dir = order[0][oidx];
			dy = (A[hidx].r + D[dir].r) % 5;
			dx = (A[hidx].c + D[dir].c) % 5;
			if (dy< 0) dy = 4;
			if (dx < 0) dx = 4;
			if (lens < 3 && flank[dy][dx]) {//길이가 되고 플랑크톤존재하면
				flank[dy][dy] = 0;
				A.push_back(A[hidx]);// 맨뒤녀석을 추가
			}
			A[hidx].r = dy;
			A[hidx].c = dx;
			A[hidx].dir = dir;
		}
		else {
			//나머지
			A[hidx] = A[hidx - 1];
		}
	}
}
void movingB(int oidx) {
	int lens = B.size();
	for (int hidx = lens - 1; hidx >= 0; hidx--) {
		if (hidx == 0) {
			int dy = B[hidx].r;
			int dx = B[hidx].c;
			int dir = B[hidx].dir;
			dir = order[1][oidx];
			dy = (B[hidx].r + D[dir].r) % 5;
			dx = (B[hidx].c + D[dir].c) % 5;
			if (dy < 0) dy = 4;
			if (dx < 0) dx = 4;
			if (lens < 3 && flank[dy][dx]) {//길이가 되고 플랑크톤존재하면
				flank[dy][dy] = 0;
				B.push_back(B[hidx]);// 맨뒤녀석을 추가
			}
			B[hidx].r = dy;
			B[hidx].c = dx;
			B[hidx].dir = dir;
		}
		else {
			//나머지
			B[hidx] = B[hidx - 1];
		}
	}	
}
int mapupdate() {
	// 부딪히는지 보자 업데이트하면서
	for (int i = 0; i < A.size(); i++) {
		maps[A[i].r][A[i].c] = 1;
	}
	for (int i = 0; i < B.size(); i++) {
		if (maps[B[i].r][B[i].c] == 1) return 0;
		maps[B[i].r][B[i].c] = 2;
	}
	return 1;
}
void print() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cout << maps[r][c]<<" ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int solve() {
	//print();
	//cout << "before\n";
	for (int oidx = 0; oidx < N; oidx++) {
		fill(&maps[0][0], &maps[MAXN + 1][MAXN + 2],0);
		movingA(oidx);
		movingB(oidx);
		int ret = mapupdate();
		print();
		if (!ret) return 0;
	}
	return A.size() + B.size();
}
int main(void) {
	freopen("haemafamily.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	int ret = solve();
	if (!ret) cout << "Accident\n";
	else cout << ret << '\n';
	return 0;
}