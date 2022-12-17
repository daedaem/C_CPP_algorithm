#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
vector<int> numbers;
int num[4];
void init() {
	numbers.clear();
}
void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		numbers.push_back(n);
	}
	sort(numbers.begin(), numbers.end());
}
void solve() {
	//int val = numbers[0] + numbers[1] + numbers[2];
	int val;
	int sidx = 0;
	int endidx = 2;
	int cnt = 0;
	for (int mid = 1; mid<= N - 1; mid++) {
		val= numbers[mid];
		for (int left = 0; left < mid; left++) {
			val = numbers[mid];
			val += numbers[left];
			int right = mid + 1;
			while (right < N) {
				//cout << numbers[l]<<" "<< numbers[m]<<" "<<numbers[right]<<"\n";
				if (K - val == numbers[right]) cnt++;
				if (val + numbers[right] > K) break;
				right++;
			}
		}
	}
	cout << cnt << '\n';
}
int main(void) {
	freopen("tripplesum.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	return 0;
}