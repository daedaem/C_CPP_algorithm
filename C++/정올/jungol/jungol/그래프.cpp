// used[i] =0 지우는게 없으면 "모든 노트 탐색"
// used[i] =0 지우는게 있으면 "모든 경로를 탐색"
// 기본기 연습
// 1. 인접행렬
//2. 인접행렬 기본 DFS
//3 0번에서 3번까지 가는 경로의 수 구하기
//4. used[i] =0 있고 없고 차이 이해하기
//5. 0에서 3번까지 가는데 가중치그래프, 최소비용구하기
// 다익스트라인지 dfs인지 구별하는 쉬운 구분방법
// N값으로 다익스트라는 1000정도까지, dfs는 7까지
#if 1
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Node {
	int n;
	int price;
};
vector<vector<Node>> alist(4);
int used[10];
int cnt = 0;
void run(int now, int sum) {
	//cout << now;
	if (now == 3) {
		cout << sum << "\n";
		cnt++;
		return;
	}

	for (int i = 0; i < alist[now].size(); i++) {
		Node next = alist[now][i];
		if (used[next.n] == 1) continue;
		used[next.n] = 1;
		run(next.n, sum + next.price);
		used[next.n] = 0;
	}
}
int main() {
	alist[0] = { {1, 4}, {2, 1}, {3, 15} };
	alist[1] = { {3, 5} };
	alist[2] = { {3, 2} };
	used[0] = 1;
	run(0, 0);
	cout << cnt;
	return 0;
}
#endif
//인접행렬
#if 0
#include <iostream>
using namespace std;
int arr[4][4] = {
	0,1,1,1,
	0,0,1,1,
	0,0,0,1,
	0,0,0,0,
};
int used[10];
int cnt = 0;
int path[10];
void run(int now) {
	if (now == 3) {
		cnt++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		path[now] = i;
		run(i);
		//used[i] = 0;
	}
}
int main() {
	used[0] = 1;
	run(0);
	cout << cnt;
	return 0;
}
#endif

//인접리스트
#if 0
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> alist(4);
int used[10];
int cnt = 0;
void run(int now) {
	//cout << now;
	if (now == 3) {
		cnt++;
		return;
	}

	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		run(next);
		used[next] = 0;
	}
}
int main() {
	alist[0] = { 1, 2, 3 };
	alist[1] = { 3 };
	alist[2] = { 3 };
	used[0] = 1;
	run(0);
	cout << cnt;
	return 0;
}
#endif