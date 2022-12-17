#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_N (5)

int N;
char maps[MAX_N + 2][MAX_N + 2];
int visit[MAX_N + 2][MAX_N + 2][MAX_N + 2][MAX_N + 2];
struct POS {
	int r, c;
};
struct ST{
	int er, ec, ar, ac, d;
};
queue<ST> q;
int ER, EC, AR, AC;
void input() {
	cin >> N;
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++) {
			cin >> maps[r][c];
		}
	}
	cin >> ER >> EC >> AR >> AC;
}
int checkcontact(ST data) {
	int ar = data.ar;
	int ac = data.ac;
	int er = data.er;
	int ec = data.ec;

	//아래 이부분이 진짜 미치는줄알았다...
	//잘 못 생각했는데 굳게 믿었음
	if (ar < er - 2 || ar > er + 2 || ac < ec - 2 || ac > ec + 2) return 0;
	/*if (er == ar || ec == ac) {
		int ret = abs(er - ar) + abs(ec - ac);
		if (ret <= 2) return 1;
	}
	else if (){
		int ret = abs(er - ar) + abs(ec - ac);
		if (ret <= 4) return 1;
	}*/
	return 1;
}
int BFS() {
	static POS D[] = { {0,0}, {-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };
	if (ER == AR && EC == AC) return 0;
	
	q = {};
	fill(&visit[0][0][0][0], &visit[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 2], 0);
	q.push({ ER, EC, AR,AC, 0 });
	visit[ER][EC][AR][AC] = 1;
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		for (int ai = 0; ai <= 4; ai++) {
			ST newdata = data;
			newdata.ar += D[ai].r;
			newdata.ac += D[ai].c;
			newdata.d++;
			//경계밖인경우
			if (newdata.ar < 0 || newdata.ac < 0 || newdata.ar >= N || newdata.ac >= N) continue;
			//빙하인경우
			if (maps[newdata.ar][newdata.ac] == '#') continue;
			for (int ei = 1; ei <= 8; ei++) {
				if (ei > 4) {
					int ret = checkcontact(data); // 움직이기전이니까
					//만약 두칸 거리안에 존재한면 4방향만
					if (ret) break;
				}
				newdata.er = data.er + D[ei].r;
				newdata.ec = data.ec + D[ei].c;
				if (newdata.er < 0 || newdata.ec < 0 || newdata.er >= N || newdata.ec >= N) continue;
				///빙하인 경우 안되고
				if (maps[newdata.er][newdata.ec] == '#') continue;
				if (visit[newdata.er][newdata.ec][newdata.ar][newdata.ac]) continue;
				//거리 2안이면 끝내자
				if (newdata.er == newdata.ar && newdata.ec == newdata.ac) return newdata.d;
				visit[newdata.er][newdata.ec][newdata.ar][newdata.ac] = 1;
				q.push(newdata);
			}
		}
	}
	return -1;
}
int main(void) {
	freopen("annaelsa.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	cout <<BFS() << " sec\n";
	return 0;
}