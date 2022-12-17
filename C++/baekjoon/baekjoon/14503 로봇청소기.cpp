#if 1
#include <iostream>
using namespace std;
#define MAX_NM (50)
struct RB {
	int r, c, dir;
}robot;
struct POS {
	int r, c;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int revd[] = { 2,3,0,1 };
int N, M, result;
int maps[MAX_NM + 2][MAX_NM + 2];
void input() {
	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.dir;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
		}
	}
}
int check() {
	for (int i = 1; i < 4; i++) { // ��������� ���ʺ��� ����
		int newd = robot.dir - 1 * i;
		if (newd < 0) newd = (robot.dir + 4) - (1 * i);//���� ������
		int dy = robot.r + D[newd].r;
		int dx = robot.c + D[newd].c;
		if (!maps[dy][dx]) return 1;
	}
	return 0;
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << '\n';
		}
		cout << '\n';
	}cout << '\n';
}
int rotates() {
	for (int i = 1; i <= 4; i++) { // ��������� ���ʺ��� ����
		int newd = robot.dir - 1 * i;
		if (newd < 0) newd = (robot.dir + 4) - (1 * i);//���� ������
		int dy = robot.r + D[newd].r;
		int dx = robot.c + D[newd].c;
		if (!maps[dy][dx]) {
			robot.dir = newd;
			robot.r = dy;
			robot.c = dx;
			return 1;
		}
	}
	return 0;
}
int simulation() {
	int result = 0;
	for (;;) {
		//1 ������ġ û��
		if (!maps[robot.r][robot.c]) {
			maps[robot.r][robot.c] = 2;
			result++;
		}
		
		int ret = rotates();//ȸ���غ���
		if (!ret) { // 4���� �� �� ����
			int opd = revd[robot.dir];
			int dy = robot.r + D[opd].r;
			int dx = robot.c + D[opd].c; 
			if (maps[dy][dx]==1) {//���� ���ʵ� ���̶� ���� ���ϸ�
				break; // 2-4 �۵������
			}
			else { // ��ĭ ����
				robot.r = dy;
				robot.c = dx;
				continue;
			}
		}
	}
	return result;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
}
#endif
#if 0
#include <iostream>
using namespace std;
#define MAX_NM (50)
struct RB {
	int r, c, dir;
}robot;
struct POS {
	int r, c;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int revd[] = {2,3,0,1};
int N, M, result;
int maps[MAX_NM + 2][MAX_NM + 2];
void input(){
	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.dir;
	for(int r=0;r<N;r++){
		for (int c = 0; c < M; c++) {
			cin >> maps[r][c];
		}
	}
}
int check(){
	for (int i = 1; i < 4; i++) { // ��������� ���ʺ��� ����
		int newd = robot.dir - 1 * i;
		if (newd < 0) newd = (robot.dir + 4) - (1 * i);//���� ������
		int dy = robot.r + D[newd].r;
		int dx = robot.c + D[newd].c;
		if (!maps[dy][dx]) return 1;
	}
	return 0;
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << maps[r][c] << '\n';
		}
		cout << '\n';
	}cout << '\n';
}
int search(int d) {
	int cnt = 0;
	int flag = 0;
	if (check()) {
		for (int i = 1; i < 4; i++) { // ��������� ���ʺ��� ����
			int newd = d - 1 * i;
			if (newd < 0) newd = (d + 4) - (1 * i);//���� ������
			int dy = robot.r + D[newd].r;
			int dx = robot.c + D[newd].c;
			if (!maps[dy][dx]) {
				robot.dir = newd;
				robot.r = dy;
				robot.c = dx;
				return 1;
			}
			else {//û�Ұ����� ���ų� ���̸�
				robot.dir = newd; // �׹������� ȸ���ϰ�
				search(newd); //2������ ���ư���.
				//�׷��� �ȵǸ�2-3
			}
		}
	}
	else {
		if (!cnt) {
			int opd = revd[robot.dir];
			int dy = robot.r + D[opd].r;
			int dx = robot.c + D[opd].c;
			if (maps[dy][dx]) return 0; // 2-4 �۵������
			robot.r = dy;
			robot.c = dx;
			search(robot.dir);
		}
	}
	return 0;
}
int simulation() {
	for (;;) {
		//1 ������ġ û��
		if (!maps[robot.r][robot.c]) {
			maps[robot.r][robot.c] = 1;
			result++;
		}
		//�������˷��ֱ�
		for (int i = 1; i < 4; i++) { // ��������� ���ʺ��� ����
			int newd = robot.dir - 1 * i;
			if (newd < 0) newd = (robot.dir+ 4) - (1 * i);//���� ������
			int dy = robot.r + D[newd].r;
			int dx = robot.c + D[newd].c;
			if (!maps[dy][dx]) {
				robot.dir = newd;
				robot.r = dy;
				robot.c = dx;
				continue;
			}
		}
		if(!search(robot.dir)) break;
	}
	return result;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
}
#endif