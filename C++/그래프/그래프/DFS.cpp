//======================================================================================================
//10819 차이를 최대로 - 백준
//======================================================================================================
#if 1
//왜 32가 나오지
#include <iostream>
using namespace std;
int check[200 + 10];
int arr[200 + 10];
int record[8 + 10];
int N;
int maxx = -101;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}
void DFS(int dep, int summ)
{
	if (dep >= N)
	{
		if (maxx < summ)
		{
			maxx = summ;
		}
		//int tempsum = 0;
		//for (int i = 0; i < N-1; i++) 
		//{
		//	tempsum += abs((record[i]) - (record[i + 1]));
		//}
		//if (maxx < tempsum) 
		//{
		//	maxx = tempsum;
		//}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		int tempsum = 0;
		if (check[i]) continue;
		check[i] = 1;
		record[dep] = arr[i];
		//DFS(dep + 1, 0);

		if (dep >= 1)
		{
			DFS(dep + 1, summ + abs(record[dep - 1] - record[dep]));
		}
		else DFS(dep + 1, summ);

		check[i] = 0;
	}
}
int main()
{
	input();
	DFS(0, 0);
	cout << maxx;
	return 0;
}
#endif