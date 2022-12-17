#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �������
#define MAX_NM (1000)
struct POS {
	int r, c;
};
struct ST {
	int sr, sc, sdir;
};
POS D[] = { {0,1},{-1,0},{0,-1}, {1,0} };
int mirrorD[] = { 1,0,3,2 };
int maps[MAX_NM+2][MAX_NM + 2];
int N, M;
int result[MAX_NM + 2][MAX_NM + 2];
vector<ST> path;
void init(){
	fill(&maps[0][0], &maps[MAX_NM + 1][MAX_NM + 2], 0);
	path.clear();
}
void input() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> maps[r][c];
		}
	}
}
//void makepath() {
//	int idx = 0;
//	for (int i = 0; i < 2; i++) {
//		for (int r = 0; r < N; r++) {
//			path.push_back(idx);
//		}
//		for (int c = 0; c < M; c++) {
//			path.push_back(idx);
//		}
//		idx++;
//	}
//}
void makeside() {
	int idx = 1;
	int diridx = 0;
	for (int r = 1; r <= N; r++) {
		maps[r][0] = idx++;
		path.push_back({ r,0,diridx });
	}
	diridx++;
	for (int c = 1; c <= M; c++) {
		maps[N+1][c] = idx++;
		path.push_back({ N+1,c,diridx });
	}
	diridx++;
	for (int r = N; r >= 1; r--) {
		maps[r][M+1] = idx++;
		path.push_back({ r,M+1,diridx });
	}
	diridx++;
	for (int c = M; c >=1; c--) {
		maps[0][c] = idx++;
		path.push_back({ 0,c,diridx });
	}
	diridx++;
}
void print() {
	for (int r = 0; r < N + 2; r++) {
		for (int c = 0; c < M + 2; c++) {
			cout << result[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void light(int id) {
	fill(&result[0][0], &result[N+1][M+2], 0);
	int r=path[id].sr , c = path[id].sc, dir = path[id].sdir;
	//result[r][c] = id+1;
	while (1) {
		r += D[dir].r;
		c += D[dir].c;
		//result[r][c] = id+1;
		if (r == 0 || c == 0) break;
		if (r == N+1 || c == M+1) break;
		if(maps[r][c]==1){
			dir = mirrorD[dir];
		}
	}
	cout << maps[r][c] << " ";
}
void solve() {
	//makepath();
	makeside();
	for (int i = 1; i <= 2 * (N + M); i++) {
		light(i-1);
		//print();
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;

}