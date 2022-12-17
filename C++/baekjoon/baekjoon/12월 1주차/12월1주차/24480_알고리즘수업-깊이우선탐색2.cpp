#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N (100000)

int N, M, R;
vector<int> adj[MAX_N + 1];
int vis[MAX_N + 1];

int cnt = 0;
void DFS(int node){
	vis[node] = ++cnt;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (vis[next]) continue;
		DFS(next);
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

	DFS(R);
	for (int i = 1; i <= N; i++) {
		cout << vis[i] << "\n";
	}

	return 0;
}
