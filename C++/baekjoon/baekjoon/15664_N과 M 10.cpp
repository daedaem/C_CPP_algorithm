#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NM (8)
using namespace std;
vector<int> arr;
bool check[MAX_NM + 1];
vector<int> arr2;
int N, M;
int start;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int cc; cin >> cc;
		arr.push_back(cc);
	}
	sort(arr.begin(), arr.end());
}
void print() {
	for (int r = 0; r < M; r++) {
		cout << arr2[r] << " ";
	} cout << '\n';
}
void DFS(int start, int dep) {
	if (dep == M) {
		print();
		return;
	}
	int before=0;
	for (int i = start; i < N; i++) {
		if (before == arr[i]) continue;
		before = arr[i];
		arr2.push_back(arr[i]);
		DFS(i + 1, dep + 1);
		arr2.pop_back();
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	DFS(0, 0);
}
#endif

#if 0
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_NM (8)
using namespace std;
vector<int> arr;
map<int,string> numbers;
vector<int>arr2;
int N, M;
int start;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int c; cin >> c;
		arr.push_back(c);
	}
	sort(arr.begin(), arr.end());
}
void makestring() {
	string a;
	for (int i = 0; i < arr2.size(); i++) {
		a += to_string(arr2[i])+",";
	}
	auto it = numbers.begin();
	while (it != numbers.end()) {
		if (it->second == a) {
			break;
		}
		it++;
	}
	if (it == numbers.end()) {
		numbers.insert({ start++,a });
	}
}
void print() {
	for (auto str:numbers) {
		for (auto c : str.second) {
			if (c == ',') cout << " ";
			else cout << c;
		}cout << '\n';
	}

}
void DFS(int start, int dep) {
	if (dep == M) {
		makestring();
		return;
	}
	for (int i = start; i < N; i++) {
		arr2.push_back(arr[i]);
		DFS(i + 1, dep + 1);
		arr2.pop_back();
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	DFS(0, 0);
	print();
}
#endif