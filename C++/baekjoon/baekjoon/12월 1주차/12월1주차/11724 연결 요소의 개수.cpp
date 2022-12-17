#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> adjlist[1000 + 1];
int visit[1000 + 1];
void DFS(int now) {
	visit[now] = 1;
	for(int i=0; i< adjlist[now].size();i++){
		int next = adjlist[now][i];
		if (visit[next]) continue;
		DFS(next);
	}
}
int main(void){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a, b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		cnt++;
		DFS(i);
	}
	cout << cnt;
	return 0;
}