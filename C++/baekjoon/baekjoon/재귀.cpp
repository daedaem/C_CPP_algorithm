//======================================================================================================
//15649 - N引 M 1
//======================================================================================================
#if 0
#include <iostream>
using namespace std;
int N, M;
int arr[8 + 2];
int visit[8 + 2];
void dfs(int dep)
{
	if (dep > M)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		arr[dep] = i;
		dfs(dep + 1);
		visit[i] = 0;
	}
}
int main(void)
{
	cin >> N >> M;
	dfs(1);
	return 0;
}
#endif

//======================================================================================================
//15650 - N引 M 2
//======================================================================================================
#if 0
#include <iostream>
using namespace std;
int N, M;
int arr[8 + 2];
void dfs(int dep, int idx)
{
	if (dep > M)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		arr[dep] = i;
		dfs(dep + 1, i + 1);
	}
}
int main(void)
{
	cin >> N >> M;
	dfs(1, 1);
	return 0;
}
#endif

//======================================================================================================
//15651 - N引 M 3
//======================================================================================================
#if 0
#include <iostream>
using namespace std;
int N, M;
int arr[8 + 2];
void dfs(int dep)
{
	if (dep == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[dep] = i;
		dfs(dep + 1);
	}
}
int main(void)
{
	cin >> N >> M;
	dfs(0);
	return 0;
}
#endif

//======================================================================================================
//15652 - N引 M 4
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> arr;
void dfs(int dep, int start) 
{
	if (dep >= M) 
	{
		for (int i = 0; i < arr.size(); i++) 
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= N; i++) 
	{
		arr.push_back(i);
		dfs(dep + 1, i);
		arr.pop_back();
	}
}
int main(void)
{
	cin >> N >> M;
	dfs(0, 1);
	return 0;
}
#endif

//======================================================================================================
//15654 - N引 M 5
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, M;
vector<int> arr;
int numbers[8 + 1];
unordered_set<int> visit;
void dfs(int dep)
{
	if (dep >= M)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		auto it = visit.find(numbers[i]);
		if (it != visit.end()) continue;
		arr.push_back(numbers[i]);
		visit.insert(numbers[i]);
		dfs(dep + 1);
		arr.pop_back();
		auto cc = visit.find(numbers[i]);
		visit.erase(cc);
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
	dfs(0);
	return 0;
}
#endif

//======================================================================================================
//15655 - N引 M 6
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, M;
vector<int> arr;
int numbers[8 + 1];
void dfs(int dep, int start)
{
	if (dep >= M)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < N; i++)
	{
		arr.push_back(numbers[i]);
		dfs(dep + 1, i + 1);
		arr.pop_back();
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
	dfs(0, 0);
	return 0;
}
#endif

//======================================================================================================
//15656 - N引 M 7
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, M;
vector<int> arr;
int numbers[8 + 1];
void dfs(int dep)
{
	if (dep >= M)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr.push_back(numbers[i]);
		dfs(dep + 1);
		arr.pop_back();
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
	dfs(0);
	return 0;
}
#endif

//======================================================================================================
//15657 - N引 M 8
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, M;
vector<int> arr;
int numbers[8 + 1];
void dfs(int dep, int start)
{
	if (dep >= M)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < N; i++)
	{
		arr.push_back(numbers[i]);
		dfs(dep + 1, i);
		arr.pop_back();
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
	dfs(0, 0);
	return 0;
}
#endif

//======================================================================================================
//15663 - N引 M 9
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
int N, M;
vector<int> arr;
int numbers[8 + 1];
int visit[8 + 1];
unordered_set<string> stvisit;
string makestr() 
{
	string temp;
	for (int i = 0; i < M; i++)
	{
		temp += arr[i];
	}
	return temp;
}
void dfs(int dep)
{
	if (dep >= M)
	{
		string temp = makestr();
		auto it = stvisit.find(temp);
		if (it != stvisit.end())
		{
			return;
		}
		stvisit.insert(temp);
		for (int i = 0; i < M; i++) 
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i]) continue;
		arr.push_back(numbers[i]);
		visit[i] = 1;
		dfs(dep + 1);
		visit[i] = 0;
		arr.pop_back();
		
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
	dfs(0);
	return 0;
}
#endif

//======================================================================================================
//15664 - N引 M 10
//======================================================================================================
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<int> result;
int N, M;
void input() 
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
	{
		int zz; cin >> zz;
		arr.push_back(zz);
	}
}
void dfs(int dep, int start) 
{
	if (dep >= M) 
	{
		for (int i = 0; i < M; i++) 
		{
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	int last = arr[dep - 1];;
	for (int i = start; i < N; i++) 
	{
		result.push_back(arr[i]);
		dfs(dep + 1, i+1);
		result.pop_back();
	}
}
int main(void)
{
	input();
	sort(arr.begin(), arr.end());
	dfs(0,0);
	return 0;
}
#endif

//======================================================================================================
//15665 - N引 M 11
//======================================================================================================
#if 0
#include <iostream>
using namespace std;
int main(void)
{
	return 0;
}
#endif
//======================================================================================================
//15666 - N引 M 12
//======================================================================================================
#if 0
#include <iostream>
using namespace std;
int main(void)
{
	return 0;
}
#endif


