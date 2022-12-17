#define _CRT_SECURE_NO_WARNINGS
// 미리 고스트맵 만들기 버젼
// 아직 미완성
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_NM (100)
#define MAX_G (4)
struct POS {
	int r, c;
};
int T, N, M;
vector<POS> ghost;
vector<POS> me;
queue<POS>q;
queue<POS>gq;
char maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
int ghostmap[400][MAX_NM + 2][MAX_NM + 2];
void init() {

	ghost.clear();
	me.clear();
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], '#');
	fill(&visit[0][0], &visit[N + 1][M + 2], 0);
	fill(&ghostmap[0][0][0], &ghostmap[399][N + 1][M + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'S') {
				me.push_back({ r,c });
			}
			else if (maps[r][c] == 'C') {
				ghost.push_back({ r,c });
			}
		}
	}
}
int BFS() {
	static POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	gq = {};
	//맵표시

	for (int time = 1; ; time++) {
		while (!q.empty()) {
			POS data = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				POS newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
				if (maps[newdata.r][newdata.c] == '#') continue;
				if (visit[newdata.r][newdata.c] == time) continue;
				if (ghostvisit[newdata.r][newdata.c] == time * (-1)) continue;
				if (maps[newdata.r][newdata.c] == 'E') return time;
				visit[newdata.r][newdata.c] = time;
				me.push_back({ newdata.r, newdata.c });
			}
		}
	}

}
void ghostmapmake() {
	for (int i = 0; i < ghost.size(); i++) {
		gq.push({ ghost[i].r ,ghost[i].c });
	}
	ghost.clear();
	while (!gq.empty()) {
		POS data = gq.front(); gq.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += D[i].r;
			newdata.c += D[i].c;
			if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
			if (maps[newdata.r][newdata.c] == '#') continue;
			if (ghostvisit[newdata.r][newdata.c]) continue;
			ghostvisit[newdata.r][newdata.c] = (-1)*time;
			ghost.push_back({ newdata.r, newdata.c });
		}
	}
}
int main(void) {
	freopen("horrorgame.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		ghostmapmake();
		cout << "#" << tc << " " << BFS() << '\n';
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_NM (100)
#define MAX_G (4)
struct POS {
	int r, c, time;
};
int T, N, M;
queue<POS>q;
queue<POS>gq;
char maps[MAX_NM + 2][MAX_NM + 2];
int visit[MAX_NM + 2][MAX_NM + 2];
int SR, SC, ER, EC;
void init() {
	q = {};
	gq = {};
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], '#');
	fill(&visit[0][0], &visit[N + 1][M + 2], 0);
}
void input() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'S') {
				q.push({ r,c ,0});
				SR = r;
				SC = c;
			}
			else if (maps[r][c] == 'C') {
				gq.push({ r,c,0 });
			}
			else if (maps[r][c] == 'E') {
				ER = r;
				EC = c;
			}
		}
	}
}
int BFS() {
	static POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
	//맵표시
	while (!q.empty()) {
		int len = gq.size();
		for (int i = 0; i < len; i++) {
			POS data = gq.front(); gq.pop();
			maps[data.r][data.c] = '.';
			gq.push(data);
		}
		for (int id = 0; id < len; id++) {
			POS data = gq.front(); gq.pop();
			for (int i = 0; i < 4; i++) {
				POS newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				newdata.time++;
				if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
				if (maps[newdata.r][newdata.c] == '#') continue;
				maps[newdata.r][newdata.c] = '#';
				gq.push(newdata);
			}
		}
		len = q.size();
		for (int id = 0; id < len; id++) {
			POS data = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				POS newdata = data;
				newdata.r += D[i].r;
				newdata.c += D[i].c;
				newdata.time++;
				if (newdata.r<1 || newdata.c<1 || newdata.r>N || newdata.c>M) continue;
				if (maps[newdata.r][newdata.c] == '#') continue;
				if (visit[newdata.r][newdata.c]) continue;
				if (newdata.r == ER && newdata.c == EC) return newdata.time;
				visit[newdata.r][newdata.c] = 1;
				q.push(newdata);
			}
		}
	}
	return -1;
}
int main(void) {
	freopen("horrorgame.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		cout << "#" << tc << " " << BFS() << '\n';
	}
	return 0;
}
#endif
#if 0
//공포게임 공량
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN (100)
using namespace std;

char map[MAXN][MAXN];
int chk[MAXN][MAXN];
int g_map[4][MAXN][MAXN];
int g_cnt;
struct POS {
	int r, c;
};
POS str;
POS dst;
vector<POS>g;
struct STATUS {
	int r, c;
	int cnt;
};
queue<STATUS>q;

int R, C;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

void Debug() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << map[r][c] << ' ';
		}
		cout << '\n';
	}
}

void Debug_g() {
	cout << "g_map-----------------------\n";
	for (int i = 0; i < g_cnt; i++) {
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (g_map[i][r][c] == 0x7fffffff)cout << "- ";
				else cout << g_map[i][r][c] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void Init() {
	g_cnt = 0;
	q = {};
	g.clear();
	memset(chk, 0, sizeof(chk));
}

void Make_gmap(int idx, int sr, int sc) {
	g_map[idx][sr][sc] = 0;
	q.push({ sr,sc,0 });

	while (!q.empty()) {
		STATUS data = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			STATUS ndata;
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			ndata.cnt = data.cnt + 1;

			if (ndata.r < 0 || ndata.r >= R || ndata.c < 0 || ndata.c >= C) continue;
			if (map[ndata.r][ndata.c] == '#') continue;
			if (g_map[idx][ndata.r][ndata.c] <= ndata.cnt) continue;

			g_map[idx][ndata.r][ndata.c] = ndata.cnt;
			q.push(ndata);
		}
	}
}

void Input_Data() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == 'C') {
				g.push_back({ r,c });
				g_cnt++;
			}
			if (map[r][c] == 'S') {
				str.r = r; str.c = c;
			}
			if (map[r][c] == 'E') {
				dst.r = r; dst.c = c;
			}
		}
	}
	//   Debug();

	   //귀신 맵 만들기
	for (int i = 0; i < g_cnt; i++) {
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				g_map[i][r][c] = 0x7fffffff;
			}
		}
		Make_gmap(i, g[i].r, g[i].c);
	}
	//   Debug_g();
}

int g_check(int r, int c, int cnt) {
	for (int idx = 0; idx < g_cnt; idx++) {
		if (g_map[idx][r][c] <= cnt && (g_map[idx][r][c] + cnt) % 2 == 0) return 1;
	}
	return 0;
}

int Simulation() {
	q.push({ str.r,str.c,0 });
	chk[str.r][str.c] = 1;

	while (!q.empty()) {
		STATUS data = q.front(); q.pop();
		if (data.r == dst.r&&data.c == dst.c) return data.cnt;

		for (int i = 0; i < 4; i++) {
			STATUS ndata;
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			ndata.cnt = data.cnt + 1;

			if (ndata.r < 0 || ndata.r >= R || ndata.c < 0 || ndata.c >= C) continue;
			if (map[ndata.r][ndata.c] == '#') continue;
			if (g_check(ndata.r, ndata.c, ndata.cnt)) continue;
			if (chk[ndata.r][ndata.c])continue;

			chk[ndata.r][ndata.c] = 1;
			q.push(ndata);

		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {

		Init();
		Input_Data();
		cout << '#' << t << ' ' << Simulation() << '\n';


	}


	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int R, C;
int sr, sc;
int black_r, black_c; //블랙홀. 즉 최종 목적지
char map[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
struct STATUS
{
	int r, c;
	int t;
};


vector<pair<int, int>> V;

queue<STATUS> gq; //고스트큐
queue<STATUS> mq; //민수큐


void input(void)
{
	cin >> R >> C;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 'C') V.push_back({ r, c }); //무서운 유령들!!의위치.
			if (map[r][c] == 'E') black_r = r, black_c = c;
			if (map[r][c] == 'S') sr = r, sc = c; //시작점
		}
	}

}


void init_chk(void)
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++) chk[r][c] = 0;
	}
}



int simulation(void)
{

	while (!mq.empty()) //민수가 죽어없어질때까지. 안죽고 블랙홀만나서 끝날수도있음. 그럼 게임승리!
	{

		//고스트먼저.

		int GSIZE = gq.size();

		for (int i = 0; i < GSIZE; i++) //고스트들 어차피 무조건 움직이니까 고스트들이 있던 자리는 무조건 '.'이됨.
		{
			STATUS data = gq.front(); gq.pop();
			map[data.r][data.c] = '.'; //미리 .으로 만들어놓고
			gq.push(data);
		}


		for (int i = 0; i < GSIZE; i++) //갈수있는곳으로 한칸씩 다 움직여보자.
		{
			STATUS data = gq.front(); gq.pop();

			for (int d = 0; d < 4; d++)
			{
				int nr = data.r + dr[d];
				int nc = data.c + dc[d];

				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if (map[nr][nc] == '#') continue;

				map[nr][nc] = '#'; //유령이 그자리에 갔다면 벽이라 하면된다. 
				gq.push({ nr, nc, data.t + 1 });


			}
		}


		int MSIZE = mq.size();

		for (int i = 0; i < MSIZE; i++) //민수가 갈수있는곳으로 한칸씩움직여보자.
		{
			STATUS data = mq.front(); mq.pop();

			for (int d = 0; d < 4; d++)
			{
				int nr = data.r + dr[d];
				int nc = data.c + dc[d];

				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if (map[nr][nc] == '#') continue;
				if (chk[nr][nc] == 1) continue;

				if (nr == black_r && nc == black_c) //종료조건.
				{
					return data.t + 1;
				}


				mq.push({ nr, nc, data.t + 1 });
				chk[nr][nc] = 1;

			}
		}


	}
	return -1;


}


int main(void)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{

		input();
		init_chk();

		for (auto g : V)
		{
			gq.push({ g.first, g.second, 0 });
		}
		mq.push({ sr, sc, 0 });
		chk[sr][sc] = 1;


		cout << '#' << test_case << ' ' << simulation() << '\n';
		gq = {};
		mq = {};
		V.clear();
	}


	return 0;
}
#endif
