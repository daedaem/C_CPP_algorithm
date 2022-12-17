#define _CRT_SECURE_NO_WANRINGS
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_M (700)
#define MAX_N (1000000)

struct POS {
	int r, c;
};
long long M, N, maps[MAX_M + 2][MAX_M + 2];
int numcnt[4];
void print() {
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void incMapupdate() {
	int idx = 0;
	int r = M - 1;
	int c = 0;
	while (idx <= 2) {
		while (!numcnt[idx]) {
			idx++;
			if (idx > 2) break;
		}
		if (idx > 2) break;
		numcnt[idx]--;
		if (r >= 0) {
			maps[r][c] += idx;
			r--;
		}
		else if (r < 0) {
			c++;
			maps[0][c] += idx;
		}
	}
}
void mapUpdate() {
	for (int c = 1; c < M; c++) {
		for (int r = 1; r < M; r++) {
			if (c == 1) {
				maps[r][c] = max(maps[r][c - 1], max(maps[r - 1][c], maps[r - 1][c - 1]));
			}
			else maps[r][c] = maps[r - 1][c];
		}
	}
}
void solve() {
	cin >> M >> N;
	fill(&maps[0][0], &maps[MAX_M + 1][MAX_M + 2], 1);
	//1번 사이드 부분 부터 크기 키우기
	print();

	for (int i = 0; i < N; i++) {
		cin >> numcnt[0] >> numcnt[1] >> numcnt[2];
		incMapupdate();
	mapUpdate();
	print();
	}
}
int main(void) {
	freopen("queenbee.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_M (700)
#define MAX_N (1000000)

struct POS {
	int r, c;
};
long long M, N, maps[MAX_M + 2][MAX_M + 2];
int zcnt, ocnt, tcnt;
int sums[MAX_M * 2];
void print() {
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
}
void solve() {
	cin >> M >> N;
	int totalcnt = 2 * M - 1;
	fill(&maps[0][0], &maps[MAX_M + 1][MAX_M + 2], 1);
	//1번 사이드 부분 부터 크기 키우기
	for (int i = 0; i < N; i++) {
		cin >> zcnt >> ocnt >> tcnt;
		for (int c = zcnt; c < zcnt+ocnt; c++) {
			sums[c]++;
		}
		for (int c = zcnt+ocnt; c < 2*M; c++) {
			sums[c]++;
		}
	}

	for (int i = 0; i < 2 * M; i++) {
		int r = M - 1;
		int c = 0;
		while (totalcnt) {
			if (r >= 0) {
				r--;
			}
			else (r < 0) {
				c++;
			}
			totalcnt--;
		}
	}

	for (int c = 1; c < M; c++) {
		for (int r = 1; r < M; r++) {
			maps[r][c] = max(maps[r][c - 1], max(maps[r - 1][c], maps[r - 1][c - 1]));
		}
	}

	print();
}
int main(void) {
	freopen("queenbee.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}
#endif