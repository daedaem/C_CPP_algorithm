#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> adjlist[100 + 1];
int visit[100 + 1];
int cnt;
void DFS(int now) {
	for(int i=0; i<adjlist[now].size();i++){
		if (visit[adjlist[now][i]]) continue;
		visit[adjlist[now][i]] = 1;
		cnt++;
		DFS(adjlist[now][i]);
	}
}
int main(void){
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	cnt = 0;
	visit[1] = 1;
	DFS(1);
	cout << cnt;
}
