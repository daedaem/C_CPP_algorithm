#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N (10)
struct POS {
	int r, c, d;
};
queue<POS> q;
int arr[MAX_N + 2][MAX_N + 2];
int visit[MAX_N + 2][MAX_N + 2];
int N;
int order[5];
int nums[5];
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> arr[r][c];
		}
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout <<arr[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void rotate() {
	int newarr[MAX_N + 2][MAX_N + 2];
	fill(&newarr[0][0], &newarr[N][N + 1], 0);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			newarr[c][N - r - 1] = arr[r][c];
		}
	}
	copy(&newarr[0][0], &newarr[N][N + 1], &arr[0][0]);
}
void moveupside() {
	//cout << "Before : \n";
	//print();
	deque<int> dq;
	for (int c = 0; c < N; c++) {
		dq.clear();
		for (int r = 0; r < N; r++) {
			if (arr[r][c]) {
				dq.push_back(arr[r][c]);
				arr[r][c] = 0;
			}
		}
		int idx = 0;
		while (!dq.empty()) {
			int num = dq.front(); dq.pop_front();
			arr[idx++][c] = num;
		}
	}
	//cout << "After : \n";
	//print();
}
int getscore() {
	static int dr[] = {-1,0,1,0};
	static int dc[] = {0,1,0,-1};
	q = {};
	fill(&visit[0][0], &visit[N + 1][N + 1], 0);
	q.push({ 0,0,arr[0][0] });
	int num = arr[0][0];
	if (!num) return 0;
	int cnt = 1;
	visit[0][0] = 1;
	arr[0][0] = 0;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += dr[i];
			newdata.c += dc[i];
			if (newdata.r<0 || newdata.c<0 || newdata.r>=N || newdata.c>=N) continue;
			if (visit[newdata.r][newdata.c]) continue;
			if (arr[newdata.r][newdata.c] != newdata.d) continue;
			arr[newdata.r][newdata.c] = 0;
			cnt++;
			visit[newdata.r][newdata.c] = 1;
			q.push(newdata);
		}
	}
	return cnt * num;
}
int maxx = 0;
int cnt = 0;
void DFS(int dep, int sum) {
	if (dep == 4) {
		cnt++;
		//cout << "Order : ";
		//for (int i = 0; i < 4; i++) {
		//	cout << order[i] << " ";
		//}
		//cout << '\n';
		//cout << "numer : ";
		//for (int i = 0; i < 4; i++) {
		//	cout << nums[i] << " ";
		//}
		//cout << '\n';
		if (maxx < sum) {
			maxx = sum;
		}
		return;
	}
	int backup[MAX_N + 2][MAX_N + 2];
	copy(&arr[0][0], &arr[N][N + 1], &backup[0][0]);

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			rotate();
			int ret = getscore();
			order[dep] = i;
			DFS(dep + 1, sum+ret);
			copy(&backup[0][0], &backup[N][N + 1], &arr[0][0]);
		}
		else if (i == 1) {
			for (int num = 1; num <= 5; num++) {
				arr[0][0] = num;
				int ret = getscore();
				order[dep] = i;
				nums[dep] = num;
				DFS(dep + 1, sum+ret);
				order[dep] = 0;
				copy(&backup[0][0], &backup[N][N + 1], &arr[0][0]);
			}
		}
		else {
			moveupside();
			int ret = getscore();
			order[dep] = i;
			DFS(dep + 1, sum+ret);
			copy(&backup[0][0], &backup[N][N + 1], &arr[0][0]);
		}
	}
}
int main(void) {
	freopen("gaaaaame.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	DFS(0,0);
	cout << maxx << '\n';
	cout << "cnt : " << cnt << '\n';
	return 0;
}