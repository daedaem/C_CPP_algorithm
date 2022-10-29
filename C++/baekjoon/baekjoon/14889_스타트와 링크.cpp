#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define MAX_N (20)
int N;
int arr[MAX_N + 2][MAX_N + 2];
int teams[MAX_N + 1];
int visit[MAX_N + 1];
set<string> s;
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> arr[r][c];
		}
	}
}
int calc() {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N / 2 && j < N / 2) {
				sum1 += arr[teams[i]][teams[j]];
			}
			else if  (i>=N/2 &&j>=N/2){
				sum2 += arr[teams[i]][teams[j]];
			}
		}
	}
	return abs(sum1 - sum2);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout <<teams[i] << " ";
	}
	cout << '\n';
}

void maketeam2() {
	int idx = N / 2;
	for (int i = 0; i < N; i++) {
		if (!visit[i]) teams[idx++] = i;
	}
}
int result = 0xf777777;

void DFS(int start, int dep) {
	if (dep == N/2) {
		maketeam2();
		//print();
		int temp = calc();
		if (result > temp) result = temp;
		return;
	}
	for (int i = start; i < N; i++) {
		teams[dep] = i;
		visit[i] = 1;
		DFS(i+1, dep + 1);
		visit[i] = 0;
	}
}
void solve() {
	DFS(0, 0);
}
int main(void) {
	freopen("startandlink.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	solve();
	cout << result << '\n';

	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N (20)
int N;
int arr[MAX_N + 2][MAX_N + 2];
vector<int> teamA;
vector<int> teamB;
int visit[MAX_N + 1];
set<string> s;
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> arr[r][c];
		}
	}
}
int calc() {
	int sum1 = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i+1; j < N / 2; j++) {
			sum1 += arr[teamA[i]][teamA[j]];
			sum1 += arr[teamA[j]][teamA[i]];
		}
	}
	int sum2 = 0;

	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			sum2 += arr[teamB[i]][teamB[j]];
			sum2 += arr[teamB[j]][teamB[i]];
		}
	}
	cout << sum1 << " "<< sum2 << '\n';
	return abs(sum1 - sum2);
}
void print() {
	for (int i = 0; i < N; i++) {
		if (i < N / 2) {
			cout << teamA[i] << " ";
		}
		else cout << teamB[i] << " ";
	}
	cout << '\n';
}
bool already_team() {
	string a;
	for (int i = 0; i < N / 2; i++) {
		a += teamA[i] + '0';
	}
	sort(a.begin(), a.end());

	teamB.clear();
	for (int i = 0; i < N; i++) {
		if (!visit[i]) teamB.push_back(i);
	}

	string b;
	for (int i = 0; i < N / 2; i++) {
		b += teamB[i] + '0';
	}
	sort(b.begin(), b.end());

	auto at = s.find(a);
	auto bt = s.find(b);
	if (at != s.end() || bt != s.end()) return true;
	else {
		s.insert(a);
		s.insert(b);
		return false;
	}
}
int result = 0xf777777;

void DFS(int dep) {
	if (dep == N/2) {
		if(already_team()) return;
		print();
		int temp = calc();
		if (result > temp) result = temp;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		teamA.push_back(i);
		visit[i] = 1;
		DFS(dep + 1);
		teamA.pop_back();
		visit[i] = 0;
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	DFS(0);
	cout << result << '\n';

	return 1;
}
#endif