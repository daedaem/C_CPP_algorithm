#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_NM (300)

int record[MAX_NM + 2][MAX_NM + 2];
int maps[MAX_NM + 2][MAX_NM + 2];
int IceGroup[MAX_NM + 2][MAX_NM + 2];
int N, M;
struct POS {
	int r, c;
};
queue<POS>q;
void input(){
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
		}
	}
}
void count_record_Melt(int nr, int nc) {
	static int dr[] = { -1,0,1,0 };
	static int dc[] = { 0,1,0,-1 };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dy = nr + dr[i];
		int dx = nc + dc[i];
		if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
		if (!maps[dy][dx]) cnt++; // ���� �ٴ幰�̸� �ٴ幰 ���� �߰�
	}
	record[nr][nc] = cnt;
}
int meltIce() {
	fill(&record[0][0], &record[MAX_NM + 1][MAX_NM + 2], 0);
	//�ٴ幰 �� ���
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++){
			if (!maps[r][c])continue; // �ش���ġ 0�̸�
			count_record_Melt(r, c); // ���� �ٴ幰 �� ���� ���
		}
	}
	//�ٴ幰 ��ϵȸ�ŭ ����
	int flag = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!record[r][c]) continue;//���δ� �򱼼���
			if (!maps[r][c]) continue;
			maps[r][c] -= record[r][c];
			if (maps[r][c] < 0) maps[r][c] = 0;
			flag = 1;
		}
	}
	return flag;
}
void floodfill(int nr, int nc, int groupcnt) {
	static int dr[] = {-1,0,1,0};
	static int dc[] = {0,1,0,-1};
	q = {};
	q.push({ nr, nc });
	IceGroup[nr][nc] = groupcnt;
	while (!q.empty()) {
		POS data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			POS newdata = data;
			newdata.r += dr[i];
			newdata.c += dc[i];
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= N || newdata.c >= M) continue;
			if (!maps[newdata.r][newdata.c]) continue; // ���� ������ �н�
			if (IceGroup[newdata.r][newdata.c]) continue; //�׷�ٸ��� �н�
			IceGroup[newdata.r][newdata.c] = groupcnt;
			q.push(newdata);
		}
	}
}
int simulation(){
	for (int time = 1; ; time++) {
		int ret = meltIce(); //�ٳ��������� �и� �ȵǸ�
		if (!ret) return 0; // ���� ������ ���� 0�ε��� ���� �ȳ������ϱ� 0����
		//�ѵ������ �־����ٴϱ� ÷���� �䳪���°� �Ű� x

		// ���굢� �� Ȯ��
		int groupcnt = 0;

		fill(&IceGroup[0][0], &IceGroup[MAX_NM + 1][MAX_NM + 2], 0);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (!maps[r][c]) continue;
				if (IceGroup[r][c]) continue;
				groupcnt++;
				if (groupcnt >= 2) return time;
				floodfill(r,c, groupcnt);
			}
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}