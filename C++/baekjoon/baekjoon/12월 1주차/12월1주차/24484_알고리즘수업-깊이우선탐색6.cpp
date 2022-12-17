#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN (100000)
vector<int> adj[MAXN + 1];
int dep[MAXN + 1];
long long order[MAXN + 1];
int N, M, R;
long long cnt = 0;
void DFS(int node, int lev) {
	order[node] = ++cnt;
	dep[node] = lev;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (dep[next]) continue;
		DFS(next, lev + 1);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end(), greater<int>());
	}
	DFS(R, 1);
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		result += (order[i] * (dep[i] - 1));
	}
	cout << result;
	return 0;
}
