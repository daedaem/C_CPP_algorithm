#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, T, N;
vector<int> lines;
struct AN {
	int c, dir;
};
int dc[] = { -1,1 };
vector<AN> ant;
void input() {
	cin >> L >> T >> N;
	lines.resize(L);
	ant.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> ant[i].c;
		char cc; cin >> cc;
		if (cc = 'L') ant[i].dir = 0;
		else ant[i].dir = 1;
	}
}
void calc(int aidx) {
	int c = ant[aidx].c;
	int dir = ant[aidx].dir;
	if (!dir) {
		
	}
	else {
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		calc(i);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();

	return 0;
}