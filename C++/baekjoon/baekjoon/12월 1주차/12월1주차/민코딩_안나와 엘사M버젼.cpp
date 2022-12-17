#include <iostream>
#include <queue>
using namespace std;

#define MAX_N (5)

char maps[MAX_N + 2][MAX_N + 2];
int visit[MAX_N + 2][MAX_N + 2][MAX_N + 2][MAX_N + 2];
int N, elr, elc, anr, anc;

struct POS {
	int r, c;
};
struct ST {
	int elr, elc, anr, anc, d;
};
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> maps[r][c];
		}
	}
	cin >> elr >> elc >> anr >> anc;
}
int solve(){
	static POS D[] = { {0,0},{-1,0},{0,1},{1,0},{0,-1} };
	queue<ST>q;
	
	if (elr == anr && elc == anc) return 0;

	fill(&visit[0][0][0][0], &visit[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 2], 0);
	q.push({ elr, elc, anr, anc, 0 });
	visit[elr][elc][anr][anc] = 1;
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int ai = 0; ai < 5; ai++) {
			for (int ei = 0; ei < 5; ei++) {
				ST newdata = data;
				newdata.elr += D[ei].r;
				newdata.elc += D[ei].c;
				newdata.anr += D[ai].r;
				newdata.anc += D[ai].c;
				newdata.d++;
				if (newdata.elr < 0 || newdata.elc < 0 || newdata.elr >= N || newdata.elc >= N) continue;
				if (newdata.anr < 0 || newdata.anc < 0 || newdata.anr >= N || newdata.anc >= N) continue;
				if (maps[newdata.elr][newdata.elc]=='#') continue;
				if (maps[newdata.anr][newdata.anc]=='#')continue;
				if (visit[newdata.elr][newdata.elc][newdata.anr][newdata.anc]) continue;
				if (newdata.anr == newdata.elr && newdata.anc == newdata.elc) return newdata.d;
				visit[newdata.elr][newdata.elc][newdata.anr][newdata.anc] = 1;
				q.push({ newdata });
			}
		}
	}
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	cout <<solve()<<'\n';

}
