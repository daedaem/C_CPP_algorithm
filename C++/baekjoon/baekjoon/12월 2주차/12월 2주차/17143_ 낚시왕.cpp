#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_RC (100)

struct POS {
	int r, c;
};
POS DIR[] = { {0,0}, {-1,0},{1,0},{0,1}, {0,-1} };
struct SHK {
	int r, c, s, dir, z;
	bool alive;
};
vector<SHK> sharks;
int maps[MAX_RC + 2][MAX_RC + 2];
void init() {
	memset(maps, 0, sizeof(maps));
	sharks.clear();
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
	}
	return 0;
}