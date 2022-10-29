#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N, M;
unordered_map<int,int> Scard;
vector<int> numbers;
void input() 
{
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int nn; cin >> nn;
		auto it = Scard.find(nn);
		if (it != Scard.end()) it->second += 1;
		else Scard.insert({ nn,1 });
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int nn; cin >> nn;
		numbers.push_back(nn);
	}
}
void solve() 
{
	for (int i = 0; i < M; i++) 
	{
		int findnumber = numbers[i];
		auto it = Scard.find(findnumber);
		if (it != Scard.end()) cout << it->second << " ";
		else cout << 0 << " ";
	}
}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	solve();
	return 0;
}	