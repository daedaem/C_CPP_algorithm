#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_NM (500)
int flu[MAX_NM + 2][MAX_NM + 2];
int put[MAX_NM + 2][MAX_NM + 2];
int bloomf[MAX_NM + 2][MAX_NM + 2];

struct SEED {
	int r, c, day;
	bool flower;
};
vector<SEED> seeds;
int N, M;
int maxxflower, maxxday;
int totalcnt;
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> flu[r][c];
			if (flu[r][c]) totalcnt++;
			else bloomf[r][c] = 1;
		}
	}
	int r, c; cin >> r >> c;
	put[r][c] = 1;
	seeds.push_back({ r,c,flu[r][c] + 1,false });
}
void addseeds(int seedidx) {
	static int dr[4] = { -1,0,1,0 };
	static int dc[4] = { 0,1,0,-1 };
	int r = seeds[seedidx].r;
	int c = seeds[seedidx].c;
	for (int i = 0; i < 4; i++) {
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (put[dy][dx]) continue;
		if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
		if (!flu[dy][dx]) continue;
		put[dy][dx] = 1;
		seeds.push_back({ dy,dx, flu[dy][dx] + 1, false });
	}
}
int bloom() {
	int bloomcnt = 0;
	int len = seeds.size();
	for (int i = 0; i < len; i++) {
		if (!seeds[i].day) continue;
		seeds[i].day--;
		if (!seeds[i].day) {
			seeds[i].flower = false;
		}
		else {
			if (!seeds[i].flower) {
				seeds[i].flower = true;
				bloomf[seeds[i].r][seeds[i].c] = 1;
				addseeds(i);
			}
			bloomcnt++;
		}
	}
	return bloomcnt;
}
int	checkalldead() {
	int len = seeds.size();
	for (int i = 0; i < len; i++) {
		if (seeds[i].day) return 0;
	}
	return 1;
}
int allbloom() {
	int cnt = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!bloomf[r][c]) return 0;
		}
	}
	return cnt;
}
void solve() {
	int cnt = 0;
	for (int day = 1; day<=1000;day++) {
		cnt = bloom();
		if (maxxflower < cnt) {
			maxxflower = cnt;
			maxxday = day;
		}
		if (checkalldead()) break;
		if (totalcnt == maxxflower) break;
		if(allbloom()) break;
	}
	cout << maxxday << "일\n" << maxxflower << "개\n";
}
int main(void) {
	freopen("mincheolsflower.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();

	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_NM (500)
int flu[MAX_NM + 2][MAX_NM + 2];
int bloomday[MAX_NM + 2][MAX_NM + 2];
struct SEED {
	int r, c, day;
	bool flower;
};
struct ST {
	int r, c, d;
};
int N, M;
int maxxflower, maxxday;
vector<SEED> seeds;
queue<ST> q;
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> flu[r][c];
		}
	}
	int r, c; cin >> r >> c;
	seeds.push_back({ r,c,flu[r][c] + 1,false });
}
void BFS() {
	q = {};
	fill(&bloomday[MAX_NM + 2][MAX_NM + 2], &bloomday[MAX_NM + 2][MAX_NM + 2], 0);
}
void solve() {

}
int main(void) {
	freopen("mincheolsflower.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();

	return 0;
}

#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_NM (500)
int flu[MAX_NM + 2][MAX_NM + 2];
int put[MAX_NM + 2][MAX_NM + 2];
struct SEED {
	int r, c, day;
	bool flower;
};
vector<SEED> seeds;
int N, M;
int maxxflower, maxxday;
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> flu[r][c];
		}
	}
	int r, c; cin >> r >> c;
	put[r][c] = 1;
	seeds.push_back({ r,c,flu[r][c]+1,false });
}
void addseeds(int seedidx) {
	static int dr[4] = { -1,0,1,0 };
	static int dc[4] = { 0,1,0,-1};
	int r = seeds[seedidx].r;
	int c = seeds[seedidx].c;
	for (int i = 0; i < 4; i++) {
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (put[dy][dx]) continue;
		if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
		if (!flu[dy][dx]) continue;
		put[dy][dx] = 1;
		seeds.push_back({ dy,dx, flu[dy][dx]+1, false });
	}
}
int dcnt = 1;
int bloom() {
	int bloomcnt = 0;
	cout << dcnt++ << "일\n";
	int len = seeds.size();
	for (int i = 0; i < len; i++) {
		if (!seeds[i].day) continue;
		seeds[i].day--;
		if (!seeds[i].day) {
			seeds[i].flower = false;
		}
		else {
			cout << seeds[i].r<< ","<<seeds[i].c << " ";
			if (!seeds[i].flower) {
				seeds[i].flower = true;
				addseeds(i);
			} 
			bloomcnt++;
		}
	}
	
	cout << bloomcnt<<"개\n";

	return bloomcnt;
}
int	checkalldead() {
	int len = seeds.size();
	for (int i = 0; i < len; i++) {
		if (seeds[i].day) return 0;
	}
	return 1;
}
int allput() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!put[r][c]) return 0;
		}
	}
	return 1;
}
void solve() {
	int cnt = 0;
	for (int day = 1; ;day++) {
		cnt = bloom();
		if (maxxflower < cnt) {
			maxxflower = cnt;
			maxxday = day;
		}
		if(checkalldead()) break;
	}
	//cout << maxxday << "일\n" << maxxflower << "개\n";
}
int main(void){
	freopen("mincheolsflower.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();

	return 0;
}
#endif