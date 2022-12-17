#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N (12)

int arr[MAX_N * 2 + 1];
int visit[MAX_N * 2 + 1];

vector<int> numbers;
set<vector<int> > S;

int N, x, y, fixnumber, cnt;

void input() {
	cin >> N;
	cin >> x >> y;
}
int findnumber(int start, int end) {
	int numb = end - start - 1;
	return numb;
}
void print(){
	for(int i=1;i<=2*N;i++){
		cout << arr[i] << " ";
	}
	cout << '\n';
}
int check() {
	for (int i = 1; i <= 2 * N; i++) {
		if (!arr[i]) return 0;
	}
	return 1;
}
void DFS(int dep) {
	if (dep > 2* N) {
		if (check()) {
			print();
			cnt++;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		//�̹� üũ�ȰŸ� 
		if (arr[dep]) {
			DFS(dep + 1);
			return;
		}
		//�ȵȰŸ�
		else {
			// ������ ���� �� �Ÿ���ŭ �ڳ༮�̳Ѿ�� �ȵǴϱ�

			// �տ��� ���ڰ� �Է¾ȵȳ༮�� �־��ַ����ϴµ� �̹� �װŸ���ŭ �ڿ� ������ ���� �ȵǴϱ�
			if(arr[dep + i + 1]) continue;

			//���ڰ� �ΰ����ۿ� �Ⱦ��̴ϱ�
			if (visit[i]) continue; 
			visit[i] = 1;
			arr[dep] = i;
			arr[dep + i + 1] = i;
			DFS(dep + 1);
			visit[i] = 0;
			arr[dep] = 0;
			arr[dep + i + 1] = 0;
		}
	}
	return;
}
void solve() {
	if (y < x) swap(x, y);
	//�����Ŵϱ� �ȿ� ĭ��Ȯ���ϸ� Ȯ����
	int ret = findnumber(x, y);
	arr[x] = arr[y] = ret;
	visit[ret] = 1;
	DFS(1);

	cout << cnt << '\n';
}
int main(void) {
	freopen("15198.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
}