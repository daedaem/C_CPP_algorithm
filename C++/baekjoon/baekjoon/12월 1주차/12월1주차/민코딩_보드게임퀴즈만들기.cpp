#if 0 // 강사님 코드
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MOD 1000000007; 
using namespace std;
// S : 시작
// E : 도착
// R : 찬스 -> 횟수 카운팅 안함
// # : 기둥
// . : 일반 길 
int T;
int H, W;
int MAP[300][300];
int visited[300][300];
int dist[300][300];
int sy, sx; // 시작 좌표
int ty, tx; // 타겟 좌표
// 방향 배열
int ydir[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int xdir[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
struct Node {
	int y, x, dist;
};
bool operator < (Node left, Node right) {
	// 온 경로가 짧은것 우선
	if (left.dist < right.dist)
		return false;
	if (left.dist > right.dist)
		return true;
	// 더 멀리 돌아가는 것 우선
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
			// 범위 체크
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)
				continue;
			// 벽이면 못간다
			if (MAP[ny][nx] == -1)
				continue;
			// 찬스 -> 찬스면 횟수 늘릴 필요 없음
			// 다른 경우의 수로 찬스칸에 온 것만 확인
			if (MAP[ny][nx] == 0 && MAP[now.y][now.x] == 0)
				continue;
			int nextcost = dist[now.y][now.x] + MAP[ny][nx];
			// (ny,nx)까지 가는 길을 더 짧은 것을 찾았다면
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