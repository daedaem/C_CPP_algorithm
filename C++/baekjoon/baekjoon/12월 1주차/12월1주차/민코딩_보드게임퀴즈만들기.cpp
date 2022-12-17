#if 0 // ����� �ڵ�
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MOD 1000000007; 
using namespace std;
// S : ����
// E : ����
// R : ���� -> Ƚ�� ī���� ����
// # : ���
// . : �Ϲ� �� 
int T;
int H, W;
int MAP[300][300];
int visited[300][300];
int dist[300][300];
int sy, sx; // ���� ��ǥ
int ty, tx; // Ÿ�� ��ǥ
// ���� �迭
int ydir[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int xdir[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
struct Node {
	int y, x, dist;
};
bool operator < (Node left, Node right) {
	// �� ��ΰ� ª���� �켱
	if (left.dist < right.dist)
		return false;
	if (left.dist > right.dist)
		return true;
	// �� �ָ� ���ư��� �� �켱
	if (MAP[left.y][left.x] > MAP[right.y][right.x])
		return false;
	if (MAP[left.y][left.x] < MAP[right.y][right.x])
		return true;
	return false;
}
void solve(int y, int x, int testcase) {
	priority_queue<Node>pq;
	pq.push({ y, x, 0 });
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			dist[i][j] = 21e8;
	visited[y][x] = 1;
	dist[y][x] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.y == ty && now.x == tx)
			break;
		for (int i = 0; i < 8; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			// ���� üũ
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)
				continue;
			// ���̸� ������
			if (MAP[ny][nx] == -1)
				continue;
			// ���� -> ������ Ƚ�� �ø� �ʿ� ����
			// �ٸ� ����� ���� ����ĭ�� �� �͸� Ȯ��
			if (MAP[ny][nx] == 0 && MAP[now.y][now.x] == 0)
				continue;
			int nextcost = dist[now.y][now.x] + MAP[ny][nx];
			// (ny,nx)���� ���� ���� �� ª�� ���� ã�Ҵٸ�
			if (dist[ny][nx] > nextcost) {
				dist[ny][nx] = nextcost;
				visited[ny][nx] = visited[now.y][now.x];
				pq.push({ ny, nx, nextcost });
			}
			else if (dist[ny][nx] == nextcost) {
				visited[ny][nx] += visited[now.y][now.x];
				visited[ny][nx] %= MOD;
			}
		}
	}
	if (visited[ty][tx] == 0)
		cout << "#" << testcase << " -1\n";
	else
		cout << "#" << testcase << " " << dist[ty][tx] << " " << visited[ty][tx] << '\n';
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// reset
		memset(MAP, 0, sizeof(MAP));
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		// input
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < W; j++) {
				if (temp[j] == 'S') {
					MAP[i][j] = 1;
					sy = i; sx = j;
				}
				if (temp[j] == 'E') {
					MAP[i][j] = 1;
					ty = i; tx = j;
				}
				if (temp[j] == '#') MAP[i][j] = -1;
				if (temp[j] == 'R') MAP[i][j] = 0;
				if (temp[j] == '.') MAP[i][j] = 1;
			}
		}
		// solve
		solve(sy, sx, t);
	}
}
#endif