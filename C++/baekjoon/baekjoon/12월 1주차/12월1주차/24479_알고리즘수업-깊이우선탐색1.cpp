#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R, cnt;
vector<int> adjlist[100000 + 1];
int visit[100000 + 1];
void DFS(int node) {
	visit[node] = ++cnt;
	for (int i = 0; i < adjlist[node].size(); i++) {
		int next = adjlist[node][i];
		if (visit[next]) continue;
		DFS(next);
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M >> R;
	for(int i=0; i<M;i++){
		int a, b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (adjlist[i].empty()) continue;
		sort(adjlist[i].begin(), adjlist[i].end());
	}
	DFS(R);
	for (int i = 1; i <= N; i++) {
		cout << visit[i] << '\n';
	}
	return 0;
}
