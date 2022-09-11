//=================================================================================
// 1753 - 최단 경로
//=================================================================================
#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF ((int)1e9)
using namespace std;
int V, E, K;
vector<pair<int, int>> arr[20000 + 10];
int D[20000 + 10];
priority_queue<pair<int, int>> pq;
void input(void)
{
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		arr[u].push_back({ w, v });
	}
}
void init(void)
{
	for (int i = 1; i <= V; i++)
	{
		D[i] = INF;
	}
}
void dijkstra(int start)
{
	D[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int nowvalue = -(pq.top().first);
		int nowpos = pq.top().second;
		pq.pop();

		if (D[nowpos] < nowvalue) continue;
		int lens = arr[nowpos].size();
		for (int i = 0; i < lens; i++)
		{
			int nextvalue = arr[nowpos][i].first;
			int next = arr[nowpos][i].second;

			if ((nextvalue + nowvalue) < D[next])
			{
				D[next] = nextvalue + nowvalue;
				pq.push({ -D[next], next });
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (D[i] == (int)INF)
		{
			cout << "INF" << '\n';
		}
		else cout << D[i] << '\n';
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	init();
	dijkstra(K);
	return 0;
}

#endif

//=================================================================================
// 18352 - 특정 거리의 도시 찾기
//=================================================================================
#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF (int)1e9
using namespace std;

int N, M, K, X;
vector<pair<int, int>> arr[300000 + 10];
priority_queue<pair<int, int>> pq;
int D[300000 + 10] = { 0 };
void input(void)
{
	memset(arr, 0, sizeof(arr));
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		int start, to; cin >> start >> to;
		arr[start].push_back({ 1, to });
	}
}
void init(void)
{
	//거리정보 초기화
	for (int i = 1; i <= N; i++)
	{
		D[i] = INF;
	}
}
void dijkstra(int start)
{
	D[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int current_value = -(pq.top().first);
		int current_position = pq.top().second;
		pq.pop();
		if (D[current_position] < current_value) continue;
		int lens = arr[current_position].size();
		for (int i = 0; i < lens; i++)
		{
			int destination_value = arr[current_position][i].first;
			int destination_position = arr[current_position][i].second;

			if (D[destination_position] > current_value + destination_value)
			{
				D[destination_position] = current_value + destination_value;
				pq.push({ -(D[destination_position]), destination_position });
			}
		}
	}
	int isk = false;
	for (int i = 1; i <= N; i++)
	{
		if (D[i] == K)
		{
			cout << i << '\n';
			isk = true;
		}
	}
	if (!isk) cout << -1;

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	init();
	dijkstra(X);
	return 0;
}
#endif

//======================================================================================================
// 1916 - 촤소비용 구하기
//======================================================================================================
#if 0
#include <iostream>
#include<vector>
#include<queue>
#define INF 1E9
int N, M;
int start, destination;
std::vector<std::pair<int, int>> arr[1000 + 10];
int d[1000 + 10];
void input(void)
{
	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, value;
		std::cin >> from >> to >> value;
		arr[from].push_back({ value,to });
	}
	std::cin >> start >> destination;
}
void distance_init()
{
	for (int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
}
void dijkstra(int ST)
{
	d[ST] = 0;
	std::priority_queue<std::pair<int, int>> PQ;
	PQ.push({ 0,ST });
	while (!(PQ.empty()))
	{
		int c_cost = -PQ.top().first;
		int c = PQ.top().second;
		PQ.pop();

		if (d[c] < c_cost) continue;
		for (int i = 0; i < arr[c].size(); i++)
		{
			int n_cost = arr[c][i].first;
			int next = arr[c][i].second;
			if (d[next] > n_cost + c_cost)
			{
				d[next] = n_cost + c_cost;
				PQ.push({ -d[next], next });
			}
		}
	}
}
void solve(void)
{
	dijkstra(start);
	std::cout << d[destination];
}
int main()
{
	input();
	distance_init();
	solve();
}
#endif


//======================================================================================================
// 4485 - 녹색 옷 입은 애가 젤다지
//======================================================================================================
#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF (int)(1e9)
using namespace std;
int N;
int cnt = 1;
vector<std::vector<int>> arr(125 + 10, vector<int>(125 + 10));
vector<std::vector<int>>d(125 + 10, vector<int>(125 + 10));
int visited[125 + 10][125 + 10];
int Y[] = { 0, 1, 0 ,-1 };
int X[] = { 1, 0,-1,0 };

void input(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int numb;
			cin >> numb;
			arr[i][j] = numb;
		}
	}
}
void init(void)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			arr[i][j] = 0;
			d[i][j] = INF;
			visited[i][j] = 0;
		}
	}
}
void solve(void)
{
	priority_queue<std::vector<int>> PQ;
	d[0][0] = arr[0][0];
	PQ.push({ arr[0][0] ,0, 0, });
	while (!(PQ.empty()))
	{
		int currentY = PQ.top()[1];
		int currentX = PQ.top()[2];
		int current_cost = d[currentY][currentX];
		PQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int dy = currentY + Y[i];
			int dx = currentX + X[i];
			if (dy<0 || dx<0 || dy>N - 1 || dx>N - 1) continue;
			if (d[dy][dx] < current_cost) continue;
			if (d[dy][dx] > arr[dy][dx] + current_cost)
			{
				d[dy][dx] = arr[dy][dx] + current_cost;
				PQ.push({ -d[dy][dx],dy, dx });
			}
		}
	}
	cout << "Problem " << cnt << ": " << d[N - 1][N - 1] << '\n';
	cnt++;

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		cin >> N;

		if (N == 0) break;
		init();
		input();
		solve();
	}
}
#endif