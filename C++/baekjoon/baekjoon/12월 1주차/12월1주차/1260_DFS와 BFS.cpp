#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N (1000)
#define MAX_M (10000)
int N, M, V;
vector<int> adjlist[MAX_N + 1];
int visit[MAX_N + 1];
void DFS(int now) {
	cout << now << " ";
	visit[now] = 1;
	for(int i=0; i<adjlist[now].size(); i++){
		if (visit[adjlist[now][i]]) continue;
		DFS(adjlist[now][i]);
	}
}
int main(void) {
	cin >> N >> M >> V;
	for(int i=0; i<M;i++){
		int a, b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(adjlist[i].begin(), adjlist[i].end());
	}
	DFS(V);
	cout << '\n';
	BFS(V);
	visit[V] = 1;
	return 0;
}