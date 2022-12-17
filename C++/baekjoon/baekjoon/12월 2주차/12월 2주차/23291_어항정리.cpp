#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N (100)
#define MAX_FISH (10000)
int N, K;
//int maps[MAX_N + 2][MAX_N + 2];
//vector<int> reptable;
deque<int> dq[MAX_N+2];
int NR;
//void maketable() {
//	reptable.resize(101, 0);
//	int start = 1;
//	int idx = 0;
//	for (int r = 2; r <= 10; r++) {
//		for (int rep = 0; rep <= 1; rep++) {
//			for (int n = 0; n < r; n++) {
//				start += 1;
//				reptable[start] = idx;
//				if (start == 100) return;
//			}
//			idx++;
//		}
//	}
//}
void init() {
	//memset(maps, 0, sizeof(maps));
	for (int r = 0; r < MAX_N + 2; r++) {
		dq[r] = {};
	}
	NR = MAX_N;
}
void input() {
	cin >> N >> K;
	dq[MAX_N].resize(N);
	for (int r = 0; r < N; r++) {
		cin >> dq[MAX_N][r];
	}
}
int check() {
	int maxx = 1;
	int minn = MAX_FISH;
	for(int i=0; i<dq[MAX_N].size();i++){
		if (maxx < dq[MAX_N][i]) maxx = dq[MAX_N][i];
		if (minn > dq[MAX_N][i]) minn = dq[MAX_N][i];
	}
	if (maxx - minn <= K) return 1;
	return 0;
}
void addfish() {
	vector<int> af;
	int minn = 10001;
	for (int i = 0; i < (int)dq[MAX_N].size(); i++) {
		if (dq[MAX_N][i] < minn) {
			minn = dq[MAX_N][i];
			af.clear();
			af.push_back(i);
		}
		else if (dq[MAX_N][i] == minn) {
			af.push_back(i);
		}
	}
	for (int i = 0; i < (int)af.size(); i++) {
		dq[MAX_N][af[i]]++;
	}
}
void print() {
	for (int r = 94; r <= MAX_N; r++) {
		for (int c = 0; c < dq[r].size(); c++) {
			cout << dq[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void roll(int lenr, int lenc) {
	deque<int>temp;
	for (int c = 0; c < lenc;c++) {;
		for (int r = MAX_N - lenr + 1; r <= MAX_N; r++) {
			temp.push_back(dq[r].front());
			dq[r].pop_front();
		}
	}
	for (int r = MAX_N - lenc; r < MAX_N; r++) {
		for (int c = 0; c < lenr; c++) {
			if (temp.empty()) break;
			int num = temp.front(); temp.pop_front();
			dq[r].push_front(num);
		}
	}
}
void control(int lenr,int lenc) {
	int dr[] = { 0,1 };
	int dc[] = { 1,0 };
	int tempsum[MAX_N + 1][MAX_N + 1];
	memset(tempsum, 0, sizeof(tempsum));
	for (int r = MAX_N - lenr+1; r <= MAX_N; r++) {
		for (int c = 0; c <= lenc; c++) {
			if (dq[r].size() <= c) continue;
			for (int idx = 0; idx < 4; idx++) {
				int dy = r + dr[idx];
				int dx = c + dc[idx];
				if (dy< MAX_N - lenr+1 || dy>MAX_N || dx < 0 || dx >lenc) continue;
				if (dq[dy].size() <= dx) continue;
				int ret = (abs(dq[r][c] - dq[dy][dx])) / 5;
				if (ret) {
					if (dq[r][c] > dq[dy][dx]) {
						tempsum[r][c] -= ret;
						tempsum[dy][dx] += ret;
					}
					else if (dq[r][c] < dq[dy][dx]) {
						tempsum[r][c] += ret;
						tempsum[dy][dx] -= ret;
					}
				}
			}
		}
	};
	for (int r = MAX_N - lenr+1; r <= MAX_N; r++) {
		for (int c = 0; c <= lenc; c++) {
			if (dq[r].size() <= c) continue;
			dq[r][c] += tempsum[r][c];
		}
	}
}
void makeoneline(int lenr,int lenc) {
	deque<int> temp;
	for (int c = 0; c < lenc; c++) {
		for (int r = MAX_N; r >= MAX_N-lenr; r--) {
			if (dq[r].empty()) continue;
			temp.push_back(dq[r].front());
			dq[r].pop_front();
		}
	}
	while (!temp.empty()) {
		dq[MAX_N].push_back(temp.front()); temp.pop_front();
	}
}

void rolling() {
	int num = dq[MAX_N].front(); dq[MAX_N].pop_front();
	dq[MAX_N - 1].push_back(num);
	deque<int> bowl;
	for (int r = 0; r < 2; r++) {
		bowl.push_back(dq[MAX_N - r].front());
		dq[MAX_N - r].pop_front();
	}
	dq[MAX_N - 1].resize(bowl.size());
	for (int i = bowl.size()-1; i >=0; i--) {
		dq[MAX_N - 1][0 + i] = bowl.back(); bowl.pop_back();
	}

	for (int c = 2; ; c++) {
		for (int r = c; r <= c + 1; r++) {
			if (dq[MAX_N].size() - c < r || dq[MAX_N].size() - c < c) {
				control(r, c);
				makeoneline(r, N);
				return;
			}
			roll(r, c);
		}
	}
}
void otherroll() {
	int lens = N / 2;
	for (int rep = 0; rep < 2; rep++) {
		deque<int> temp;
		if (rep == 0) {
			for (int i = 0; i < lens; i++) {
				int num = (dq[MAX_N].front());
				dq[MAX_N].pop_front();
				temp.push_back(num);
			}
			for (int c = 0; c < lens; c++) {
				dq[MAX_N - 1].push_front(temp.front());
				temp.pop_front();
			}
		}
		else {
			for (int r = 0; r < 2; r++) {
				for (int i = 0; i < lens; i++) {
					int num = (dq[MAX_N-r].front());
					dq[MAX_N-r].pop_front();
					temp.push_back(num);
				}
			}
			for (int r = 3; r >= 2; r--) {
				for (int c = 0; c < lens; c++) {
					dq[MAX_N - r].push_front(temp.front());
					temp.pop_front();
				}
			}
		}
		lens /= 2;
	}
}
int solve() {
	for (int time = 0; ;time++) {
		int ret = check();
		if (ret) return time;
		addfish();
		rolling();
		otherroll();
		control(4, N/4);
		//
		makeoneline(4, N/4);
	}
	return -1111;
}
int main(void) {
	freopen("23291.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//maketable();
	init();
	input();
	int ret = solve();
	cout << ret << '\n';

	return 0;
}