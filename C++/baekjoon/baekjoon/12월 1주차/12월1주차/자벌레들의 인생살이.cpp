#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define MAX_N (10)
#define MAX_RC (5)
int N, K;
struct BG {
	int r, c, d, nowe;
	int dir; // 1이면 앞으로 -1 뒤로
	bool alive;
};
struct POS {
	int r, c;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int revd[] = { 2,3,0,1 };
BG bugs[MAX_N + 2];
int maps[MAX_RC + 2][MAX_RC + 2];
void input() {
	cin >>N >> K;
	for (int i = 1; i <= N; i++) {
		int r, c, d,dir; cin >> r >> c >> d;
		if (r == 0) {
			dir = 0;
			r = 5 - r;
		}
		else if (c == 0) {
			dir = 1;
			r = 5 - r;
		}
		bugs[i] = { r,c,d,d,dir,true };
		maps[r][c] = i;
	}
}
void print() {
	for (int r = 0; r <= 5; r++) {
		for (int c = 0; c <= 5; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void moving(int bidx) {
	BG data= bugs[bidx];
	maps[data.r][data.c] = 0;
	
	bugs[bidx].nowe--;

	bugs[bidx].r += D[data.dir].r;
	bugs[bidx].c += D[data.dir].c;
	if (bugs[bidx].nowe == 0) {
		bugs[bidx].dir = revd[bugs[bidx].dir];
		bugs[bidx].nowe = bugs[bidx].d;
	}
}
void mapupdate() {
	set<int>erase;
	for (int i = 1; i <= N; i++) {
		if (!bugs[i].alive) continue;
		if (maps[bugs[i].r][bugs[i].c]) {
			int id = maps[bugs[i].r][bugs[i].c];
			erase.insert(id);
			erase.insert(i);
		}
		else {
			maps[bugs[i].r][bugs[i].c] = i;
		}
	}
	auto it = erase.begin();
	while (it != erase.end()) {
		int idx = *it;
		bugs[idx].alive = false;
		maps[bugs[idx].r][bugs[idx].c] = 0;
		it++;
	}
}
void solve() {
		//print();
	for (int time = 1; time <= K; time++) {
		for (int i = 1; i <= N; i++) {
			if (!bugs[i].alive) continue;
			moving(i);
		}
		mapupdate();
		//print();
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (bugs[i].alive) result++;
	}
	cout << result <<"마리" <<'\n';
}
int main(void) {
	freopen("jabugs.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define MAX_N (10)
#define MAX_RC (5)
int N, K;
struct BG {
	int r, c, d, nowe;
	int dir; // 1이면 앞으로 -1 뒤로
	bool alive;
};
struct POS {
	int r, c;
};
POS D[] = { {-1,0},{0,1},{1,0},{0,-1} };
int revd[] = { 2,3,0,1 };
BG bugs[MAX_N + 1];
int maps[MAX_RC + 1][MAX_RC + 1];
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int r, c, d, dir; cin >> r >> c >> d;
		if (r == 0) {
			dir = 2;
		}
		else if (c == 0) {
			dir = 1;
		}
		bugs[i] = { r,c,d,d,dir,true };
		maps[r][c] = i;
	}
}
void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
}
void moving(int bidx) {
	BG data = bugs[bidx];
	maps[data.r][data.c] = 0;

	data.r = bugs[bidx].r;
	data.c = bugs[bidx].c;
	data.d = bugs[bidx].d;
	data.nowe = bugs[bidx].nowe;
	data.dir = bugs[bidx].dir;
	data.nowe--;
	data.r += D[data.dir].r;
	data.c += D[data.dir].c;
	if (data.nowe == 0) {
		data.dir = revd[data.dir];
		data.nowe = data.d;
	}
	bugs[bidx] = data;
}
void mapupdate() {
	//set <int> erase;
	for (int i = 1; i <= N; i++) {
		if (!bugs[i].alive) continue;
		if (maps[bugs[i].r][bugs[i].c]) {
			int id = maps[bugs[i].r][bugs[i].c];
			/*	erase.insert(id);
				erase.insert(i);*/
			bugs[i].alive = false;
			bugs[id].alive = false;
			maps[bugs[i].r][bugs[i].c] = 0;
		}
		else {
			maps[bugs[i].r][bugs[i].c] = i;
		}
	}
	//auto it = erase.begin();
	//while (it != erase.end()) {
	//	int idx = *it;
	//	bugs[idx].alive = false;
	//	if (maps[bugs[idx].r][bugs[idx].c]) {
	//		maps[bugs[idx].r][bugs[idx].c] = 0;
	//	}
	//	it++;
	//}
}
void solve() {
	for (int time = 1; time <= K; time++) {
		for (int i = 1; i <= N; i++) {
			if (!bugs[i].alive) continue;
			moving(i);
		}
		mapupdate();
		print();
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (bugs[i].alive) result++;
	}
	cout << result << "마리" << '\n';
}
int main(void) {
	freopen("jabugs.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}
#endif