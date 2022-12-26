#if 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int W, H;
struct POS {
	int r, c;
};
struct RB {
	int r, c, cnt;
};
int visit[20 + 1][20 + 1];
POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<string> arr;
vector<POS> dirties;
queue<RB> q;
vector<int>permu;
int memo[20 + 1][20 + 1][20 + 1][20 + 1];
int permuvisit[10];
int SR, SC, maxd;
void init() {
	arr.clear();
	maxd = 0x7fffffff;
	memset(permuvisit, 0, sizeof(permuvisit));
	memset(memo, 0, sizeof(memo));
	permu.clear();
	dirties.clear();
}
void input(int W, int H) {
	arr.resize(H);
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char cc; cin >> cc;
			arr[r].push_back(cc);
			if (arr[r][c] == '*') {
				dirties.push_back({ r,c });
			}
			else if (arr[r][c] == 'o') {
				SR = r;
				SC = c;
			}
		}
	}
}
int BFS(int sr,int sc, int er, int ec) {
	memset(visit, 0, sizeof(visit));
	q = {};
	q.push({ sr,sc,0 });
	visit[sr][sc] = 1;
	while (!q.empty()) {
		RB data = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			RB newdata = data;
			newdata.r += DIR[i].r;
			newdata.c += DIR[i].c;
			newdata.cnt++;
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= H || newdata.c >= W) continue;
			if (arr[newdata.r][newdata.c] == 'x') continue;
			if (visit[newdata.r][newdata.c]) continue;
			//æ∆∑°≤® »Æ¿Œ
			if (newdata.r == er && newdata.c == ec) return newdata.cnt;
			visit[newdata.r][newdata.c] = 1;
			q.push(newdata);
		}
	}
	return -1;
}
void DFS(int dep) {
	if (dep == dirties.size()) {
		int cnt = memo[SR][SC][dirties[permu[0]].r][dirties[permu[0]].c];
		for (int i = 0; i < permu.size() - 1; i++) {
			int sr = dirties[permu[i]].r;
			int sc = dirties[permu[i]].c;
			int er = dirties[permu[i + 1]].r;
			int ec = dirties[permu[i + 1]].c;
			cnt += memo[sr][sc][er][ec];
		}
		if (maxd > cnt) maxd = cnt;
		return;
	}
	for (int i = 0; i < dirties.size(); i++) {
		if (permuvisit[i]) continue;
		permuvisit[i] = 1;
		permu.push_back(i);
		DFS(dep + 1);
		permuvisit[i] = 0;
		permu.pop_back();
	}
}
int makePath() {
	for (int e = 0; e < dirties.size(); e++) {
		int er = dirties[e].r;
		int ec = dirties[e].c;
		int ret = BFS(SR, SC, er, ec);
		if (ret == -1) return 0;
		memo[SR][SC][dirties[e].r][dirties[e].c] = ret;
		memo[dirties[e].r][dirties[e].c][SR][SC] = ret;
	}
	for (int i = 0; i < dirties.size()-1; i++) {
		for (int j = i + 1; j < dirties.size(); j++) {
			if (i == j) continue;
			int sr= dirties[i].r;
			int sc = dirties[i].c;
			int er = dirties[j].r;
			int ec = dirties[j].c;
			int ret = BFS(sr,sc, er, ec);
			if (ret == -1) return 0;
			memo[sr][sc][er][ec] = ret;
			memo[er][ec][sr][sc] = ret;
		}
	}
	return 1;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (1) {
		cin >> W >> H;
		if (!W && !H)break;
		else {
			init();
			input(W, H);
			int ret = makePath();
			if (!ret) {
				cout << -1 << '\n';
			}
			else {
				DFS(0);
				cout << maxd<<'\n';
			}
		}
	}
	return 0;
}

#endif
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//int W, H;
//struct POS {
//	int r, c;
//};
//struct RB {
//	int r, c, cnt, dirty;
//	vector<string> arr;
//};
//int visit[20 + 1][20 + 1];
//POS DIR[] = { {-1,0},{0,1},{1,0},{0,-1} };
//vector<string> arr;
//queue<RB> q;
//int SR, SC;
//void print() {
//	for (int r = 0; r < H; r++) {
//		for (int c=0; c< W; c++){
//			cout << arr[r][c];
//		}
//		cout << '\n';
//	}
//}
//void init() {
//	arr.clear();
//}
//void input(int W, int H) {
//	arr.resize(H);
//	int dirtycnt=0;
//	for (int r = 0; r < H; r++) {
//		for (int c = 0; c < W; c++) {
//			char cc; cin >> cc;
//			arr[r].push_back(cc);
//			if (arr[r][c] == '*') dirtycnt++;
//			else if (arr[r][c] == 'o') {
//				SR = r;
//				SC = c;
//			}
//		}
//	}
//
//	arr[SR][SC] = '.';
//	q = {};
//	q.push({ SR,SC,0, dirtycnt, arr});
//}
//int BFS() {
//	fill(&visit[0][0], &visit[20][20 + 1], 0xf777777);
//	visit[SR][SC] = 0;
//	int maxx = 0xf777777;
//	while (!q.empty()) {
//		RB data = q.front(); q.pop();
//		if (data.cnt >= maxx) continue;
//		for (int i = 0; i < 4; i++) {
//			RB newdata = data;
//			newdata.r += DIR[i].r;
//			newdata.c += DIR[i].c;
//			newdata.cnt++;
//			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= H || newdata.c >= W) continue;
//			if (newdata.arr[newdata.r][newdata.c] == 'x') continue;
//			//æ∆∑°≤® »Æ¿Œ
//			//if (visit[newdata.r][newdata.c] < newdata.cnt) continue;
//			//visit[newdata.r][newdata.c] = newdata.cnt;
//			if (newdata.arr[newdata.r][newdata.c] == '*') {
//				newdata.dirty--;
//				newdata.arr[newdata.r][newdata.c] = '.';
//			}
//			if (!newdata.dirty && maxx > newdata.cnt) {
//				return newdata.cnt;
//			}
//			/*if (!newdata.dirty && maxx > newdata.cnt) {
//				maxx = newdata.cnt;
//
//			}*/
//			q.push(newdata);
//			//cout << "#" << newdata.cnt << '\n';
//			//for (int r = 0; r < H; r++) {
//			//	for (int c = 0; c < W; c++) {
//			//		cout << newdata.arr[r][c] << " ";
//			//	}
//			//	//cout << "        ";
//			//	//for (int c = 0; c < W; c++) {
//			//	//	cout << visit[r][c] << " ";
//			//	//}
//			//	cout << '\n';
//			//}
//		}
//	}
//	//cout << maxx << '\n';
//	return maxx;
//}
//int main(void){
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	while (1) {
//		cin >> W >> H;
//		if (!W && !H)break;
//		else {
//			init();
//			input(W, H);
//			cout << BFS() <<'\n';
//		}
//	}
//	return 0;
//}
