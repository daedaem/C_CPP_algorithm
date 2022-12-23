#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long  N, K;
vector<long long > arr;
int find(int lens) {
	long long  cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += (arr[i] / lens);
	}
	if (cnt >= K) return 1;
	else return 0;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	arr.resize(N);
	long long  maxx = 0;
	long long  minn = 1;
	long long  mid;
	long long  maxlen = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		maxx = max(maxx, arr[i]);
	}
	while (minn <= maxx) {
		mid = (maxx + minn) / 2;
		int ret = find(mid);
		if (ret) {
			if (mid > maxlen) maxlen = mid;
			minn = mid + 1;
		}
		else maxx = mid - 1;
	}
	cout << maxlen;
	return 0;
}