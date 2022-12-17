#include <iostream>
using namespace std;

int N, M;
int arr[10];
void input() {
	cin >> N >> M;
}
void DFS(int dep, int sum) {
	if (dep == N ) {
		if (sum == M) {
			for (int i = 0; i < N; i++) {
				cout << arr[i] << " ";
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= 6; i++) {
		arr[dep] = i;
		//if (dep == N - 1 && i + sum != M) continue;
		DFS(dep + 1, sum + i);
	}
}
void solve() {
	DFS(0, 0);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}