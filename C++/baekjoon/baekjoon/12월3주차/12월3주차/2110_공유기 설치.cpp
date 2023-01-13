#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long C, N;
vector<int> ac;
vector<long long> arr;
void input() {
	cin >> N >> C;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
}
long long findNumber(long long start, long long end, long long value) {
	int cnt = 1;
	long long now = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] >= now + value) {
			cnt++;
			now = arr[i];
		}
	}
	if (cnt >= C) return 1;
	else return 0;
}
void solve() {
	long long start = 1;
	long long end = arr[arr.size() - 1];
	/*long long lens = end - start;
	long long rep = lens / (C - 1);*/
	long long maxxlen = 0;
	while (start<=end) {
		long long mid = (start + end) / 2;
		int ret = findNumber(start, end, mid);
		if (ret) {
			if (maxxlen < mid) maxxlen = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << maxxlen;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	return 0;
}
