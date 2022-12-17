#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX_RC (4)
struct POS {
	int r, c;
};
struct HR {
	int idx, r, c, dir;
	bool alive;
};
HR horse[17];
struct ME{
	int r, c, dir;
	int score;
}me;
POS DIR[9] = { {0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
int maps[MAX_RC + 1][MAX_RC + 1];
int maxscore;
void init() {
	for (int i = 0; i < 17; i++) {
		horse[i] = {};
	}
	memset(maps, 0, sizeof(maps));
	maxscore = 0;
}
void input() {
	for (int r = 0; r < MAX_RC; r++) {
		for (int c = 0; c < MAX_RC; c++) {
			int p, d; cin >> p >> d;
			horse[p] = { p, r, c, d, true };
			maps[r][c] = p;
		}
	}
}
void print() {
	for (int r = 0; r < MAX_RC; r++) {
		for (int c = 0; c < MAX_RC; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void soolaeinit() {
	me.r = 0;
	me.c = 0;
	int hidx = maps[0][0];
	me.dir = horse[hidx].dir;
	me.score += horse[hidx].idx;
	maps[0][0] = -1;
	horse[hidx].alive = false;
}
int check() {
	return 1;
}
void horsemove(int hidx) {
	int dir = horse[hidx].dir;
	int r = horse[hidx].r;
	int c = horse[hidx].c;
	int dy = r + DIR[dir].r;
	int dx = c + DIR[dir].c;
	// 격자안이고 술래가 있는 곳이아니라면
	if (dy >= 0 && dy <= 3 && dx >= 0 && dx <= 3 && maps[dy][dx] != -1) {
		int otheridx = maps[dy][dx];
		if (otheridx) {
			horse[otheridx].r = r;
			horse[otheridx].c = c;
		}
		horse[hidx].r = dy;
		horse[hidx].c = dx;
		swap(maps[r][c], maps[dy][dx]);
		return;
	}
	for (int idx = 1; idx < 8; idx++) {
		dir += 1;
		if (dir > 8) dir = 1;
		int dy = r + DIR[dir].r;
		int dx = c + DIR[dir].c;
		if (dy >= 0 && dy <= 3 && dx >= 0 && dx <= 3 && maps[dy][dx] != -1) {
			int otheridx = maps[dy][dx];
			if (otheridx) {
				horse[otheridx].r = r;
				horse[otheridx].c = c;
			}
			horse[hidx].r = dy;
			horse[hidx].c = dx;
			horse[hidx].dir = dir;
			swap(maps[r][c], maps[dy][dx]);
			return;
		}
	}
}
void movinghorse() {
	for (int i = 1; i <= 16; i++) {
		if (!horse[i].alive) continue;
		horsemove(i);
		//cout << "#" << i << " 이동\n";
		//print();
	}
}
int soolaemove(int step) {
	int dy = me.r + step * DIR[me.dir].r;
	int dx = me.c + step * DIR[me.dir].c;
	// 4방향 밖이면
	if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) {
		return 0;
	}
	// 해당 곳에 먹을 말 없으면
	if (!maps[dy][dx]) return 0;
	//먹을 말 인덱스
	int eatedidx = maps[dy][dx];
	// 죽음처리
	horse[eatedidx].alive = false;
	// 원래자리 비우기
	maps[me.r][me.c] = 0;
	me.r = dy;
	me.c = dx;
	me.score += eatedidx;
	me.dir =  horse[eatedidx].dir;
	maps[dy][dx] = -1;
	return 1;
}
void makecombi() {
	if (maxscore < me.score) maxscore = me.score;
	//print();
	//cout << me.score << '\n';
	// 갈때없으면 maxscore랑 비교
	/*if (check()) {  ===========================켜기
		if (maxscore < me.r) maxscore = me.r;
		return;
	}*/
	//맵 정보 백업
	movinghorse();
	int backupmaps[MAX_RC + 1][MAX_RC + 1];
	copy(&maps[0][0], &maps[MAX_RC][MAX_RC + 1], &backupmaps[0][0]);
	//술래정보 백업
	ME mebackup = me;
	// 말정보 백업
	HR horsebackup[17];
	for (int i = 1; i <= 16; i++) {
		horsebackup[i] = horse[i];
	}
	int ret = soolaemove(1);
	if (ret) {
		makecombi();
		me = mebackup;
		copy(&backupmaps[0][0], &backupmaps[MAX_RC][MAX_RC + 1], &maps[0][0]);
		for (int i = 1; i <= 16; i++) {
			horse[i] = horsebackup[i];
		}
	}
	ret = soolaemove(2);
	if (ret) {
		makecombi();
		me = mebackup;
		copy(&backupmaps[0][0], &backupmaps[MAX_RC][MAX_RC + 1], &maps[0][0]);
		for (int i = 1; i <= 16; i++) {
			horse[i] = horsebackup[i];
		}

	}
	ret = soolaemove(3);
	if (ret) {
		makecombi();
		me = mebackup;
		copy(&backupmaps[0][0], &backupmaps[MAX_RC][MAX_RC + 1], &maps[0][0]);
		for (int i = 1; i <= 16; i++) {
			horse[i] = horsebackup[i];
		}
	}
	return;
	//for (int step = 1; step <= 3; step++) {
	//	int ret = 
	//	if (ret) {
	//		makecombi();
	//		//되돌리기
	//		
	//	}
	//}
}
void solve() {
	//print();
	// 술래말 초기 0,0 먹기
	soolaeinit();
	//print();
	makecombi();
	//maps[r][c]
}
int main(void) {
	freopen("soolaejabgi_chess.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << maxscore << '\n';
	}
	return 0;
}