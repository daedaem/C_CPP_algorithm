#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct POS {
	int r, c;
};
vector<POS> squares[4];
//set<vector<POS>> squares;
char papper[5][5];
char board[10+1][10+1];
int visit[5][5];
vector<POS> spaces;
void input() {
	for (int r = 0; r < 4; r++) {
		for(int c=0; c<4;c++){
			cin >> papper[r][c];
		}
	}
	for(int r=0; r<10;r++){
		for (int c = 0; c < 10; c++) {
			cin >> board[r][c];
			if (board[r][c] == '_') spaces.push_back({ r,c });
		}
	}
}
void print() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << papper[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
void rotate(int idx) {
	char newpapper[5][5];
	fill(&newpapper[0][0], &newpapper[4][5], '_');
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			newpapper[c][4 - r - 1] = papper[r][c];
		}
	}
	int sr = 0;
	int sc = 0;
	int flag = 0;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (!flag && newpapper[r][c] == '$') {
				sr = r;
				sc = c;
				flag = 1;
				squares[idx].push_back({ r-r,c-c });
			}
			else if (flag && newpapper[r][c] == '$') {
				squares[idx].push_back({ r - sr,c - sc });
			}
		}
	}
	copy(&newpapper[0][0], &newpapper[4][5], &papper[0][0]);
}
int checksame(int i , int j) {
	for (int c = 0; c < squares[i].size(); c++) {
		if ((squares[i][c].r != squares[j][c].r) || (squares[i][c].c != squares[j][c].c)) return 0;
	}
	return 1;
}
void findcomb() {
	for (int i = 0; i < 4; i++) {
		rotate(i);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (squares[i].empty() || squares[j].empty()) continue;
			int ret = checksame(i,j);
			if(ret) squares[j].clear();
		}
	}
}
void printvisit() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << visit[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
int matching(int sidx, int zidx) {
	int sr = spaces[sidx].r;
	int sc = spaces[sidx].c;
	for (int i = 0; i < squares[zidx].size(); i++) {
		int dy = sr + squares[zidx][i].r;
		int dx = sc + squares[zidx][i].c;
		if (dy < 0 || dx < 0 || dy >= 10 || dx >= 10) return 0;
		if (board[dy][dx] == '#') return 0;
	}
	//for (int i = 0; i < squares[zidx].size(); i++) {
	//	int dy = sr + squares[zidx][i].r;
	//	int dx = sc + squares[zidx][i].c;
	//	visit[dy][dx] = 1;
	//}
	return 1;
}
void solve() {
	findcomb();
	int cnt = 0;
	for (int z = 0; z < 4; z++) { // 해당 도형대로 넣어보기
		if (squares[z].empty()) continue;
		fill(&visit[0][0], &visit[4][5], 0);
		for (int i = 0; i < spaces.size(); i++) {
			int ret = matching(i, z);
			if (ret) cnt++;
		}
		//printvisit();
	}
	cout << cnt;
	//printvisit();
}

int main(void) {
	freopen("insertfigure.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	return 0;
}