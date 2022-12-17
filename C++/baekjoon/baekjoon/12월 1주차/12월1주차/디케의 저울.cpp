
#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, Q;
vector<int> weight;
vector<int>question;
set<vector<int>> vs;
vector<int>A;
vector<int>B;
int visit[21][200001];
set<int> s;
void init() {
	weight.clear();
	question.clear();
	//totalweight = 0;
//	for (int i = 0; i < 21; i++) {
		s.clear();
//	}
}
void input() {
	cin >> N;
	weight.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
		//s.insert(weight[i]);
		//s.insert(totalweight);
	}
	sort(weight.begin(), weight.end());
	cin >> Q;
	question.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> question[i];
	}
}
void print() {
	cout << "===================\n";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << " ";
	}
	cout << '\n';
}
void DFS(int dep, int sum) {
	if (dep > N) {
		return;
	}
	//print();
	//if (s.find(bsum) != s.end()) return;
	if (visit[dep][sum]) return;
	visit[dep][sum] = 1;
	s.insert(sum);
	//for (int i = 0; i < N; i++) {
		//if (visit[i]) continue;	
			//visit[i] = 1;
			//A.push_back(i);
	DFS(dep + 1, sum);
	DFS(dep + 1, sum+weight[dep]);
	DFS(dep + 1, abs(sum-weight[dep]));
			//A.pop_back();
			//visit[i] = 1;
			////A.push_back(i);
			//DFS(asum, bsum,cnt);
			////A.pop_back();
			//visit[i] = 0;
		//}
	//}
}
void solve() {
	int cnt = 0;
	DFS(0, 0);
	for (int i = 0; i < Q; i++) {
		auto it = s.find(question[i]);
		if (it != s.end()) {
			cout << *it << '\n';
			cnt++;
			break;
		}
	}
	//auto it = s.begin();
	//while (it != s.end()) {
	//	cout << *it << " ";
	//	it++;
	//}
	cout << cnt << '\n';
}
int main(void) {
	freopen("dikesScale.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();

	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, Q;
vector<int> weight;
vector<int>question;
int totalweight;
set<int> s;
void init() {
	weight.clear();
	question.clear();
	totalweight = 0;
	s.clear();
}
void input() {
	cin >> N;
	weight.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
		s.insert(weight[i]);
		totalweight += weight[i];
		s.insert(totalweight);
	}
	cin >> Q;
	question.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> question[i];
	}
}
void DFS(int dep, int start, long long remainW, long long sums) {
	s.insert(remainW);
	s.insert(abs(remainW - sums));
	s.insert(sums);
	if (dep == N) {
		return;
	}
	for (int i = start; i < N; i++) {
		DFS(dep + 1, i + 1, totalweight - weight[i], sums + weight[i]);
	}
}
void solve() {
	int cnt = 0;
	DFS(0, 0, totalweight, 0);
	for (int i = 0; i < Q; i++) {
		auto it = s.find(question[i]);
		if (it != s.end()) cnt++;
	}
	cout << cnt << '\n';
}
int main(void) {
	freopen("dikesScale.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();

	return 0;
}
#endif