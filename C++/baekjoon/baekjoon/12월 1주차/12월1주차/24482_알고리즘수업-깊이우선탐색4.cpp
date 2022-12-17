#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N (100000)
int N, M, R;
vector<int> adj[MAX_N+1];
int depth[MAX_N + 1];
void DFS(int node, int lev) {
	depth[node] = lev;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (depth[next]) continue;
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
	for (int i = 1; i <= N; i++) {
		cout << depth[i] -1<< '\n';
	}
	return 0;
}
