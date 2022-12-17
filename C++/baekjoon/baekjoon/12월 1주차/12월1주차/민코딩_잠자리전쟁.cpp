#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_NM (100)
struct GR {
	int r, c, power;
	int dis;
	int diridx;
	bool alive;
	vector<int> moving;
};
struct POS {
	int r, c;
};
POS D[] = { {0,1},{1,0},{0,-1}, {-1,0} };
GR groups[100+1];
int maps[100 + 1][100 + 1];
int N, M, T;
void input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= T; i++) {
		int y, x, power, dist; cin >> y >> x >> power >> dist;
		vector<int> a;
		for (int idx = 0; idx < 4; idx++) {
			for (int c = 0; c < dist-1; c++) {
				a.push_back(idx);
			}
		groups[i] = { y,x,power,dist,-1,1, a};
		}
		maps[y][x] = i;
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << ":";
			cout << groups[maps[r][c]].power <<	"	";
		}
		cout << '\n';
	}
	cout << '\n';

}
void moving(int gidx,int time) {
	GR data = groups[gidx];
	if (data.moving.empty()) {
		groups[gidx].power++;
		return;
	}
	int diridx = (data.diridx+1)% (data.moving.size());
	int dir = (data.moving[diridx]);
	maps[data.r][data.c] = 0;
	if (time && !diridx) {
		data.power++;
	}
	data.r += D[dir].r;
	data.c += D[dir].c;
	groups[gidx].r = data.r;
	groups[gidx].c = data.c;
	groups[gidx].diridx = diridx;
	groups[gidx].power = data.power;
}
void mapupdate(int gidx) {
	GR data = groups[gidx];

	if (!maps[data.r][data.c]) {
		maps[data.r][data.c] = gidx;
	}
	else if (maps[data.r][data.c]) {
		int rival = maps[data.r][data.c];
		GR rivaldata = groups[rival];
		if (rivaldata.power < data.power) {
			data.power += rivaldata.power;
			maps[data.r][data.c] = gidx;
			groups[rival].alive = false;
			groups[gidx] = data;
		}
		else if (rivaldata.power > data.power) {
			rivaldata.power += data.power;
			maps[data.r][data.c] = rival;
			groups[rival] = rivaldata;
			groups[gidx].alive = false;
		}
		else if (rivaldata.power == data.power) {
			if (rivaldata.dis > data.dis) {
				rivaldata.power += data.power;
				maps[data.r][data.c] = rival;
				groups[rival] = rivaldata;
				groups[gidx].alive = false;
			}
			else if(rivaldata.dis < data.dis) {
				data.power += rivaldata.power;
				maps[data.r][data.c] = gidx;
				groups[rival].alive = false;
				groups[gidx] = data;
			}
			else {
				maps[data.r][data.c] = 0;
				groups[gidx].alive = false;
				groups[rival].alive = false;
			}
		}
	}
}
int findmax(){
	
	int maxxpower=0;
	int flag = 0;
	for (int i = 1; i <= T; i++) {
		if (!groups[i].alive) continue;
		if (maxxpower < groups[i].power) maxxpower = groups[i].power;
		flag = 1;
	}
	if (!flag) return 0;
	return maxxpower;
}
void solve() {
	for (int time = 0; time <= 14; time++) {
		//움직임
		for (int i = 1; i <= T; i++) {
			if (!groups[i].alive) continue;
			moving(i, time);
		}
		//맵최신화
		fill(&maps[0][0], &maps[100][100+1], 0);
		for (int i = 1; i <= T; i++) {
			if (!groups[i].alive) continue;
			 mapupdate(i);
		}

	}
	cout << findmax() << '\n';
}
int main(void) {
	freopen("jamjariwar.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}