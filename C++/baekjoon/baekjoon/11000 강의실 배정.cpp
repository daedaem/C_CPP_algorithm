#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
struct CS {
	int s, t;
};
vector<CS> classtime;
priority_queue<int, vector<int>, greater<int>> endtimes;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, t; cin >> s >> t;
		classtime.push_back({ s,t });
	}
}
bool COMP(CS a, CS b) {
	if (a.s == b.s) {
		return a.t < b.t;
	}
	return a.s < b.s;
}
int solve() {
	sort(classtime.begin(), classtime.end(), COMP);
	endtimes.push(classtime[0].t);
	for (int i = 1; i < classtime.size(); i++) {
		if (endtimes.top() <= classtime[i].s) {
			endtimes.pop();
		}
		endtimes.push(classtime[i].t);
	}
	return endtimes.size();
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << solve() << '\n';	
}