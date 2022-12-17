#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N (100000)
int visit[MAX_N + 1];
vector<int> adj[MAX_N + 1];
int N, M, R;
void DFS(int node, int start) {
	visit[node] = start;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (visit[next]) continue;
		DFS(next, start + 1);
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
		sort(adj[i].begin(), adj[i].end());
	}
	//fill(&visit[1], &visit[N + 1], 0);
	DFS(R, 1);
	for (int i = 1; i <= N; i++) {
		cout << visit[i] - 1 << '\n';
	}

	return 0;
}
