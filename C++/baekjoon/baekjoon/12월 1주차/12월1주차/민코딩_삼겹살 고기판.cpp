#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_NM (15)

int board[MAX_NM + 2][MAX_NM + 2];
int backup[MAX_NM + 2][MAX_NM + 2];
int N, M;
deque<int> side;
vector<int> perm;
void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> board[r][c];
			backup[r][c] = board[r][c];
		}
	}
}
void rotate() {
	for (int c = 0; c < M-1; c++) {
		side.push_back(board[0][c]);
	}
	for (int r = 0; r <N-1; r++) {
		side.push_back(board[r][M-1]);
	}
	for (int c = M-1; c >=1; c--) {
		side.push_back(board[N-1][c]);
	}
	for (int r = N-1; r>=1; r--) {
		side.push_back(board[r][0]);
	}
	int num = side.back(); side.pop_back();
	side.push_front(num);
	//로테이트
	for (int c = 0; c < M-1; c++) {
		board[0][c] = side.front(); side.pop_front();
	}
	for (int r = 0; r < N-1; r++) {
		board[r][M - 1] = side.front(); side.pop_front();
	}
	for (int c = M - 1; c >= 1; c--) {
		board[N - 1][c] = side.front(); side.pop_front();
	}
	for (int r = N - 1; r >= 1; r--) {
		board[r][0] = side.front(); side.pop_front();
	}
}
void moveup() {
	for (int c = 0; c < M; c++) {
		deque<int> bowl;
		for (int r = 0; r < N; r++) {
			if (board[r][c]) {
				bowl.push_back(board[r][c]);
				board[r][c] = 0;
			}
		}
		//만일 다비었으면 넘기기
		if (bowl.empty()) continue;
		int val = bowl.front(); bowl.pop_front();
		int samecnt = 1;
		int len = bowl.size();
		int num;
		for (int idx = 0; idx < len; idx++) {
			num = bowl.front(); bowl.pop_front();
			if (val == num) {
				samecnt++;
			}
			else {
				bowl.push_back(samecnt*val);
				samecnt = 1;
				val = num;
			}
		}
		bowl.push_back(samecnt*val);
		int idx = 0;
		while (!bowl.empty()) { 
			board[idx++][c] = bowl.front(); bowl.pop_front();
		}
	}
}
void movedown() {
	for (int c = 0; c < M; c++) {
		deque<int> bowl;
		for (int r = N-1; r >=0; r--) {
			if (board[r][c]) {
				bowl.push_back(board[r][c]);
				board[r][c] = 0;
			}
		}
		//만일 다비었으면 넘기기
		if (bowl.empty()) continue;
		int val = bowl.front(); bowl.pop_front();
		int samecnt = 1;
		int len = bowl.size();
		int num;
		for (int idx = 0; idx < len; idx++) {
			num = bowl.front(); bowl.pop_front();
			if (val == num) {
				samecnt++;
			}
			else {
				bowl.push_back(samecnt*val);
				samecnt = 1;
				val = num;
			}
		}
		bowl.push_back(samecnt*val);
		int idx = N-1;
		while (!bowl.empty()) {
			board[idx--][c] = bowl.front(); bowl.pop_front();
		}
	}
}
void moveright() {
	for (int r = 0; r < N; r++) {
		deque<int> bowl;
		for (int c = 0; c < M; c++) {
			if (board[r][c]) {
				bowl.push_back(board[r][c]);
				board[r][c] = 0;
			}
		}
		//만일 다비었으면 넘기기
		if (bowl.empty()) continue;
		int val = bowl.front(); bowl.pop_front();
		int samecnt = 1;
		int len = bowl.size();
		int num;
		for (int idx = 0; idx < len; idx++) {
			num = bowl.front(); bowl.pop_front();
			if (val == num) {
				samecnt++;
			}
			else {
				bowl.push_back(samecnt*val);
				samecnt = 1;
				val = num;
			}
		}
		bowl.push_back(samecnt*val);
		int idx = M-1;
		while (!bowl.empty()) {
			board[r][idx++] = bowl.front(); bowl.pop_front();
		}
	}
}

void moveleft() {
	for (int r = 0; r < N; r++) {
		deque<int> bowl;
		for (int c = 0; c < M; c++) {
			if (board[r][c]) {
				bowl.push_back(board[r][c]);
				board[r][c] = 0;
			}
		}
		//만일 다비었으면 넘기기
		if (bowl.empty()) continue;
		int val = bowl.front(); bowl.pop_front();
		int samecnt = 1;
		int len = bowl.size();
		int num;
		for (int idx = 0; idx < len; idx++) {
			num = bowl.front(); bowl.pop_front();
			if (val == num) {
				samecnt++;
			}
			else {
				bowl.push_back(samecnt*val);
				samecnt = 1;
				val = num;
			}
		}
		bowl.push_back(samecnt*val);
		int idx = 0;
		while (!bowl.empty()) {
			board[r][idx++] = bowl.front(); bowl.pop_front();
		}
	}
}
int findbig() {
	int maxx = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (maxx < board[r][c]) maxx = board[r][c];
		}
	}
	return maxx;
}
int simulation() {
	for(int i=0; i<perm.size();i++){
		int button = perm[i];
		if (button == 0) {
			rotate();
		}
		else if (button == 1) {
			//상
			moveup();
		}
		else if (button == 2) {
			//우
			moveright();
		}
		else if (button == 3) {
			//하
			movedown();
		}
		else if (button == 4) {
			//좌
			moveleft();
		}
	}
	return findbig();
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << board[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int maxx = 0;
void makeperm(int dep) {
	if (dep == 6) {
		copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &board[0][0]);
		int ret = simulation();
		//print();
		if (ret > maxx) maxx = ret;
		return;
	}
	//int backup[MAX_NM + 2][MAX_NM + 2];
	//copy(&board[0][0], &board[MAX_NM + 1][MAX_NM + 2], &backup[0][0]);

	for (int i = 0; i < 5; i++) {
		perm.push_back(i);
		makeperm(dep + 1);
		perm.pop_back();
		//copy(&backup[0][0], &backup[MAX_NM + 1][MAX_NM + 2], &board[0][0]);
	}
}
void solve() {	
	makeperm(0);
	cout << maxx<<'\n';
}
int main(void) {
	freopen("samgyupsal.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}

#if 0
#include <iostream>
using namespace std;
int N, M;
int input_map[20][20];
int max_result;
void Input()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> input_map[y][x];
		}
	}
}
void MakeMap(int map[20][20], int next[5][20][20])
{
	//왼쪽
	int flag;
	int t;
	int target;
	for (int y = 0; y < N; y++) {
		flag = 0;
		t = 0;
		for (int x = 0; x < M; x++) {
			if (map[y][x] > 0) {
				if (flag == 0) {
					next[0][y][t++] = map[y][x];
					target = map[y][x];
					flag = 1;
				}
				else {
					if (target == map[y][x]) next[0][y][t - 1] += target;
					else {
						next[0][y][t++] = map[y][x];
					}
				}
			}
		}
	}
	//오른쪽
	for (int y = 0; y < N; y++) {
		flag = 0;
		t = M - 1;
		for (int x = M - 1; x >= 0; x--) {
			if (map[y][x] > 0) {
				if (flag == 0) {
					next[1][y][t--] = map[y][x];
					target = map[y][x];
					flag = 1;
				}
				else {
					if (target == map[y][x]) next[1][y][t + 1] += target;
					else {
						next[1][y][t--] = map[y][x];
					}
				}
			}
		}
	}
	//위
	for (int x = 0; x < M; x++) {
		flag = 0;
		t = 0;
		for (int y = 0; y < N; y++) {
			if (map[y][x] > 0) {
				if (flag == 0) {
					next[2][t++][x] = map[y][x];
					target = map[y][x];
					flag = 1;
				}
				else {
					if (target == map[y][x]) next[2][t - 1][x] += target;
					else {
						next[2][t++][x] = map[y][x];
					}
				}
			}
		}
	}
	//아래
	for (int x = 0; x < M; x++) {
		flag = 0;
		t = N - 1;
		for (int y = N - 1; y >= 0; y--) {
			if (map[y][x] > 0) {
				if (flag == 0) {
					next[3][t--][x] = map[y][x];
					target = map[y][x];
					flag = 1;
				}
				else {
					if (target == map[y][x]) next[3][t + 1][x] += target;
					else {
						next[3][t--][x] = map[y][x];
					}
				}
			}
		}
	}
	//회전
	for (int y = 1; y < N; y++) next[4][y - 1][0] = map[y][0];
	for (int x = 1; x < M; x++) next[4][N - 1][x - 1] = map[N - 1][x];
	for (int y = N - 2; y >= 0; y--) next[4][y + 1][M - 1] = map[y][M - 1];
	for (int x = M - 2; x >= 0; x--) next[4][0][x + 1] = map[0][x];
}
int GetMax(int map[20][20])
{
	int max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] > max) max = map[y][x];
		}
	}
	return max;
}
void run(int level, int map[20][20])
{
	if (level == 6) {
		int ret = GetMax(map);
		if (ret > max_result) {
			max_result = ret;
		}
		return;
	}
	int next[5][20][20] = { 0 };
	MakeMap(map, next);
	for (int i = 0; i < 5; i++) {
		run(level + 1, next[i]);
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	Input();
	run(0, input_map);
	cout << max_result;
	return 0;
}
#endif