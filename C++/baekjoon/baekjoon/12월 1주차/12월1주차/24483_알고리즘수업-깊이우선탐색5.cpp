#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN (100000)
int N, M, R;
vector<int> adj[MAXN + 1];
long long dep[MAXN + 1];
long long order[MAXN + 1];
long long cnt;
void DFS(long long node, long long lev){
	order[node] = ++cnt;
	dep[node] = lev;
	for(int i=0; i<adj[node].size(); i++){
		int next = adj[node][i];
		if (order[next])continue;
		DFS(next, lev + 1);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M >> R;
	for(int i=0; i< M;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(R, 1);
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		/*cout << dep[i] - 1 << " " << order[i] << '\n';*/
		result += ((dep[i]-1) * order[i]);
	}
	cout << result;
	return 0;
}
