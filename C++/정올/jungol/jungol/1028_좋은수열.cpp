#include <iostream>
using namespace std;
int N, arr[80+1];
int check(int len, int dep) {
	for (int i = 1; i <= len; i++) {
		//����
		for (int j = 0; j+2*i<=dep; j++) {
			int cnt = 0;
			for (int k = 0; k < i; k++) {
				if (arr[j+k] == arr[j+k+i]) cnt++;
			}
			if (cnt == i) return 0;
		}
	}
	return 1;
}
int DFS(int dep) {
	for (int c = 1; c <= dep/2; c++) {
		int ret = check(c, dep);
		if(!ret) return 0;
	}
	if (dep == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i];
		}
		cout << '\n';
		return 1;
	}
	for (int i = 1; i <= 3; i++) {
		arr[dep] = i;
		int ret = DFS(dep + 1);
		if (ret) {
			return 1;
		}
	}
	return 0;
}
int main(void) {
	cin >> N;
	DFS(0);
	return 0;
}