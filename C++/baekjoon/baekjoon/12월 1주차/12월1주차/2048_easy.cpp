#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX_N (20)
int N, maxx;
int maps[MAX_N + 2][MAX_N + 2];
char comb[5];
void init() {
	maxx = 0;
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout<< maps[r][c]<< " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> maps[r][c];
		}
	}
}
int upside() {
	//print();
	for (int c = 0; c < N; c++) {
		deque<int> dq;
		for (int r = 0; r < N; r++) {
			if (maps[r][c]) {
				dq.push_back(maps[r][c]);
				maps[r][c] = 0;
			}
		}
		int ridx = 0;
		while (!dq.empty()) {
			if (dq.size() >= 2) {
				int num1 = dq.front(); dq.pop_front();
				int num2 = dq.front(); dq.pop_front();
				if (num1 == num2) {
					maps[ridx][c] = num1 + num2;
					ridx++;
				}
				else {
					maps[ridx][c] = num1;
					dq.push_front(num2);
					ridx++;
				}
			}
			else {
				int num1 = dq.front(); dq.pop_front();
				maps[ridx][c] = num1;
				ridx++;
			}
		}
	}
	//print();
	return 1;
}
int downside() {
	//print();
	for (int c = 0; c < N; c++) {
		deque<int> dq;
		for (int r = N-1; r >=0; r--) {
			if (maps[r][c]) {
				dq.push_back(maps[r][c]);
				maps[r][c] = 0;
			}
		}
		int ridx = N-1;
		while (!dq.empty()) {
			if (dq.size() >= 2) {
				int num1 = dq.front(); dq.pop_front();
				int num2 = dq.front(); dq.pop_front();
				if (num1 == num2) {
					maps[ridx][c] = num1 + num2;
					ridx--;
				}
				else {
					maps[ridx][c] = num1;
					dq.push_front(num2);
					ridx--;
				}
			}
			else {
				int num1 = dq.front(); dq.pop_front();
				maps[ridx][c] = num1;
				ridx--;
			}
		}
	}
	return 1;
}
int rightside() {
	for (int r = 0; r < N; r++) {
		deque<int> dq;
		for (int c = N - 1; c >= 0; c--) {
			if (maps[r][c]) {
				dq.push_back(maps[r][c]);
				maps[r][c] = 0;
			}
		}
		int cidx = N - 1;
		while (!dq.empty()) {
			if (dq.size() >= 2) {
				int num1 = dq.front(); dq.pop_front();
				int num2 = dq.front(); dq.pop_front();
				if (num1 == num2) {
					maps[r][cidx] = num1 + num2;
					cidx--;
				}
				else {
					maps[r][cidx] = num1;
					dq.push_front(num2);
					cidx--;
				}
			}
			else {
				int num1 = dq.front(); dq.pop_front();
				maps[r][cidx] = num1;
				cidx--;
			}
		}
	}
	return 1;
}
int leftside() {
	for (int r = 0; r < N; r++) {
		deque<int> dq;
		for (int c = 0; c < N; c++) {
			if (maps[r][c]) {
				dq.push_back(maps[r][c]);
				maps[r][c] = 0;
			}
		}
		int cidx = 0;
		while (!dq.empty()) {
			if (dq.size() >= 2) {
				int num1 = dq.front(); dq.pop_front();
				int num2 = dq.front(); dq.pop_front();
				if (num1 == num2) {
					maps[r][cidx] = num1 + num2;
					cidx++;
				}
				else {
					maps[r][cidx] = num1;
					dq.push_front(num2);
					cidx++;
				}
			}
			else {
				int num1 = dq.front(); dq.pop_front();
				maps[r][cidx] = num1;
				cidx++;
			}
		}
	}
	return 1;
}
int check() {
	int maxv = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (maps[r][c] > maxv) maxv = maps[r][c];
		}
	}
	return maxv;
}
void DFS(int dep) {
	if (dep == 5) {
		/*cout << "===============\n";
		for (int i = 0; i < 5; i++) {
			cout << comb[i] << " ";
		}
		cout << '\n';*/
		//print();
		int ret = check();
		if (ret > maxx) maxx = ret;
		return;
	}
	int backup[MAX_N + 2][MAX_N + 2];
	copy(&maps[0][0], &maps[MAX_N+1][MAX_N+2], &backup[0][0]);
	
	int ret = upside();
	comb[dep] = 'U';
	DFS(dep + 1);
	copy(&backup[0][0], &backup[MAX_N + 1][MAX_N + 2], &maps[0][0]);
	
	ret = downside();
	comb[dep] = 'D';
	DFS(dep + 1);
	copy(&backup[0][0], &backup[MAX_N + 1][MAX_N + 2], &maps[0][0]);
	
	ret = rightside();
	comb[dep] = 'R';
	DFS(dep + 1);
	copy(&backup[0][0], &backup[MAX_N + 1][MAX_N + 2], &maps[0][0]);
	
	ret = leftside();
	comb[dep] = 'L';
	DFS(dep + 1);
	copy(&backup[0][0], &backup[MAX_N + 1][MAX_N + 2], &maps[0][0]);

}
void solve(){
	DFS(0);
	cout << maxx << '\n';
}
int main(void) {
	freopen("2048_easy.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();

	return 0;
}