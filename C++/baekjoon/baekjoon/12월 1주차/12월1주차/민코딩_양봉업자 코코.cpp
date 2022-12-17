#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define MAX_NM (15)

struct POS {
	int r, c;
};
struct ST {
	int r, c, sum, cnt;
	set<pair<int,int>>s;
};
int maxsum;
POS DIR[][7] = { 
	{{-1,0},{-1,1},{-1,-1} ,{0,1},{0,-1},{1,0},{0,0} },
	{{-1,0},{0,1},{0,-1} ,{1,1},{1,-1}, {1,0}, {0,0} },
};
vector<vector<int>> beehouse;
queue<ST> q;
int N, M;
void init() {
	beehouse.resize(0, vector<int>(0));
	maxsum = 0;
	for (int i = 0; beehouse.size(); i++) {
		beehouse[i].clear();
	}
}
void input() {
	cin >> N >> M;
	beehouse.resize(N, vector<int>(M));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> beehouse[r][c];
		}
	}
}
int BFS() {
	q = {};
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			q.push({ r,c,0, 0, {} });
		}
	}
	int maxxsum = 0;
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		int ret = data.c % 2;
		for (int i = 0; i < 6; i++) {
			ST newdata = data;
			newdata.r += DIR[ret][i].r;
			newdata.c += DIR[ret][i].c;
			newdata.cnt++;
			newdata.s.insert({ newdata.r, newdata.c });
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
			if (newdata.cnt > 6) continue;  //4°³ °¬´Ù¿À´Âµ¥ 6¹øÀÌ¸é µÇ´Ï±î
			if (newdata.s.size() == 4) {
				auto it = newdata.s.begin();
				while (it != newdata.s.end()) {
					newdata.sum += beehouse[it->first][it->second];
					it++;
				}
				if (newdata.sum > maxxsum) maxxsum = newdata.sum;
				continue;
			}
			if (newdata.cnt < 6) q.push(newdata);
		}
	}
	return maxxsum;
}
void solve() {
	int ret = BFS();
	cout << ret << '\n';
}
int main(void) {
	freopen("beemastercoco.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	input();
	solve();
	
	return 0;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[17][17];
int ans = -1;
int dr[] = { 0,0,1,-1,-1,-1,1,1 };
int dc[] = { 1,-1,0,0,-1,1,-1,1 };
struct POS
{
	int r;
	int c;
	int select;
	bool operator<(const POS &a)const
	{
		if (select == a.select) return r < a.r;
		return select < a.select;
	}
};
priority_queue<POS> q;

void input(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void go(int x, int y)
{
	int chk[17][17];
	memset(chk, 0, sizeof(chk));
	q = {};
	int cnt = 0;
	int ret = 0;

	q.push({ x,y,map[x][y] });

	while (!q.empty())
	{
		POS data = q.top(); q.pop();
		if (chk[data.r][data.c]) continue;
		cnt++;
		ret += data.select;
		chk[data.r][data.c] = 1;
		if (cnt == 4)
		{
			if (ret > ans) ans = ret;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			POS ndata;
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			if (ndata.r < 0 || ndata.r >= N || ndata.c < 0 || ndata.c >= M) continue;
			if (chk[ndata.r][ndata.c]) continue;
			ndata.select = map[ndata.r][ndata.c];
			q.push(ndata);
		}
		if (data.c % 2 == 0) // Âð³ë¶û
		{
			for (int i = 4; i <= 5; i++)
			{
				POS ndata;
				ndata.r = data.r + dr[i];
				ndata.c = data.c + dc[i];
				if (ndata.r < 0 || ndata.r >= N || ndata.c < 0 || ndata.c >= M) continue;
				if (chk[ndata.r][ndata.c]) continue;
				ndata.select = map[ndata.r][ndata.c];
				q.push(ndata);
			}
		}
		else
		{
			for (int i = 6; i <= 7; i++)
			{
				POS ndata;
				ndata.r = data.r + dr[i];
				ndata.c = data.c + dc[i];
				if (ndata.r < 0 || ndata.r >= N || ndata.c < 0 || ndata.c >= M) continue;
				if (chk[ndata.r][ndata.c]) continue;
				ndata.select = map[ndata.r][ndata.c];
				q.push(ndata);
			}
		}
	}
}

void solve(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			go(i, j);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	cout << ans << '\n';

	return 0;
}
#endif