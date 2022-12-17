#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX_Z (624)
#define MAX_N (25)
#define WALL (-1)
struct POS {
	int r, c;
};
struct ZB {
	int r, c, dir, speed, type;
};
POS player;
POS DIR[] = { {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1} };
int revd[] = {0, 3,4,1,2 };
vector<int> order;
vector<ZB> zombies;
int N, W, Z, D;
int maps[MAX_N + 2][MAX_N + 2];
int zmaps[MAX_N + 2][MAX_N + 2];
void init() {
	order.clear();
	player = { 0,0 };
	fill(&maps[0][0], &maps[MAX_N + 1][MAX_N + 2], 0);
}
void input() {
	cin >> N;
	string o; cin >> o;
	for (int i = 0; i < o.size(); i++) {
		if (o[i] == 'S') order.push_back(0);
		else if (o[i] == 'U') order.push_back(1);
		else if (o[i] == 'R') order.push_back(2);
		else if (o[i] == 'D') order.push_back(3);
		else if (o[i] == 'L') order.push_back(4);
	}
	cin >> player.r >> player.c;
	cin >> W;
	for (int i = 0; i < W; i++) {
		int y, x; cin >> y >> x;
		maps[y][x] = WALL; //º®
	}
	cin >> Z;
	zombies.resize(Z);
	for (int i = 0; i < Z; i++){
		char dir;
		cin >> zombies[i].r >> zombies[i].c >> zombies[i].type >> dir >> zombies[i].speed;
		if (dir == 'U') zombies[i].dir = 1;
		else if (dir == 'R') zombies[i].dir = 2;
		else if (dir == 'D') zombies[i].dir = 3;
		else if (dir == 'L') zombies[i].dir = 4;
	}
	cin >> D;
}
void playermove(int diridx) {
	int dy = player.r + DIR[diridx].r;
	int dx = player.c + DIR[diridx].c;
	if (dy<1 || dx<1 || dy>N || dx>N) return;
	if (maps[dy][dx] == WALL) return;
	player.r = dy;
	player.c = dx;
}
int underZombiMove(int zidx) {
	ZB data = zombies[zidx];
	for(int i=1; i<=data.speed; i++){
		int dy = data.r + DIR[data.dir].r;
		int dx = data.c + DIR[data.dir].c;
		if (maps[dy][dx] == WALL) {
			data.dir = revd[data.dir];
			break;
		}
		else if (dy<1 || dx<1 || dy>N || dx>N) {
			data.dir = revd[data.dir];
			break;
		}
		data.r = dy;
		data.c = dx;
	}
	zombies[zidx] = data;
	if (data.r == player.r && data.c == player.c) return 1;
	return 0;
}
int checkwall(ZB data) {
	int maxxwallcnt = 0;
	int maxdir = 1;
	for (int i = 1; i <= 4; i++) {
		int cnt = 0;
		int dy = data.r;
		int dx = data.c;
		while (1) {
			dy += DIR[i].r;
			dx += DIR[i].c;
			if (maps[dy][dx] == WALL) cnt++;
			if (dy<1 || dx<1 || dy>N || dx>N) break;
		}
		if (maxxwallcnt < cnt) {
			maxdir = i;
			maxxwallcnt = cnt;
		}
	}
	return maxdir;
}
int highZombiMove(int zidx){
	ZB data = zombies[zidx];
	for (int i = 1; i <= data.speed; i++) {
		int dy = data.r + DIR[data.dir].r;
		int dx = data.c + DIR[data.dir].c;
		if (maps[dy][dx] == WALL) {
			maps[dy][dx] = 0;
			break;
		}
		else if (dy<1 || dx<1 || dy>N || dx>N) {
			break;
		}
		data.r = dy;
		data.c = dx;
	}
	data.dir = checkwall(data);

	zombies[zidx] = data;
	if (data.r == player.r && data.c == player.c) return 1;
	return 0;
}
void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << zmaps[r][c] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void updatemap() {
	for (int i = 0; i < Z; i++) {
		zmaps[zombies[i].r][zombies[i].c] = 2;
	}
	zmaps[player.r][player.c] = 1;
}
int solve() {
	int oidx = 0;
	for (int time = 1; time <= D; time++) {
		fill(&zmaps[0][0], &zmaps[MAX_N + 1][MAX_N + 2],0);
		if (oidx < order.size()) {
			playermove(order[oidx]);
		}
		for (int i = 0; i < Z; i++) {
			if (zombies[i].type) {
				int ret = highZombiMove(i);
				if (ret) return time;
			}
			else {
				int ret = underZombiMove(i);
				if (ret) return time;
			}
		}
		oidx++;
		updatemap();
		//print();
	}
	return 0;
}
int main(void) {
	freopen("aliveordead.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	int ret = solve();
	if (ret) cout <<ret<<'\n'<< "DEAD...\n";
	else cout << "ALIVE!\n";
	return 0;
}
#endif


#if 0
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
#define MAX_Z (624)
#define MAX_N (25)

struct POS {
	int r, c;
};
struct ZOM {
	int r, c, dir, types, speed;
};

POS pos[] = { {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1} };
int revD[] = { 0,3,4,1,2 };
char maps[MAX_N + 2][MAX_N + 2];
POS me;
ZOM zombies[MAX_Z + 1];
vector<int> meorder;
int N, W, Z, D;
void init() {
	meorder.clear();
	fill(&maps[1][1], &maps[MAX_N + 1][MAX_N + 2], '.');
	for (int i = 0; i < MAX_Z + 1; i++) {
		zombies[i] = { 0,0,0,0,0 };
	}
}
void input() {
	cin >> N;
	string A; cin >> A;
	for (int i = 0; i < A.size(); i++) {
		char cc = A[i];
		if (cc == 'S') meorder.push_back(0);
		else if (cc == 'U') meorder.push_back(1);
		else if (cc == 'R') meorder.push_back(2);
		else if (cc == 'D') meorder.push_back(3);
		else if (cc == 'L') meorder.push_back(4);
	}
	cin >> me.r >> me.c;
	maps[me.r][me.c] = 'M';
	cin >> W;
	for (int i = 0; i < W; i++) {
		int r, c; cin >> r >> c;
		maps[r][c] = '#';
	}
	cin >> Z;
	for (int i = 0; i < Z; i++) {
		char dirs;
		cin >> zombies[i].r >> zombies[i].c >> zombies[i].types >> dirs >> zombies[i].speed;
		maps[zombies[i].r][zombies[i].c] = '@';
		if (dirs == 'S') zombies[i].dir = 0;
		else if (dirs == 'U') zombies[i].dir = 1;
		else if (dirs == 'R') zombies[i].dir = 2;
		else if (dirs == 'D') zombies[i].dir = 3;
		else if (dirs == 'L') zombies[i].dir = 4;
	}
	cin >> D;
}
void moveme(int diridx) {
	int dy = me.r + pos[diridx].r;
	int dx = me.c + pos[diridx].c;
	if (dy >= 1 && dx >= 1 && dx <= N && dy <= N) {
		maps[me.r][me.c] = '.';
		me.r = dy;
		me.c = dx;
		maps[me.r][me.c] = 'M';
	}
}
int undzombiemove(int zidx) {
	if (maps[zombies[zidx].r][zombies[zidx].c] == 'Z') {
		maps[zombies[zidx].r][zombies[zidx].c] = '.';
	}
	int dy = zombies[zidx].r;
	int dx = zombies[zidx].c;
	for (int i = 1; i <= zombies[zidx].speed; i++) {
		dy += pos[zombies[zidx].dir].r;
		dx += pos[zombies[zidx].dir].c;
		if (dy<1 || dx<1 || dx>N || dy>N || maps[dy][dx] == '#') {
			zombies[zidx].dir = revD[zombies[zidx].dir];
			return 1;
		}
		if (dy == me.r && dx == me.c) return 0;
		zombies[zidx].r = dy;
		zombies[zidx].c = dx;
	}
	return 1;
}
int checkdirect(int sr, int sc, int diridx) {
	int r = sr;
	int c = sc;
	int cnt = 0;
	if (diridx == 1) {
		while (r >= 0) {
			if (maps[r][sc] == '#') cnt++;
			r--;
		}
	}
	else if (diridx == 2) {
		while (c <= N) {
			if (maps[sr][c] == '#') cnt++;
			c++;
		}
	}
	else if (diridx == 3) {
		while (r <= N) {
			if (maps[r][sc] == '#') cnt++;
			r++;
		}
	}
	else if (diridx == 4) {
		while (c >= 0) {
			if (maps[sr][c] == '#') cnt++;
			c--;
		}
	}
	return cnt;
}
void highzombiemove(int zidx) {
	if (maps[zombies[zidx].r][zombies[zidx].c] == 'Z') {
		maps[zombies[zidx].r][zombies[zidx].c] = '.';
	}
	int dy = zombies[zidx].r;
	int dx = zombies[zidx].c;
	for (int i = 1; i <= zombies[zidx].speed; i++) {
		dy += pos[zombies[zidx].dir].r;
		dx += pos[zombies[zidx].dir].c;
		if (dy<1 || dx<1 || dy>N || dx>N) break;
		if (maps[dy][dx] == '#') {
			maps[dy][dx] = '.';
			break;
		}
		zombies[zidx].r = dy;
		zombies[zidx].c = dx;
	}
	int maxx = 0;
	for (int i = 1; i <= 4; i++) {
		int ret = checkdirect(zombies[zidx].r, zombies[zidx].c, i);
		if (ret > maxx) {
			maxx = ret;
			zombies[zidx].dir = i;
		}
	}
	return;
}
void movezombie() {
	for (int i = 0; i < Z; i++) {
		if (zombies[i].types) {
			undzombiemove(i);
		}
		else highzombiemove(i);
	}
}
void solve() {
	int ordidx = 0;
	for (int i = 0; i < D; i++) {
		if (ordidx < meorder.size()) {
			moveme(meorder[ordidx++]);
		}
		movezombie();
	}
}
int main(void) {
	freopen("aliveordead.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;
}
#endif
