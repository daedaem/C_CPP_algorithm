#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N (8)

struct POS {
	int r, c;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
char maps[MAX_N + 1][MAX_N + 1];

int SR, SC;
int AR, AC;
void input(){
	for (int r = 0; r < MAX_N; r++) {
		for (int c = 0; c < MAX_N; c++) {
			cin >> maps[r][c];
		}
	}
	SR = MAX_N - 1, SC = 0;
	AR = 0, AC = MAX_N - 1;
}
int solve() {
	for (int time = 1; time < 8; time++) {
	//시간난중에 브레이크
		ukjemove();
		if (SR == AR && SC == AC) return 1;
	}
	return 0;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	cout << solve() << '\n';
	return 0;

}