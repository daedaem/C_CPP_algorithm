#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define MAX_N (50)
int N, L, R;
int arr[MAX_N + 1][MAX_N + 1];
int visit[MAX_N + 1][MAX_N + 1];
struct POS 
{
	int r, c;
};
queue<POS> q;
struct GR 
{
	int sum, cnt, avg;
};
map<int, GR> groups;

void input() {
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> arr[r][c];
		}
	}
}
void  print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << visit[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << arr[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';

}
bool calc(int a, int b) {
	int ret = abs(a - b);
	return (L <= ret && ret <= R);
}
void floodfill(int sr, int sc,int groupidx) {
	static int dr[] = { -1,0,1,0 };
	static int dc[] = { 0, 1,0,-1 };
	q = {};
	int cnt = 0;
	int total = 0;
	q.push({ sr, sc });
	visit[sr][sc] = groupidx;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += dr[i];
			newdata.c += dc[i];
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= N) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (calc(arr[data.r][data.c], arr[newdata.r][newdata.c])) {
				q.push(newdata);
				visit[data.r][data.c] = groupidx;
				visit[newdata.r][newdata.c] = groupidx;
			}
		}
	}
}
bool iscandidate(int r, int c) {
	static int dr[] = { -1,0,1,0 };
	static int dc[] = { 0, 1,0,-1 };
	for (int i = 0; i < 4; i++) {
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
		if (calc(arr[dy][dx], arr[r][c])) return true;
	}
	return false;
}
int checkgroup() {
	fill(&visit[0][0], &visit[MAX_N][MAX_N + 1], 0);
	int groupidx = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (visit[r][c]) continue;
			if (iscandidate(r, c)) { // ������ �� �ĺ����� ������ �κе� üũ 
				groupidx++;
				floodfill(r,c, groupidx);
			}
		}
	}
	return groupidx;
}

void grouprecord() {
	groups.clear();
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (visit[r][c]) {
				groups[visit[r][c]].cnt++;
				groups[visit[r][c]].sum += arr[r][c];
			}
		}
	}
	for (int i = 1; i <= groups.size(); i++) {
		groups[i].avg = (double)groups[i].sum / groups[i].cnt;
	}
}
void arrupdate() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int gidx = visit[r][c];
			if (gidx) {
				arr[r][c] = groups[gidx].avg;
			}
		}
	}
}
int simulation() {
	for (int t = 0;; t++) {
		int temp = checkgroup();
		if (!temp) return t; // ���࿡ �׷��� �� ���θ� ��
		grouprecord();
		arrupdate();
	}
	return 0;
}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation()<<'\n';
	return 0;
}