#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAX_RC (1500)
struct POS {
	int r, c;
};
queue<POS> q;
int R,C, SR, SC, ER, EC;
char maps[MAX_RC + 2][MAX_RC + 2];
int visit[MAX_RC + 2][MAX_RC + 2];
int Lvisit[MAX_RC + 2][MAX_RC + 2];
vector<POS> backjos;
void init() {
	backjos.clear();
}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] == 'L') {
				backjos.push_back({ r,c });
			}
		}
	}
	SR = backjos[0].r;
	SC = backjos[0].c;
	ER = backjos[1].r;
	EC = backjos[1].c;

}
void print() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void printlvisit() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << Lvisit[r][c] <<" ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int cango() {
	queue<POS> cangoq;
	POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	cangoq = {};
	Lvisit[SR][SC] = 1;
	cangoq.push({ SR,SC });
	while (!cangoq.empty()) {
		POS data = cangoq.front(); cangoq.pop();
		for (int idx = 0; idx < 4; idx++) {
			POS ndata = data;
			ndata.r += DIR[idx].r;
			ndata.c += DIR[idx].c;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= R || ndata.c >= C) continue;
			if (Lvisit[ndata.r][ndata.c]) continue;
			if (maps[ndata.r][ndata.c] == 'X') continue;
			if (ndata.r == ER && ndata.c == EC) return 1;
			Lvisit[ndata.r][ndata.c] = 1;
			SR = ndata.r; SC = ndata.c;
			cangoq.push(ndata);
		}
	}
	return 0;
}
int bfs() {
	POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	q = {};
	fill(&visit[0][0], &visit[R + 1][C + 2], 0);
	fill(&Lvisit[0][0], &Lvisit[R + 1][R + 2], 0);

	vector<POS> willff;
	//처음 ff 돌려야할 곳 찾기
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (maps[r][c] == '.' || maps[r][c] == 'L') continue;
			for (int idx = 0; idx < 4; idx++) {
				int dy = r + DIR[idx].r;
				int dx = c + DIR[idx].c;
				if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
				if (maps[dy][dx] == '.' || maps[dy][dx] == 'L') {
					willff.push_back({ r,c });
					break;
				}
			}
		}
	}
	int time = 0;

	while (++time) {
		/*cout << "####"<<time<<'\n';
		cout << "before\n";
		print();*/
		for (int i = 0; i < willff.size(); i++) {
			q.push({ willff[i].r,willff[i].c });
		}
		willff.clear();
		while (!q.empty()) {
		// 여기서 willff에 담기
			POS data = q.front(); q.pop();
			if (maps[data.r][data.c] == '.') continue;
			for (int idx = 0; idx < 4; idx++) {
				POS newdata = data;
				newdata.r += DIR[idx].r;
				newdata.c += DIR[idx].c;
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= R || newdata.c >= C) continue;
				//if (maps[newdata.r][newdata.c] == '.') continue;
				if (maps[newdata.r][newdata.c] == '.'|| maps[newdata.r][newdata.c] == 'L') {
					maps[data.r][data.c] = '.';
					for (int didx = 0; didx < 4; didx++) {
						int dy = data.r + DIR[didx].r;
						int dx = data.c + DIR[didx].c;
						if (maps[dy][dx] == 'X') willff.push_back({ dy,dx });
					}
				}
			}
		}

		//cout << "after\n";
		//print();
		int ret = cango();
//		printlvisit();
		if (ret) return time;
	}
}
void solve() {
	cout <<bfs() <<'\n';
}
int main(void) {
	freopen("backjolake.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	input();
	solve();
}
