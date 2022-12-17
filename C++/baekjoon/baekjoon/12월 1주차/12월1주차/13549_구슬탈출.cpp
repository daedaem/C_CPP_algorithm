#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_NM (10)

struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
POS blue, red;
char printmaps[MAX_NM + 2][MAX_NM + 2];
char maps[MAX_NM + 2][MAX_NM + 2];
int ER, EC, R, C;
queue<ST> q;
void init() {

}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'B') {
				blue.r = r;
				blue.c = c;
			}
			else if (maps[r][c] == 'R') {
				red.r = r;
				red.c = c;
			}
			else if (maps[r][c] == 'O') {
				ER = r;
				EC = c;
			}
		}
	}
}
void print() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}

void solve() {
}
int main(void) {
	freopen("escapegoosle.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();
	input();
	solve();
	return 0;
}
#endif

#if 1 //DFS Ǯ�� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NM (10)

struct POS {
	int r, c;
};
int comb[11];
POS blue, red;
char printmaps[MAX_NM + 2][MAX_NM + 2];
char maps[MAX_NM + 2][MAX_NM + 2];
int ER, EC, R, C;
void init() {

	
}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'B') {
				blue.r = r;
				blue.c = c;
			}
			else if (maps[r][c] == 'R') {
				red.r = r;
				red.c = c;
			}
			else if (maps[r][c] == 'O') {
				ER = r;
				EC = c;
			}
		}
	}
}
void print() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	//cout << '\n';
}
int blueup(int bluer, int bluec, int redr, int redc) {
	int bsr = bluer;
	while (1) {
		if (bsr < 1 || maps[bsr][bluec] == '#' || maps[bsr][bluec] == 'R') {
			bsr += 1;
			blue.r = bsr;
			maps[bsr][bluec] = 'B';
			break;
		}
		if (bsr == ER && bluec == EC) {
			blue.r = bsr;

			return 1;
		}
		bsr--;
	}
	return 0;
}
int bluedown(int bluer, int bluec, int redr, int redc) {
	int bsr = bluer;
	while (1) {
		if (bsr > R || maps[bsr][bluec] == '#' || maps[bsr][bluec] == 'R') {
			bsr -= 1;
			blue.r = bsr;
			maps[bsr][bluec] = 'B';
			break;
		}
		if (bsr == ER && bluec == EC) {
			blue.r = bsr;

			return 1;
		}
		bsr++;
	}
	return 0;
}
int blueleft(int bluer, int bluec, int redr, int redc) {
	int bsc = bluec;
	while (1) {
		if (bsc < 0 || maps[bluer][bsc] == '#' || maps[bluer][bsc] == 'R') {
			bsc += 1;
			blue.c = bsc;
			maps[bluer][bsc] = 'B';
			break;
		}
		if (bluer == ER && bsc == EC) {
			blue.c = bsc;

			return 1;
		}
		bsc--;
	}
	return 0;
}
int blueright(int bluer, int bluec, int redr, int redc) {
	int bsc = bluec;
	while (1) {
		if (bsc > C || maps[bluer][bsc] == '#' || maps[bluer][bsc] == 'R') {
			bsc -= 1;
			blue.c = bsc;
			maps[bluer][bsc] = 'B';
			break;
		}
		if (bluer == ER && bsc == EC) {
			blue.c = bsc;

			return 1;
		}
		bsc++;
	}
	return 0;
}
int redup(int bluer, int bluec, int redr, int redc) {
	int rsr = redr;
	while (1) {
		if (rsr < 1 || maps[rsr][redc] == '#' || maps[rsr][redc] == 'B') {
			rsr += 1;
			red.r = rsr;
			maps[rsr][redc] = 'R';
			break;
		}
		if (rsr == ER && redc == EC) {
			red.r = rsr;

			return 1;
		}
		rsr--;
	}
	return 0;
}
int reddown(int bluer, int bluec, int redr, int redc) {
	int rsr = redr;
	while (1) {
		if (rsr > R || maps[rsr][redc] == '#' || maps[rsr][redc] == 'B') {
			rsr -= 1;
			red.r = rsr;
			maps[rsr][redc] = 'R';
			break;
		}
		if (rsr == ER && redc == EC) {
			red.r = rsr;

			return 1;
		}
		rsr++;
	}
	return 0;
}
int redleft(int bluer, int bluec, int redr, int redc) {
	int rsc = redc;
	while (1) {
		if (rsc < 0 || maps[redr][rsc] == '#' || maps[redr][rsc] == 'B') {
			rsc += 1;
			red.c = rsc;
			maps[redr][rsc] = 'R';
			break;
		}
		if (redr == ER && rsc == EC) {
			red.c = rsc;

			return 1;
		}
		rsc--;
	}
	return 0;
}
int redright(int bluer, int bluec, int redr, int redc) {
	int rsc = redc;
	while (1) {
		if (rsc > C || maps[redr][rsc] == '#' || maps[redr][rsc] == 'B') {
			rsc -= 1;
			red.c = rsc;
			maps[redr][rsc] = 'R';
			break;
		}
		if (redr == ER && rsc == EC) {
			red.c = rsc;
			return 1;
		}
		rsc++;
	}
	return 0;
}
int flag = 0;
void DFS(int dep) {
	if (dep == 10) {
		//for (int i = 0; i < dep; i++) {
		//	if (comb[i] == 0) cout << 'U' << " ";
		//	else if (comb[i] == 1) cout << 'D' << " ";
		//	else if (comb[i] == 2) cout << 'L' << " ";
		//	else if (comb[i] == 3) cout << 'R' << " ";
		//}
		//cout << '\n';
		//cout << '\n';
		return;
	}
	int backup[MAX_NM + 2][MAX_NM + 2];
	copy(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], &backup[0][0]);
	
	int bluer = blue.r;
	int bluec = blue.c;
	int redr = red.r;
	int redc = red.c;
	int retr, retb;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			maps[blue.r][blue.c] = '.';
			maps[red.r][red.c] = '.';
			if (red.r < blue.r) {
				retr=redup(blue.r, blue.c, red.r, red.c);
				retb=blueup(blue.r, blue.c, red.r, red.c);
			}
			else if (red.r >= blue.r) {
				retb = blueup(blue.r, blue.c, red.r, red.c);
				retr = redup(blue.r, blue.c, red.r, red.c);
			}
			//print();
			//comb[dep] = i;
			if (retr && !retb) {
				flag = 1;
				return;
			}
			else if (!retb) {
				DFS(dep + 1);
			}
			//comb[dep]=0;
			blue.r = bluer;
			blue.c = bluec;
			red.r = redr;
			red.c = redc;
			copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &maps[0][0]);
		}
		else if (i == 1) {
			maps[blue.r][blue.c] = '.';
			maps[red.r][red.c] = '.';
			if (red.r > blue.r) {
				retr = reddown(blue.r, blue.c, red.r, red.c);
				retb = bluedown(blue.r, blue.c, red.r, red.c);
			}
			else if (red.r <= blue.r) {
				retb = bluedown(blue.r, blue.c, red.r, red.c);
				retr = reddown(blue.r, blue.c, red.r, red.c);
			}
			//cout << "#" << dep << '\n';
			//print();
			//comb[dep]=i;
			if (retr && !retb) {
				flag = 1;
				return;
			}
			else if (!retb) {
				DFS(dep + 1);
			}
			//comb[dep]=0;
			blue.r = bluer;
			blue.c = bluec;
			red.r = redr;
			red.c = redc;
			copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &maps[0][0]);
		}
		else if (i == 2) {
			maps[blue.r][blue.c] = '.';
			maps[red.r][red.c] = '.';
			if (red.c < blue.c) {
				retr = redleft(blue.r, blue.c, red.r, red.c);
				retb = blueleft(blue.r, blue.c, red.r, red.c);
			}
			else if (red.c >= blue.c) {
				retb = blueleft(blue.r, blue.c, red.r, red.c);
				retr = redleft(blue.r, blue.c, red.r, red.c);
			}
			///*cout << "#" << dep << '\n';*/
			//print();
			//comb[dep]=i;
			if (retr && !retb) {
				flag = 1;
				return;
			}
			else if (!retb) {
				DFS(dep + 1);
			}
			//comb[dep]=0;
			blue.r = bluer;
			blue.c = bluec;
			red.r = redr;
			red.c = redc;
			copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &maps[0][0]);
		}
		else if (i == 3) {
			maps[blue.r][blue.c] = '.';
			maps[red.r][red.c] = '.';
			if (red.c < blue.c) {
				retb = blueright(blue.r, blue.c, red.r, red.c);
				retr = redright(blue.r, blue.c, red.r, red.c);
			}
			else if (red.c >= blue.c) {
				retr = redright(blue.r, blue.c, red.r, red.c);
				retb = blueright(blue.r, blue.c, red.r, red.c);
			}
			//cout << "#" << dep << '\n';
			//print();
			//comb[dep]=i;
			if (retr && !retb) {
				flag = 1;
				return;
			}
			else if (!retb) {
				DFS(dep + 1);
			}
			//comb[dep]=0;
			blue.r = bluer;
			blue.c = bluec;
			red.r = redr;
			red.c = redc;
			copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &maps[0][0]);
		}
	}
	return ;
}

void solve() {
	DFS(0);
	if (flag) cout << 1 << '\n';
	else cout << 0 << '\n';
	//print();
}
int main(void) {
	freopen("escapegoosle.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();
	input();
	solve();
	return 0;
}
#endif