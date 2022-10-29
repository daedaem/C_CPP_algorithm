#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct peo 
{
	int n, cnt;
};
vector<peo> people[100000 + 1];
int prai[100000 + 1];
int visit[100000 + 1];
void input() 
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		int boss; cin >> boss;
		if (boss == -1) continue;
		people[boss].push_back({ i,0 });
	}
	for (int i = 0; i < m; i++) 
	{
		int a, b; cin >> a >> b;
		prai[a] += b;
	}
}

void DFS(int node, int sum) 
{
	visit[node] += sum;
	for (int i = 0; i < people[node].size(); i++) 
	{
		int next = people[node][i].n;
		DFS(next, sum + prai[next]);
	}
}
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	DFS(1, 0);
	for (int i = 1; i <= n; i++) 
	{
		cout << visit[i] << " ";
	}
	return 0;
}