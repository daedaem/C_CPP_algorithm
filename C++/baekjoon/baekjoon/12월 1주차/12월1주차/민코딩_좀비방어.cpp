#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX_K (20)
#define MAX_N (5)

map<char, int> dirs = { {'U',0}, {'R',1}, {'D' , 2}, {'L', 3 } };
char maps[MAX_N+2][MAX_N+2];
int zmaps[MAX_N + 2][MAX_N + 2];
struct ZB{
	int r, c, dir;
	int life;
	int alive;
};
struct POS {
	int r, c, power=50;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<POS>towers;
ZB zombies[MAX_K + 1];
int K;
int ER, EC;
void input() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == '#') {
				towers.push_back({ r,c });
			}
			if (maps[r][c] == '@') {
				ER = r;
				EC = c;
			}
		}
	}
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> zombies[i].life;
	}
}
void makezombie(int i) {
	zombies[i].r = 0;
	zombies[i].c = 0;
	zombies[i].dir = dirs[maps[0][0]];
	zombies[i].alive = 1;
	zmaps[0][0] = i;
}
int checkalldie() {
	for (int i = 1; i <= K; i++) {
		if (zombies[i].alive) return 0;
	}
	return 1;
}
void movezombie(int zidx) {
	zombies[zidx].r += D[zombies[zidx].dir].r;
	zombies[zidx].c += D[zombies[zidx].dir].c;
	zombies[zidx].dir = dirs[maps[zombies[zidx].r][zombies[zidx].c]];
	zmaps[zombies[zidx].r][zombies[zidx].c] = zidx;
}
int attack() {
	return 1;
}
void print() {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cout << zmaps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void mapupdate() {
	fill(&zmaps[0][0], &zmaps[MAX_N + 1][MAX_N + 2], 0);
	for (int i = 1; i <= K; i++) {
		if (zombies[i].alive) {
			zmaps[zombies[i].r][zombies[i].c] = i;
		}
	}
}
void attackTower() {
	for (int idx = 0; idx < towers.size(); idx++) {
		int r = towers[idx].r;
		int c = towers[idx].c;
		int power = towers[idx].power;
		for (int i = 0; i < 4; i++) {
			int dy = r + D[i].r;
			int dx = c + D[i].c;
			if (dy < 0 || dx < 0 || dy >= MAX_N || dx >= MAX_N) continue;
			if (zmaps[dy][dx]) {
				zombies[zmaps[dy][dx]].life -= power;
				if (zombies[zmaps[dy][dx]].life <= 0) {
					zombies[zmaps[dy][dx]].life = 0;
					zombies[zmaps[dy][dx]].alive = false;
					zmaps[dy][dx] = 0;
				}
			}
		}
	}
}
int arrived() {
	for (int i = 1; i <= K; i++){
		if (!zombies[i].alive) continue;
		if (zombies[i].r == ER && zombies[i].c == EC) return 1;
	}
	return 0;
}
int solve() {
	for (int time = 1; ; time++) {
		if (time <= K) {
			makezombie(time);
		}
		for (int i = 1; i <= K; i++) {
			if (i >= time) continue;
			if (!zombies[i].alive) continue;
			movezombie(i);
		}
		mapupdate();
		attackTower();
		if(checkalldie()) return time;
		int ret = arrived();
		if (ret) return -1;
	}
	return 1;
}
int main(){
	freopen("zombiedefense.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	int ret = solve();
	if (ret == -1) cout << "Game Over\n";
	else cout << ret << '\n';
	return 0;
}