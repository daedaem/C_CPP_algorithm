#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX_RC (20)
struct POS {
	int r, c;
};
struct ST {
	int r, c, d;
};
//POS machineD[][] = { {},{},{},{} };
int R, C, K, W;
int maps[MAX_RC + 2][MAX_RC + 2];
int wind[MAX_RC + 2][MAX_RC + 2];
int tempwind[MAX_RC + 2][MAX_RC + 2];
struct WALL {
	int sr, sc;
	int er, ec;
};
vector<WALL> wall;
vector<ST> machine;
vector<POS> inv;
void init() {
	wall.clear();
	machine.clear();
}
void input() {
	cin >> R >> C >> K;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> maps[r][c];
			if (maps[r][c] && maps[r][c] < 5) {
				machine.push_back({ r,c,maps[r][c] });
				maps[r][c] = 0;
			}
			else if (maps[r][c] == 5) {
				inv.push_back({ r,c });
				maps[r][c] = 0;
			}
		}
	}
	cin >> W;
	for (int i = 0; i < W; i++) {
		int x, y, t; cin >> x >> y >> t;
		if (t == 0) {
			wall.push_back({ x,y,x - 1,y });
		}
		else if (t == 1) {
			wall.push_back({ x,y,x,y + 1 });
		}
	}
}
void print() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int checkall() {
	for (int i = 0; i < inv.size(); i++) {
		if (maps[inv[i].r][inv[i].c] < K) return 0;
	}
	return 1;
}
int findwall(int sr, int sc, int er, int ec) {
	for (int i = 0; i < wall.size(); i++) {
		if (wall[i].sr == sr && wall[i].sc == sc && wall[i].er == er && wall[i].ec == ec) return 1;
		if (wall[i].sr == er && wall[i].sc == ec && wall[i].er == sr && wall[i].ec == sc) return 1;
	}
	return 0;
}
void rightside(int sr, int sc) {
	POS DIR[] = { {0,1},{-1,1},{1,1} };
	queue<ST> q;
	fill(&tempwind[0][0], &tempwind[MAX_RC + 1][MAX_RC + 2], 0);
	q = {};
	tempwind[sr][sc + 1] = 5;
	q.push({ sr,sc + 1,5 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.d == 1) continue;
		for (int idx = 0; idx < 3; idx++) {
			ST newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			newdata.d--;
			if (newdata.r<1 || newdata.c<1 || newdata.r>R || newdata.c>C) continue;
			if (idx == 0) { //��
				int ret = findwall(data.r, data.c, newdata.r, newdata.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 1) { //1��
				if (data.r - 1 < 1) continue;
				if (data.c + 1 > C) continue;
				int ret = findwall(data.r, data.c, data.r - 1, data.c);
				if (ret) continue;
				ret = findwall(data.r - 1, data.c, data.r - 1, data.c + 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 2) {//5��
				if (data.r + 1 > R) continue;
				if (data.c + 1 > C) continue;
				int ret = findwall(data.r + 1, data.c, data.r, data.c);
				if (ret) continue;
				ret = findwall(data.r + 1, data.c, data.r + 1, data.c + 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
		}
	}
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (tempwind[r][c]) maps[r][c] += tempwind[r][c];
		}
	}
}
void leftside(int sr, int sc) {
	POS DIR[] = { {0,-1},{-1,-1},{1,-1} };
	queue<ST> q;
	fill(&tempwind[0][0], &tempwind[MAX_RC + 1][MAX_RC + 2], 0);
	q = {};
	tempwind[sr][sc - 1] = 5;
	q.push({ sr,sc - 1, 5 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.d == 1) continue;
		for (int idx = 0; idx < 3; idx++) {
			ST newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			newdata.d--;
			if (newdata.r<1 || newdata.c<1 || newdata.r>R || newdata.c>C) continue;
			if (idx == 0) { //��
				int ret = findwall(data.r, data.c, newdata.r, newdata.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 1) { //11��
				if (data.r - 1 < 1) continue;
				if (data.c - 1 < 1) continue;
				int ret = findwall(data.r, data.c, data.r - 1, data.c);
				if (ret) continue;
				ret = findwall(data.r - 1, data.c - 1, data.r - 1, data.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 2) {//7��
				if (data.r + 1 > R) continue;
				if (data.c - 1 < 1) continue;
				int ret = findwall(data.r + 1, data.c, data.r, data.c);
				if (ret) continue;
				ret = findwall(data.r + 1, data.c - 1, data.r + 1, data.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
		}
	}
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (tempwind[r][c]) maps[r][c] += tempwind[r][c];
		}
	}
}
void upperside(int sr, int sc) {
	POS DIR[] = { {-1,0},{-1,-1},{-1,1} };
	queue<ST> q;
	fill(&tempwind[0][0], &tempwind[MAX_RC + 1][MAX_RC + 2], 0);
	q = {};
	tempwind[sr - 1][sc] = 5;
	q.push({ sr - 1,sc, 5 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.d == 1) continue;
		for (int idx = 0; idx < 3; idx++) {
			ST newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			newdata.d--;
			if (newdata.r<1 || newdata.c<1 || newdata.r>R || newdata.c>C) continue;
			if (idx == 0) { //��
				int ret = findwall(data.r, data.c, newdata.r, newdata.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 1) { //11��
				if (data.r - 1 < 1) continue;
				if (data.c - 1 < 1) continue;
				int ret = findwall(data.r, data.c - 1, data.r, data.c);
				if (ret) continue;
				ret = findwall(data.r, data.c - 1, data.r - 1, data.c - 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 2) {//1��
				if (data.r - 1 < 1) continue;
				if (data.c + 1 > C) continue;
				int ret = findwall(data.r, data.c, data.r, data.c + 1);
				if (ret) continue;
				ret = findwall(data.r, data.c + 1, data.r - 1, data.c + 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
		}
	}
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (tempwind[r][c]) maps[r][c] += tempwind[r][c];
		}
	}
}
void downside(int sr, int sc) {
	POS DIR[] = { {1,0},{1,-1},{1,1} };
	queue<ST> q;
	fill(&tempwind[0][0], &tempwind[MAX_RC + 1][MAX_RC + 2], 0);
	q = {};
	tempwind[sr + 1][sc] = 5;
	q.push({ sr + 1,sc, 5 });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.d == 1) continue;
		for (int idx = 0; idx < 3; idx++) {
			ST newdata = data;
			newdata.r += DIR[idx].r;
			newdata.c += DIR[idx].c;
			newdata.d--;
			if (newdata.r<1 || newdata.c<1 || newdata.r>R || newdata.c>C) continue;
			if (idx == 0) { //�Ʒ�
				int ret = findwall(data.r, data.c, newdata.r, newdata.c);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 1) { //7��
				if (data.r + 1 > R) continue;
				if (data.c - 1 < 1) continue;
				int ret = findwall(data.r, data.c - 1, data.r, data.c);
				if (ret) continue;
				ret = findwall(data.r + 1, data.c - 1, data.r, data.c - 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
			else if (idx == 2) {//5��
				if (data.r + 1 > R) continue;
				if (data.c + 1 > C) continue;
				int ret = findwall(data.r, data.c, data.r, data.c + 1);
				if (ret) continue;
				ret = findwall(data.r + 1, data.c + 1, data.r, data.c + 1);
				if (ret) continue;
				tempwind[newdata.r][newdata.c] = newdata.d;
				q.push(newdata);
			}
		}
	}
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (tempwind[r][c]) maps[r][c] += tempwind[r][c];
		}
	}
}
void machinewind() {
	for (int i = 0; i < machine.size(); i++) {
		//cout << "## " << chocolate;

		if (machine[i].d == 1) rightside(machine[i].r, machine[i].c);
		else if (machine[i].d == 2) leftside(machine[i].r, machine[i].c);
		else if (machine[i].d == 3) upperside(machine[i].r, machine[i].c);
		else if (machine[i].d == 4) downside(machine[i].r, machine[i].c);

	}
	//for (int r = 1; r <= R; r++) {
	//	for (int c = 1; c <= C; c++) {
	//		maps[r][c] += wind[r][c];
	//	}
	//}
}
void degreecontrol() {
	POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
	int controlmap[MAX_RC + 2][MAX_RC + 2];
	fill(&controlmap[0][0], &controlmap[MAX_RC + 1][MAX_RC + 2], 0);
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			for (int idx = 0; idx < 4; idx++) {
				int dy = r + DIR[idx].r;
				int dx = c + DIR[idx].c;
				if (dy<1 || dx<1 || dy>R || dx>C) continue;
				int ret = findwall(r, c, dy, dx);
				if (ret) continue;
				if (maps[r][c] > maps[dy][dx]) {
					int ret = (maps[r][c] - maps[dy][dx]) / 4;
					controlmap[r][c] -= ret;
				}
				else if (maps[r][c] < maps[dy][dx]) {
					int ret = (maps[dy][dx] - maps[r][c]) / 4;
					controlmap[r][c] += ret;
				}
			}
		}
	}
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			maps[r][c] += controlmap[r][c];
		}
	}
}
void sidedecline() {
	for (int r = 1; r <= R; r++) {
		if (maps[r][1]) maps[r][1]--;
		if (maps[r][C]) maps[r][C]--;
	}
	// 0�̶� �� ���� ������ ó����
	for (int c = 2; c < C; c++) {
		if (maps[1][c])maps[1][c]--;
		if (maps[R][c])maps[R][c]--;
	}
}
int solve() {
	//fill(&wind[0][0], &wind[MAX_RC + 1][MAX_RC + 2], 0);
	int chocolate = 0;
	//��ǳ�� ���ÿ� �ٳ���
	// �ʾ�����Ʈ
	//�µ�����
	//�µ� 1�̻� ���� �ٱ�ĭ �µ� 1�� ����
	// ���ݸ�++;
	// ��� ĭ �µ� k�̻����� �˻�
	while (chocolate < 101) { //////////////////////
	//while (chocolate < 1) { //////////////////////
		//cout << "======="<< chocolate<<'\n';

		machinewind();

		/*cout << "before\n";
		print();*/
		degreecontrol();
		//cout << "after\n";
		//print();

		sidedecline();

		chocolate++;
		//print();
		if (chocolate > 100) return 101;
		int ret = checkall();

		if (ret) return chocolate;
	}
	return chocolate;
}
int main(void) {
	freopen("23289_hellohotmachine.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	input();
	int ret = solve();
	cout << ret << '\n';

}