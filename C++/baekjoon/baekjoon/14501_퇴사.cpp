#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N (15)
using namespace std;
int N, maxx;
vector<int> days;
vector<int> costs;
int dp[MAX_N + 2];
void input() 
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int d, cost; cin >> d >> cost;
		days.push_back(d);
		costs.push_back(cost);
	}
}
void solve() 
{
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = max(maxx, dp[i]);
		int nextd = i + days[i];
		if (nextd <= N) {
			dp[nextd] = max(dp[nextd], dp[i] + costs[i]);
		}
		maxx = max(maxx, dp[i]);
	}
	cout << maxx;
}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	solve();
	return 0;
}
#endif

#if 1
#include <iostream>
#include <vector>
using namespace  std;
int N, maxx;
vector<int> days;
vector<int> costs;
void input() 
{
	cin >> N;
	days.push_back(0);
	costs.push_back(0);
	for (int i = 1; i <= N; i++) {
		int d, cost; cin >> d >> cost;
		days.push_back(d);
		costs.push_back(cost);
	}
}
void DFS(int nowday, int costsum)
{
	if (nowday > N) {
		if (maxx < costsum) maxx = costsum;
		return;
	}
	if (nowday + days[nowday] <= N+1) DFS(nowday + days[nowday], costsum + costs[nowday]);
	DFS(nowday + 1, costsum);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	DFS(1, 0);
	cout << maxx << '\n';
	return 0;
}
#endif