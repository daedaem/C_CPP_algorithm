#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAXN (5)
struct POS {
	int r, c;
};
struct BG {
	int r, c, type, day, alive;
};
int days;
char maps[MAXN + 2][MAXN + 2];
int modum[MAXN + 2][MAXN + 2];
queue<BG> q;
BG bugs[25+1];
int idx = 0;
void input() {
	cin >> days;
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'A') {
				bugs[++idx] = { r,c,1,5,1};
			}
			else if (maps[r][c] == 'B') {
				bugs[++idx] = { r,c,2,6,1 };
			}
		}
	}
}
void print() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
void livedec(int bidx) {
	bugs[bidx].day--;
	if (bugs[bidx].day) return;

	bugs[bidx].alive = false;
	static POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
	int r = bugs[bidx].r;
	int c = bugs[bidx].c;
	modum[r][c] = 1;
	maps[r][c] = '_';
	for (int i = 0; i < 4; i++) {
		int dy = r + D[i].r;
		int dx = c + D[i].c;
		if (dy < 0 || dx < 0 || dy >= MAXN || dx >= MAXN) continue;
		if (modum[dy][dx]) continue;
		if (maps[dy][dx]=='B' || maps[dy][dx]=='A') continue;
		if (bugs[bidx].type == 1) {
			bugs[++idx] ={ dy,dx, 1, 5, 1 };
			maps[dy][dx] = 'A';
		}
		else if (bugs[bidx].type == 2) {
			bugs[++idx] = {dy,dx, 2, 6, 1};
			maps[dy][dx] = 'B';
		}
	}
	return;
}
void mapsupdate() {
	fill(&maps[0][0], &maps[6][7], '_');
	for (int i = 1; i <= 25; i++) {
		if (!bugs[i].alive) continue;
		maps[bugs[i].r][bugs[i].c] = bugs[i].type - 1 + 'A';
	}
}
void solve() {
	while (days--) {
		for(int i=1; i<=25;i++){
			if (!bugs[i].alive) continue;
			livedec(i);
		}
		mapsupdate();
	print();
	}

}
  int main(void) {
	freopen("drcoca.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char map[5][5];
int day;
int left_day[2] = { 1, 1 };
int limit_day[2] = { 5, 6 };
struct Node {
	int x, y;
};
queue<Node> A;
queue<Node> B;
void Input()
{
	cin >> day;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'A') A.push({ x, y });
			if (map[y][x] == 'B') B.push({ x, y });
		}
	}
}
void Incubate(queue<Node> &que, int date, char ch)
{
	int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
	queue<Node> next;
	while (que.empty() == false) {
		Node now = que.front();
		que.pop();
		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];
			if (dy < 0 || dx < 0 || dy >= 5 || dx >= 5) continue;
			if (map[dy][dx] != '_') continue;
			map[dy][dx] = ch;
			next.push({ dx, dy });
		}
		map[now.y][now.x] = 'D';
	}
	que = next;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	Input();
	for (int i = 2; i <= day; i++) {
		left_day[0]++;
		left_day[1]++;
		//A ¾Ë ³º±â
		if (left_day[0] == limit_day[0]) {
			left_day[0] = 1;
			Incubate(A, i, 'A');
		}
		//B ¾Ë ³º±â
		if (left_day[1] == limit_day[1]) {
			left_day[1] = 1;
			Incubate(B, i, 'B');
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (map[y][x] == 'D') cout << '_';
			else cout << map[y][x];
		}
		cout << endl;
	}
	return 0;
}
#endif