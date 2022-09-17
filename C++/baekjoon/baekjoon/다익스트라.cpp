//=================================================================================
// 1753 - �ִ� ���
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
// 18352 - Ư�� �Ÿ��� ���� ã��
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
	//�Ÿ����� �ʱ�ȭ
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
// 1916 - �ҼҺ�� ���ϱ�
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
// 4485 - ��� �� ���� �ְ� ������
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

//----------------------------------------------------------------------------
// ���ͽ�Ʈ�� �˰��� ���� ����
//------------------------------------------------------------------------------
// ���ͽ�Ʈ�� ����
//------------------------------------------------------------------------------
#if 0
#include<cstdio>
#include<iostream>
int number = 6;
int INF = 10e9;
int arr[6][6] = {
	{0, 2, 5, 1, INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0},
};
bool visit[6];
int distance[6];
int getSmallIndex()
{
	int min = INF;
	int idx = 0;
	for (int i = 0; i < number; i++)
	{
		if (distance[i] < min && !visit[i])
		{
			min = distance[i];
			idx = i;
		}
	}
	return idx;
}

void dijkstra(int start)
{
	for (int i = 0; i < number; i++)
	{
		distance[i] = arr[start][i];
	}
	visit[start] = true;
	for (int i = 0; i < number - 2; i++)
	{
		int current = getSmallIndex();
		visit[current] = true;
		for (int j = 0; j < 6; j++)
		{
			if (!visit[j])
			{
				if (distance[current] + arr[current][j] < distance[j])
				{
					distance[j] = distance[current] + arr[current][j];
				}
			}
		}
	}
}
int main(void)
{

	dijkstra(0);
	for (auto i : distance)
	{
		std::cout << i << ' ';
	}


}
#endif 

#if 0
#include <stdio.h>

#define N 100
#define INF 100000

int map[N + 1][N + 1];
int visit[N + 1];
int dist[N + 1];
int vertex;
int edge;
int start;
int end;

void dijkstra(void)
{
	int i;
	int j;
	int min;
	int v;

	dist[start] = 0;

	for (i = 1; i <= vertex; i++)
	{
		min = INF;

		for (j = 1; j <= vertex; j++)
		{
			if (visit[j] == 0 && min > dist[j])
			{
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;

		for (j = 1; j <= vertex; j++)
		{
			if (dist[j] > dist[v] + map[v][j])
			{
				dist[j] = dist[v] + map[v][j];
			}
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	int i;
	int j;
	int from;
	int to;
	int value;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d %d", &vertex, &start, &end);
		scanf("%d", &edge);

		for (i = 1; i <= vertex; i++)
		{
			for (j = 1; j <= vertex; j++)
			{
				if (i != j)
				{
					map[i][j] = INF;
				}
			}
		}

		for (i = 1; i <= edge; i++)
		{
			scanf("%d %d %d", &from, &to, &value);
			map[from][to] = value;
		}

		for (i = 1; i <= vertex; i++)
		{
			dist[i] = INF;
			visit[i] = 0;
		}

		printf("#%d ", test_case);
		dijkstra();
		printf("%d \n", dist[end]);
	}
	return 0;
}
#endif
//------------------------------------------------------------------------------
// 18352 Ư�� �Ÿ��� ���� ã��
//------------------------------------------------------------------------------
#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
int V, E, K;
// ������ �Է�
std::vector<std::pair <int, int>> arr[20000 + 10];
int distance[20000 + 10];

// �Է� �ޱ�
void input()
{
	std::cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int from, to, value;
		std::cin >> from >> to >> value;
		// 1���� 2�������� 3�ɸ��� from 1, to 2, 3 value
		arr[from].push_back({ value,  to });
	}
}
void distance_Init(void)
{
	//memset(distance, INF, sizeof(distance));
	// �湮 �ִ밪���� �ʱ�ȭ
	for (int i = 1; i <= V; i++)
	{
		distance[i] = INF;
	}
}
void dijkstra(int start)
{
	// �켱���� ť
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, start });
	distance[start] = 0;
	while (!pq.empty())
	{
		int cur_cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (distance[current] < cur_cost) continue;
		int lens = arr[current].size();
		for (int i = 0; i < lens; i++)
		{
			int next_cost = arr[current][i].first;
			int next = arr[current][i].second;

			if (distance[next] > next_cost + cur_cost)
			{
				distance[next] = next_cost + cur_cost;
				pq.push({ -distance[next] , next });
			}
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	distance_Init();
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF)
		{
			std::cout << "INF" << '\n';
		}
		else
		{
			std::cout << distance[i] << '\n';
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include<cstring>
#include <vector>
#define INF (10e8)
using std::cout;
using std::cin;

int N, M, K, X;
void input()
{
	cin >> N >> M >> K >> X;
	//2���� �迭 ����
	int **arr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++) {
		arr[i] = new int[N + 1];
		//0���� �ʱ�ȭ
		memset(arr[i], 0, sizeof(int)*(N + 1));
	}
	//visited �迭
	int *visited = new int[N + 1];
	memset(visited, 0, sizeof(int)*(N + 1));

	// �迭 �� ��� INF�� �Ҵ�
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			arr[r][c] = INF;
		}
	}
	//�迭 �����
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
	}
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << std::endl;
	}
	//�迭 �Ҵ�����
	//for (int i = 0; i < N + 1; i++) {
	//	delete [] arr[i];
	//}

}
int main()
{
	input();
	for (int i = 0; i < N + 1; i++)
	{
		for (int c = 0; c < N + 1; c++)
		{
			cout << arr[i][c] << " ";
		}
		cout << arr[i][c] << " ";
	}

	//std::vector<vector<int>> arr;




}
#endif

//------------------------------------------------------------------------------
// 18352- Ư�� �Ÿ��� ���� ã��
//------------------------------------------------------------------------------
#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
int N, M, K, X;
std::vector<std::pair<int, int>> arr[300000 + 10];
int d[300000 + 10];
void input(void)
{
	std::cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		std::cin >> from >> to;
		arr[from].push_back({ 1, to });
	}
}
void distance_init(void)
{
	for (int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
}
void dijkstra(int start)
{
	d[start] = 0;
	std::priority_queue<std::pair<int, int>> PQ;
	PQ.push({ 0,start });

	while (!(PQ.empty()))
	{
		int c_cost = -PQ.top().first;
		int current = PQ.top().second;
		PQ.pop();
		if (d[current] < c_cost) continue;
		for (int i = 0; i < arr[current].size(); i++)
		{
			int n_cost = arr[current][i].first;
			int next = arr[current][i].second;
			if (d[next] > n_cost + d[current])
			{
				d[next] = n_cost + d[current];
				PQ.push({ -d[next], next });
			}
		}
	}
}
int solve(void)
{
	dijkstra(X);
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == K)	return 1;
	}
	return 0;
}

int main(void)
{
	input();
	distance_init();
	if (solve())
	{
		for (int i = 1; i <= N; i++)
		{
			if (d[i] == K) std::cout << i << '\n';
		}
	}
	else
	{
		std::cout << -1;
	}
	return 0;
}
#endif

//------------------------------------------------------------------------------
// 1916 - �ּҺ�� ���ϱ�
//------------------------------------------------------------------------------
#if 0
#include <iostream>
#include<vector>
#include<queue>
#define INF 10E9
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

//------------------------------------------------------------------------------
// 4485 -��� �� ���� �ְ� ������?
//------------------------------------------------------------------------------
#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF (1e9)
int N;
int cnt = 1;
std::vector<std::vector<int>> arr(125 + 10, std::vector<int>(125 + 10));
//std::vector<std::vector<int>> arr(125+10);
std::vector<std::vector<int>>d(125 + 10, std::vector<int>(125 + 10));
int visited[125 + 10][125 + 10];
//std::vector<int> arr(3);
int Y[] = { 0, 1, 0 ,-1 };
int X[] = { 1, 0,-1,0 };

void input(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int numb;
			std::cin >> numb;
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
	std::priority_queue<std::vector<int>> PQ;
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
	std::cout << "Problem " << cnt << ": " << d[N - 1][N - 1] << '\n';
	cnt++;

}
int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	while (1)
	{
		std::cin >> N;

		if (N == 0) break;
		init();
		input();
		solve();
	}
}
#endif

