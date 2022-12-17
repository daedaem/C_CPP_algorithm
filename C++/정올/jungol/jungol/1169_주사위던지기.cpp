#include <iostream>
using namespace std;
int N, M;
int arr[6];
int visit[7];
void M1(int dep) {
	if (dep > N) {
		for (int i = 1; i <= N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= 6; i++) {
		arr[dep] = i;
		M1(dep + 1);
		arr[dep] = 0;
	}
}
void M2(int dep, int start) {
	if (dep > N) {
		for (int i = 1; i <= N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= 6; i++) {
		arr[dep] = i;
		M2(dep + 1, i);
		arr[dep] = 0;
	}
}
void M3(int dep) {
	if (dep > N) {
		for (int i = 1; i <= N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		arr[dep] = i;
		M3(dep + 1);
		visit[i] = 0;
		arr[dep] = 0;
		
	}
}
void solve() {
	if (M == 1) {
		M1(1);
	}
	else if (M == 2) {
		M2(1, 1);
	}
	else {
		M3(1);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;	
	solve();
	return 0;
}