#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[5][5];
int answer[5][5] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
int backup[5][5];
int nowarr[5][5];
int comb[10];
struct POS {
	int type, idx, d;
};
vector<POS> v;
void print() {
	for (int r = 0; r < 4; r++) {
		for (int c =0; c < 4; c++) {
			cout << nowarr[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void input() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr[r][c];
			nowarr[r][c] = arr[r][c];
		}
	}
}
void move(int rc, int idx, int rep) {
	int rowcol[5] = {0,0,0,0,0};
	if (rc == 2) { // 행바꾸기
		for (int i = 0; i < 4; i++) {
			int dy = i + rep;
			if (dy > 3) dy -= 4;
			rowcol[dy]= nowarr[i][idx];
		}
		for (int i = 0; i < 4; i++) {
			nowarr[i][idx] = rowcol[i];
		}
	}
	else if (rc==1){
		for (int i = 0; i < 4; i++) {
			int dx = i + rep;
			if (dx > 3) dx -= 4;
			rowcol[dx] = nowarr[idx][i];
		}
		for (int i = 0; i < 4; i++) {
			nowarr[idx][i] = rowcol[i];
		}
	}
}
int check() {
	copy(&arr[0][0], &arr[4][5], &nowarr[0][0]);
	for (int i = 0; i < 8; i++) {
		if (comb[i]) {
			if (i > 3) move(1, i-4, comb[i]);
			else move(2, i, comb[i]);
		}
	}
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (nowarr[r][c] != answer[r][c]) return 0;
		}
	}
	return 1;
}
int check() {
	copy(&arr[0][0], &arr[4][5], &nowarr[0][0]);
	for (int i = 0; i < 8; i++) {
		if (comb[i]) {
			if (i > 3) move(1, i - 4, comb[i]);
			else move(2, i, comb[i]);
		}
	}

	return 1;
}
int maxx = 0xf777777;
void DFS(int lev,int sum) {
	if (sum>7) return;
	if (lev == 8) {
		int ret = check();
		int ret2 = check2();
		if (!ret && ret2!) return;
		print();
		/*for (int i = 0; i < 8; i++) {
			cout << comb[i] << " ";
		}
		cout << '\n';*/
		if (maxx > sum) {
			maxx = sum;
			v.clear();
			for (int i =0; i < 8; i++) {
				if (comb[i]) {
					if (i >3) {
						v.push_back({ 1, i+1 - 4, comb[i] });
					}
					else {
						v.push_back({ 2, i+1, comb[i] });
					}
				}
			}
		}
		return;
	}
	for(int i = 0; i <=3; i++) {
		comb[lev] = i;
		DFS(lev + 1, i);
	}
}
int main(void) {
	freopen("rubicsqure.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	DFS(0,0);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].type << " " << v[i].idx << " " << v[i].d << '\n';
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[5][5];
int backup[5][5];
int nowarr[5][5];
struct POS {
	int type,r, c, d;
};
vector<POS> v;
void input(){
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr[r][c];
			nowarr[r][c]= arr[r][c];
		}
	}
}
int check() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (nowarr[r][c] != arr[r][c]) return 0;
		}
	}
	return 1;
}
void DFS(int lev, int sr, int sc) {
	if (check()) return;
	int backup[5][5];
	copy(&nowarr[0][0], &nowarr[4][5], &backup[0][0]);
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (lev < 2) v.push_back({ r, c, levl });
			copy(&backup[0][0], &backup[4][5], &nowarr[0][0]);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (lev < 2) v.push_back({ 0, i, sc });
		DFS(lev+1);
		copy(&backup[0][0], &backup[4][5], &nowarr[0][0]);
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	DFS(0);
	return 0;
}
#endif