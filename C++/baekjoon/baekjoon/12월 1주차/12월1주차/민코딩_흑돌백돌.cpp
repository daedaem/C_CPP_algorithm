#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define WH (1)
#define BK (2)

struct POS {
	int r, c;
};

int N;
int board[8 + 1][8 + 1];
vector<POS> order;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c; cin >> c >> r;
		order.push_back({ 7-r,c });
	}
}
void checkUD(int sr, int sc) {
	// 상하
	int cnt = 0;
	int flag = 0;
	//int duy = sr - 1;
	//int ddy = sr + 1;
	//if (duy < 0 || !board[duy][sc]) {
	//	cnt++;
	//	flag = 0;
	//}
	//if (ddy > 7 || !board[ddy][sc]) {
	//	cnt++;
	//	flag = 1;
	//}
//	if (cnt == 1 && flag == 0) { // 상이 비었으면 밑으로 가자
		int ridx = sr;
		while (1) {
			//if (!board[ridx][sc]) break;
			ridx++;
			if (ridx > 7) break;
			if (!board[ridx][sc]) break;
			if (board[ridx][sc] == board[sr][sc]) {
				for (int r = sr; r <= ridx; r++) {
					board[r][sc] = board[sr][sc];
				}
				break;
			}
		}
	//}	
	//if (cnt == 1 && flag == 1) {
		ridx = sr;
		while (1) {
			//if (!board[ridx][sc]) break;
			ridx--;
			if (ridx < 0) break;
			if (!board[ridx][sc]) break;
			if (board[ridx][sc] == board[sr][sc]) {
				for (int r = sr; r >= ridx; r--) {
					board[r][sc] = board[sr][sc];
				}
				break;
			}
		}
	//}
}
void checkLR(int sr, int sc) {
	// 좌우
	int cnt = 0;
	int flag = 0;
	int dl = sc - 1;
	int dr = sc +  1;
	//if (dl < 0 || !board[sr][dl]) {
	//	cnt++;
	//	flag = 0;
	//}
	//if (dr > 7 || !board[sr][dr]) {
	//	cnt++;
	//	flag = 1;
	//}
	//if (cnt == 1 && flag == 0) { // 왼이 비었으면 오른쪽
		int cidx = sc;
		while (1) {
			//if (!board[ridx][sc]) break;
			cidx++;
			if (cidx > 7) break;
			if (!board[sr][cidx]) break;
			if (board[sr][cidx] == board[sr][sc]) {
				for (int c = sc; c <= cidx; c++) {
					board[sr][c] = board[sr][sc];
				}
				break;
			}
		}
//	}
	//if (cnt == 1 && flag == 1) {
		cidx = sc;
		while (1) {
			//if (!board[ridx][sc]) break;
			cidx--;
			if (cidx < 0) break;
			if (!board[sr][cidx]) break;
			if (board[sr][cidx] == board[sr][sc]) {
				for (int c = sc; c >= cidx; c--) {
					board[sr][c] = board[sr][sc];
				}
				break;
			}
		}
	//}
}
void checkLCRC(int sr, int sc) {
	int cnt = 0;
	int flag = 0;
	//if ((sr-1 < 0 || sc-1<0)|| !board[sr-1][sc-1]) {
	//	cnt++;
	//	flag = 0;
	//}
	//if ((sr+1 > 7 || sc+1 > 7 )|| !board[sr+1][sc+1]) {
	//	cnt++;
	//	flag = 1;
	//}
	//if (cnt == 1 && flag == 0) { //아래대각선으로
		int ridx = sr;
		int cidx = sc;
		while (1) {
			//if (!board[ridx][sc]) break;
			ridx++;
			cidx++;
			if (ridx > 7) break;
			if (cidx > 7) break;
			if (!board[ridx][cidx]) break;
			if (board[ridx][cidx] == board[sr][sc]) {
				int r = sr;
				for (int c = sc; c <= cidx; c++) {
					board[r++][c] = board[sr][sc];
				}
				break;
			}
		}
	//}
	//if (cnt == 1 && flag == 1) {
		ridx = sr;
		cidx = sc;
		while (1) {
			ridx--;
			cidx--;
			if (ridx < 0) break;
			if (cidx < 0) break;
			if (!board[ridx][cidx]) break;
			if (board[ridx][cidx] == board[sr][sc]) {
				int r = sr;
				for (int c = sc; c >= cidx; c--) {
					board[r--][c] = board[sr][sc];
				}
				break;
			}
		}
	//}
}
void checkRCLC(int sr, int sc) {
	int cnt = 0;
	int flag = 0;
	/*if (sr-1 < 0 || sc+1 > 7 || !board[sr-1][sc+1]) {
		cnt++;
		flag = 1;
	}
	if (sr + 1 >7 || sc - 1 < 0 || !board[sr +1][sc - 1]) {
		cnt++;
		flag = 0;
	}*/
	//if (cnt == 1 && flag == 1) { //왼대각밑으로
		int ridx = sr;
		int cidx = sc;
		while (1) {
			//if (!board[ridx][sc]) break;
			ridx++;
			cidx--;
			if (ridx > 7) break;
			if (cidx < 0) break;
			if (!board[ridx][cidx]) break;
			if (board[ridx][cidx] == board[sr][sc]) {
				int r = sr;
				for (int c = sc; c >= cidx; c--) {
					board[r++][c] = board[sr][sc];
				}
				break;
			}
		}
	//}
	//if (cnt == 1 && flag == 0) {
		cidx = sc;
		ridx = sr;
		while (1) {
			ridx--;
			cidx++;
			if (ridx < 0) break;
			if (cidx > 7) break;
			if (!board[ridx][cidx]) break;
			if (board[ridx][cidx] == board[sr][sc]) {
				int r = sr;
				for (int c = sc; c <= cidx; c++) {
					board[r--][c] = board[sr][sc];
				}
				break;
			}
		}
//	}
}
void putdoll(int sr, int sc, int color) {
	if (color % 2) board[sr][sc] = 1;
	else board[sr][sc] = 2;
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			checkUD(sr,sc);
		}
		else if (i == 1) {
			checkLR(sr, sc);
		}
		else if (i == 2) {
			checkLCRC(sr, sc);
		}
		else if (i == 3) {
			checkRCLC(sr, sc);
		}
	}
}
void print() {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (board[r][c] == 1) cout << "O";
			else if(board[r][c] == 2) cout << "@";
			else cout << "_";
		}
		cout << '\n';
	}
	cout << '\n';
}
void solve() {
	for (int i = 0; i < N; i++) {
		//cout <<"# "<< i<<'\n';
		//print();
		putdoll(order[i].r, order[i].c, i);
		//print();
	}
	//cout << "after\n";
	print();
} 

int main(void) {
	freopen("whiteblackdol.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}