#include <iostream>
using namespace std;
int N, P;
long long visit[100];
void DFS(int num) {
	int result = num * N % P;
	if (visit[result] > 2) return;
	visit[result]++;
	DFS(result);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> P;
	DFS(N);
	int cnt = 0;
	for (int i = 0; i <= P; i++) {
		if (visit[i] > 1) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}