#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// 묵 1   찌 2    빠 3
// 프     오      스
using namespace std;
#define MAX_R (10)
#define MAX_C (6)
struct M {
	vector<int> v;
};
struct POS {
	int r, c;
};
struct ST {
	int r, c, type;
};

POS D[][4] = { 
	{{},{},{}, {}},
	{{-1,0},{0,1},{1,0},{0,-1}},
	{{-1,0},{1,0},{1,1},{0,-1}},
	{{-1,1},{1,1},{1,-1},{-1,-1}},
};
M maps[MAX_R + 2][MAX_C + 2];
int omap[MAX_R + 2][MAX_C + 2];
int SR1, SC1, SR2, SC2, SR3, SC3;
int finish[MAX_R + 2][MAX_C + 2];
int visit[4][MAX_R + 2][MAX_C + 2];
queue<ST> q;
queue<ST> oq;
void input() {
	for (int r = 0; r < MAX_R; r++) {
		for (int c = 0; c < MAX_C; c++) {
			cin >> omap[r][c];
			if (omap[r][c] == 1) {
				SR1 = r;
				SC1 = c;
			}
			else if (omap[r][c] == 2) {
				SR2 = r;
				SC2 = c;
			}
			else if (omap[r][c] == 3) {
				SR3 = r;
				SC3 = c;
			}
		}
	}
}
void mapupdate() {
	for (int r = 0; r < MAX_R; r++) {
		for (int c = 0; c < MAX_C; c++) {
			//// 중복제거방법
			//// 정렬하고
			////유니크한 부분 지워나가는 식
			//sort(maps[r][c].v.begin(), maps[r][c].v.end());
			//maps[r][c].v.erase(unique(maps[r][c].v.begin(), maps[r][c].v.end()), maps[r][c].v.end());
			if (maps[r][c].v.size() == 1) {
				oq.push({ r,c, maps[r][c].v[0] });
				finish[r][c] = maps[r][c].v[0];
			}
			else if (maps[r][c].v.size() == 3) {
				maps[r][c].v.clear();
				maps[r][c].v.push_back(4);
				finish[r][c] = 4;
			}
			else if (maps[r][c].v.size() == 2) {
				if (maps[r][c].v[0] + maps[r][c].v[1] == 3) {
					maps[r][c].v.clear();
					maps[r][c].v.push_back(1);
					oq.push({ r,c,1 });
					finish[r][c] = 1;
				}
				else if (maps[r][c].v[0] + maps[r][c].v[1] == 5) {
					maps[r][c].v.clear();
					maps[r][c].v.push_back(2);
					oq.push({ r,c,2 });
					finish[r][c] = 2;

				}
				else if (maps[r][c].v[0] + maps[r][c].v[1] == 4) {
					maps[r][c].v.clear();
					maps[r][c].v.push_back(3);
					oq.push({ r,c,3});
					finish[r][c] = 3;
				}
			}
		}
	}
}
void print() {
	for(int r=0;r<MAX_R;r++){
		for (int c = 0; c < MAX_C; c++) {
			cout << finish[r][c] << " ";
			/*if (maps[r][c].v.empty()) cout << 0 << " ";
			else cout << maps[r][c].v[0] << " ";*/
		} 
		cout << '\n';
	}
	cout << '\n';
}
void solve() {
	q = {};
	oq = {};
	oq.push({SR1, SC1, 1});
	oq.push({ SR2, SC2, 2 });
	oq.push({ SR3, SC3, 3 });
	finish[SR1][SC1] = 1;
	finish[SR2][SC2] = 2;
	finish[SR3][SC3] = 3;
	visit[1][SR1][SC1] = 1;
	visit[2][SR2][SC2] = 2;
	visit[3][SR3][SC3] = 3;
	for (int time = 0; time <= 6; time++) {
		while(!oq.empty()){
			q.push(oq.front());
			oq.pop();
		}
		oq = {};
		while (!q.empty()) {
			fill(&visit[0][0][0] , &visit[3][MAX_R + 1][MAX_C + 1], 0);
			ST data = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				ST newdata = data;
				newdata.r += D[newdata.type][i].r;
				newdata.c += D[newdata.type][i].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= MAX_R || newdata.c >= MAX_C) continue;
				if (visit[newdata.type][newdata.r][newdata.c]) continue;
				if (finish[newdata.r][newdata.c]==4) continue;
				if (find(maps[newdata.r][newdata.c].v.begin(), maps[newdata.r][newdata.c].v.end(), newdata.type) == maps[newdata.r][newdata.c].v.end()) {
					maps[newdata.r][newdata.c].v.push_back(newdata.type);
				}
//				maps[newdata.r][newdata.c].v.push_back(newdata.type);
				visit[newdata.type][newdata.r][newdata.c] = newdata.type;
			}
		}		
		mapupdate();
	}

}
int main(void) {
	freopen("min_italywar.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	print();


	return 0;
}