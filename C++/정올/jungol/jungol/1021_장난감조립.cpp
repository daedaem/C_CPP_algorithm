100점 #6343792

서브태스크 #1AC13ms1468KB

코드 복사하기
#include <iostream>
#include <vector>
using namespace std;

int sums[100 + 1];
vector<int> v[100 + 1];
int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, k; cin >> x >> y >> k;
		for (int j = 0; j < k; j++) {
			v[x].push_back(y);
		}
	}
}
void DFS(int now) {
	if (v[now].empty()) {
		sums[now] += 1;
		return;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		DFS(next);
	}
}
void solve() {
	DFS(N);
	for (int i = 1; i < N; i++) {
		if (sums[i]) cout << i << " " << sums[i] << '\n';
	}
}
int main(void) {
	input();
	solve();
	return 0;
}