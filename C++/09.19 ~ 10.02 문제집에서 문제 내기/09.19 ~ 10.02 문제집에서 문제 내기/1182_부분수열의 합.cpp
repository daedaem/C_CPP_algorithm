#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, S;
vector<int> arr;
vector<int> record;
void input()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		int nn; cin >> nn;
		arr.push_back(nn);
	}
}
int cnt = 0;
void DFS(int dep, int start, int sum)
{
	for (int i = 0; i <record.size(); i++) 
	{
		cout << record[i] << " ";
	}
	cout << '\n';
	if (sum == S && dep != 0)
	{
		cnt++;
	}
	for (int i = start; i < N; i++)
	{
		record.push_back(arr[i]);
		DFS(dep + 1, i + 1, sum + arr[i]);
		record.pop_back();
	}
}
int main(void)
{
	input();
	DFS(0, 0, 0);
	cout << cnt;
	return 0;
}