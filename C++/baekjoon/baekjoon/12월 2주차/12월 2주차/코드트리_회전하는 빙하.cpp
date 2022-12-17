#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
#define MAX_LEN (64)
struct POS {
	int r, c;
};
struct ICE{
	int cnt, size;
};
int N, Q, totalN;
int visit[MAX_LEN + 1][MAX_LEN + 1];
int maps[MAX_LEN + 1][MAX_LEN + 1];
int papper[MAX_LEN + 1][MAX_LEN + 1];
vector<ICE> ice;
vector<int> rotateorder;
void init() {
	memset(visit, 0, sizeof(visit));
	memset(maps, 0, sizeof(maps));
	memset(papper, 0, sizeof(papper));
	ice.clear();
	rotateorder.clear();
}
void input() {
	cin >> N >> Q;
	totalN = pow(2, N);
	//cout << totalN;
	for (int r = 0; r < totalN; r++) {
		for (int c = 0; c < totalN; c++) {
			cin >> maps[r][c];
		}
	}
	for (int i = 0; i < Q; i++) {
		int cc;  cin >> cc;
		rotateorder.push_back(cc);
	}
}
void printpapper() {
	for (int r = 0; r < totalN; r++) {
		for (int c = 0; c < totalN; c++) {
			cout << papper[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void print() {
	for (int r = 0; r < totalN; r++) {
		for(int c=0; c<totalN;c++){
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void gridmove(int sr, int sc, int dir, int len) {
	//cout << sr << sc << idx << len << '\n';
	POS DIR[] = { {0,1},{1,0},{0,-1},{-1,0} };
	for (int r = sr; r < sr + len; r++) {
		for (int c = sc; c < sc+len; c++) {
			papper[r+len*DIR[dir].r][c+len*DIR[dir].c]= maps[r][c];
		}
	}
	//papper[sr+len*DIR[idx].r][sc+len * DIR[idx].c] = maps[sr][sc];
}
void rotategrid(int sr, int sc, int er, int ec, int lens) {
	int len = lens / 2;
	for (int r = 0; r < lens; r +=len) {
		for (int c = 0; c < lens; c += len) {
			// 시작 지점과 회전시켜야할 길이
			gridmove(sr, sc, 0, len);
			gridmove(sr, sc + len, 1,len);
			gridmove(sr+len, sc + len, 2, len);
			gridmove(sr + len, sc, 3, len);
		}
	}
	//printpapper();

}
void rotate(int level) {
	int lens = pow(2, level);
	int rep = totalN / lens;
	for (int r = 0; r < rep; r++) {
		for (int c = 0; c < rep; c++) {
			// 시작 지점과 회전시켜야할 길이
			int sr = 0 + lens * r;
			int sc = 0 + lens * c;
			int er = sr + lens - 1;
			int ec = sc + lens - 1;
			//cout << sr << " " << sc << "  " << er << " " << ec << '\n';
			rotategrid(sr,sc,er,ec, lens);
		}
	}
	// 돌려놓고 복제
	copy(&papper[0][0], &papper[MAX_LEN][MAX_LEN+1], &maps[0][0]);
}
int check(int sr, int sc) {
	POS DIR[] = { {0,1},{1,0},{0,-1},{-1,0} };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dy = sr + DIR[i].r;
		int dx = sc + DIR[i].c;
		if (dy<0 || dy>=totalN || dx<0 || dx>=totalN) continue;
		if (maps[dy][dx]) cnt++;
		if (cnt >= 3) return 1;
	}
	return 0;
}
void meltice() {
	int record[MAX_LEN + 1][MAX_LEN + 1];
	memset(record, 0, sizeof(record));
	for (int r = 0; r < totalN; r++) {
		for (int c = 0; c < totalN; c++) {
			if (!maps[r][c]) continue;
			int ret= check(r, c);
			if (!ret) record[r][c]++;
		}
	}
	for (int r = 0; r < totalN; r++) {
		for (int c = 0; c < totalN; c++) {
			if (record[r][c]) maps[r][c] -= 1;
			if (maps[r][c] < 0) maps[r][c] = 0;
		}
	}
}
void BFS(int sr, int sc) {
	POS DIR[] = { {0,1},{1,0},{0,-1},{-1,0} };
	queue<POS> q;
	q.push({ sr,sc });
	visit[sr][sc] = 1;
	int size = 1;
	int cnt = maps[sr][sc];
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int idx = 0; idx < 4; idx++) {
			POS ndata = data;
			ndata.r += DIR[idx].r;
			ndata.c += DIR[idx].c;
			if (ndata.r < 0 || ndata.c < 0 || ndata.r >= totalN || ndata.c >= totalN) continue;
			if (visit[ndata.r][ndata.c]) continue;
			if (!maps[ndata.r][ndata.c]) continue;
			visit[ndata.r][ndata.c] = 1;
			cnt += maps[ndata.r][ndata.c];
			size++;
			q.push(ndata);
		}
	}
	ice.push_back({ cnt, size });
}
void solve() {
	for (int i = 0; i < Q; i++) {
		int rlevel = rotateorder[i];
		if (rlevel) {
			rotate(rlevel);
		}
		meltice();
	}
	memset(visit, 0, sizeof(visit));
	for (int r = 0; r < totalN; r++) {
		for (int c = 0; c < totalN; c++) {
			if (!maps[r][c]) continue;
			if (visit[r][c]) continue;
			BFS(r, c);
		}
	}
	int cnt = 0;
	int maxsize = 0;
	for (int i = 0; i < ice.size(); i++) {
		cnt += ice[i].cnt;
		if (maxsize < ice[i].size) {
			maxsize = ice[i].size;
		}
	}
	cout << cnt << "\n" << maxsize << '\n';
}
int main(void) {
	freopen("rotateice.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	init();
	input();
	solve();

	return 0;
}

