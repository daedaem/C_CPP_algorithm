//==================================슬라이딩 윈도우===================================================
//---------------------------------------------------------------------------------
//12847 - 꿀 아르바이트
//---------------------------------------------------------------------------------
#if 0
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> arr(100'000 + 10, 0);
void input(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
long long solve(void)
{
	long long summ = 0;
	long long maxx = 0;
	//일할 수 있는 날이 없으면
	if (m == 0) return 0;

	for (int i = 0; i < m; i++)
	{
		summ += arr[i];
		maxx = summ;
	}
	for (int i = m; i < n; i++)
	{
		summ -= arr[(i - m)];
		summ += arr[i];
		if (maxx < summ) maxx = summ;
	}
	return maxx;
}
int main(void)
{

	input();
	long long result = solve();
	cout << result;
	return 0;
}
#endif