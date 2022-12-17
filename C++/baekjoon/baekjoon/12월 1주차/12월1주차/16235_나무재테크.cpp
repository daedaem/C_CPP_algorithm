#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N (10)
#define MAX_M (100)
struct TR {
	int idx;
	int r, c;
	int age;
};
struct POS {
	int r, c;
};
int N, M, K;
int nut[MAX_N + 2][MAX_N + 2];
int nownut[MAX_N + 2][MAX_N + 2];
vector<int> maps[MAX_N + 2][MAX_N + 2];
int totalcnt;
struct ST {
	int r, c, age;
};
vector<ST> newtree;
void init() {
	for (int r = 0; r < MAX_N + 2; r++) {
		for (int c = 0; c < MAX_N + 2; c++) {
			maps[r][c].clear();
		}
	}
	newtree.clear();
	fill(&nut[0][0], &nut[MAX_N + 1][MAX_N + 2], 0);
	fill(&nownut[0][0], &nownut[MAX_N + 1][MAX_N + 2], 0);
}
void input() {
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> nut[r][c];
			nownut[r][c] = 5;
		}
	}
	for (int i = 1; i <= M; i++) {
		int x, y, z; cin >> x >> y >> z;
		//trees.insert({ idx, {idx,x,y,z, true} });
		maps[x][y].push_back(z);
	}
}
void spring() {
	newtree.clear();
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (maps[r][c].empty()) continue;
			sort(maps[r][c].begin(), maps[r][c].end());
			int energy = 0;
			for (int i = 0; i < maps[r][c].size(); i++) {
				if (maps[r][c][i] <= nownut[r][c]) {
					nownut[r][c] -= maps[r][c][i];
					newtree.push_back({ r,c, maps[r][c][i] + 1 });
				}
				else {
					energy += (maps[r][c][i] / 2);
				}
			}
			nownut[r][c] += energy;
		}
	}
}
void summer() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			maps[r][c].clear();
		}
	}
	for (int i = 0; i < newtree.size(); i++) {
		ST data = newtree[i];
		maps[data.r][data.c].push_back(data.age);
	}
}
void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (maps[r][c].empty()) {
				cout << "-";
			}
			for (int i = 0; i < maps[r][c].size(); i++) {
				cout << maps[r][c][i] << ",";
			}
			cout << "		";
		}
		cout << '\n';
	}
	cout << '\n';
}
void fall() {
	static POS DIR[] = { {-1,-1},{-1,0},{-1,1},{0,-1}, {0,1},{1,-1},{1,0},{1,1} };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (maps[r][c].empty()) continue;
			int lens = maps[r][c].size();
			for (int i = 0; i < lens; i++) {
				int age = maps[r][c][i];
				if (age % 5 == 0) {
					for (int didx = 0; didx < 8; didx++) {
						int dy = r + DIR[didx].r;
						int dx = c + DIR[didx].c;
						if (dy<1 || dx<1 || dy>N || dx>N) continue;
						maps[dy][dx].push_back(1);
					}
				}
			}
		}
	}
}
void winter() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			nownut[r][c] += nut[r][c];
		}
	}
}
void solve() {
	for (int time = 1; time <= K; time++) {
		spring();
		summer();
		fall();
		winter();
	}
	totalcnt = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			totalcnt += maps[r][c].size();
		}
	}
	cout << totalcnt << '\n';
}
int main(void) {
	freopen("16235_tree.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();

	return 0;
}
#endif
#if 0 // 해결못함
#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <list> 
using namespace std;

#define MAX_N (10)

struct TR {
	int age;
	int cnt;
};
struct POS {
	int r, c;
};
int N, M, K;
int nownutr[MAX_N + 2][MAX_N + 2];
int willnutr[MAX_N + 2][MAX_N + 2];
//list <int> maps[MAX_N + 2][MAX_N + 2];
list <TR> maps[MAX_N + 2][MAX_N + 2];
int treecnt;
void init() {
	for(int r=1;r<=N;r++){
		for (int c = 1; c <= N; c++) {
			maps[r][c].clear();
		}
	}
	treecnt = 0;
}
void input() {
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> willnutr[r][c];
			nownutr[r][c] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z; cin >> x >> y >> z;
		maps[x][y].insert(maps[x][y].begin(), { z, 1 });
		treecnt++;
	}
}
void springsummer() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (maps[r][c].empty()) continue;
			auto it = maps[r][c].begin();
			int tempe = 0;
			while (it != maps[r][c].end()) {
				int itage = it->age;
				int itcnt = it->cnt;
				if (nownutr[r][c] >= (itage*itcnt)) {
					nownutr[r][c] -= (itage*itcnt);
					(it->age)++;
					it++;
				} 
				else {	
					int tempcnt = nownutr[r][c] / itage;
					if(tempcnt){
						nownutr[r][c] -= (tempcnt*itage);
						tempe += ((itage / 2)*tempcnt);
						it->cnt -= tempcnt;
						treecnt -= tempcnt;
						if ((it->cnt) == 0) it = maps[r][c].erase(it);
						else it++;
					}
					else {
						tempe += ((itage / 2)*it->cnt);
						treecnt -= (it->cnt);
						it = maps[r][c].erase(it);
					}
				}
			}
			nownutr[r][c] += tempe;
		}
	}
}
void fall(){
	POS DIR[] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (maps[r][c].empty()) continue;
			auto it = maps[r][c].begin();
			while (it != maps[r][c].end()){
				if ((it->age) % 5 == 0) {
					for (int idx = 0; idx < 8; idx++) {
						int dy = r + DIR[idx].r;
						int dx = c + DIR[idx].c;
						if (dy<1 || dx<1 || dy>N || dx>N) continue;
						//maps[dy][dx].insert(maps[dy][dx].begin(), { 1,1 });
						//treecnt++;
						auto dit = maps[dy][dx].begin();
						int flag = 0;
						while (dit != maps[dy][dx].end()) {
							if (1 == (dit->age)) {
								(dit->cnt)++;
								treecnt++;
								flag = 1;
								break;
							}
							dit++;
						}
						if (!flag) {
							maps[dy][dx].insert(maps[dy][dx].begin(), { 1,1 });
							treecnt++;
						}
					}
				}
				it++;
			}
		}
	}
}
void winter() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			nownutr[r][c] += willnutr[r][c];
		}
	}
}
void print() {
	cout << "=======================================\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			auto it = maps[r][c].begin();
			cout << "[ ";
			while (it != maps[r][c].end()) {
				cout << it->age << ": " << it->cnt << " , ";
				it++;
			}
			
			if(it== maps[r][c].end())
			cout << "]		";
		}
		cout << "\n";

	}
}
void printnutr() {
	cout << "=======================================\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << nownutr[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void solve() {
	for (int time = 0; time < K; time++) {
		springsummer();
		fall();
		winter();
	}
	int cnt = 0;
	for (int r = 1; r <= N; r++){
		for (int c = 1; c <= N; c++) {
			auto it = maps[r][c].begin();
			while (it != maps[r][c].end()) {
				cnt += (it->cnt);
				it++;
			}
		}
	}
	//cout << treecnt << '\n';
	cout << cnt << '\n';
}
int main(void) {
	freopen("16235_tree.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
}
#endif
