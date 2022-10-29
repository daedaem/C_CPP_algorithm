#if 0
#include <iostream>
#include <queue>
using namespace std;
#define MAX 0x7fffffff
int can_go, N;
// 거리 값
int distance_info[100 + 10];
// 정비하는데 걸리는 시간 들
int jungbi_time[100 + 10];
// 방문 하는 곳 해당 값이 인덱스의 부모
int path[100 + 10];
// 걸리는 시간
int T[100 + 10];
int D[100 + 10];
struct STATUS
{
	// 합계
	int chargeTime;
	int placeN;
	//int cnt;
};
queue<STATUS> Q;
void input(void)
{
	cin >> can_go >> N;
	int sum = 0;
	for (int i = 1; i <= N + 1; i++)
	{
		cin >> distance_info[i];
		sum += distance_info[i];
		D[i] = sum;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> jungbi_time[i];
	}
	for (int i = 1; i <= N + 1; i++)
	{
		T[i] = MAX;
	}
	//for (int i = 1; i <= N + 1; i++) 
	//{
	//  cout << D[i] << " ";
	//} cout << '\n';
	//
}
void BFS(void)
{
	T[0] = 0;
	//int result = 0;
	//차지타임, 포지션
	Q.push({ 0, 0 });
	while (!Q.empty())
	{
		STATUS DATA = Q.front(); Q.pop();
		for (int i = DATA.placeN + 1; i <= N + 1; i++)
		{
			STATUS ndata;
			// 남은 에너지로 갈 수 없으면 끝내기
			if (D[i] - D[DATA.placeN] > can_go) break;
			ndata.chargeTime = T[DATA.placeN] + jungbi_time[i];
			if (T[i] > ndata.chargeTime)
			{
				T[i] = ndata.chargeTime;
				ndata.placeN = i;
				path[i] = DATA.placeN;
				Q.push(ndata);
			}
		}
	}
}

int print_jungbi(int end, int cnt)
{
	if (end == 0)
	{
		cout << cnt << '\n';
		return 1;
	}
	else print_jungbi(path[end], cnt + 1);
	cout << end << " ";
	return 0;
}
int main(void)
{
	input();
	BFS();
	cout << T[N + 1] << '\n';
	if (T[N + 1] != 0)
	{
		// 항상 최종이 N번을 들렸을거라고 착각
		print_jungbi(path[N + 1], 0);
	}
	else cout << 0;
	//해당 지점에서 140이내 갈 수 있는지 체크해보고 
	// 여기서부터 작성
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int maxD, s_cnt;
int tostationD[100+1];
int station[100+1];
int check[100 + 1];
int totalD;
int record[100 + 1];
struct edge 
{
	int now,t, remain;
};
queue<edge> q;
void input() 
{
	cin >> maxD >> s_cnt;
	for (int i = 1; i <= s_cnt + 1; i++) 
	{
		cin >> tostationD[i];
		totalD += tostationD[i];
	}
	for (int i = 1; i <= s_cnt; i++) 
	{
		cin >> station[i];
	}
}
void init() 
{
	for (int i = 1; i <= s_cnt+1; i++) 
	{
		check[i] = 0xf777777;
	}
}
void BFS() 
{
	q = {};
	q.push({ 0,0,140 });
	check[0] = 0;
	while (!q.empty())
	{
		edge data = q.front(); q.pop();
		for (int i = data.now + 1; i <= s_cnt + 1; i++) 
		{
			edge newdata=data;
			newdata.now += 1;
			if (tostationD[newdata.now]) break;
			newdata.t =check[data.now]+ station[data.now];
			if (check[newdata.now] < newdata.t) continue;
			newdata.remain = maxD - tostationD[newdata.now];
			if (check[newdata.now] > newdata.t) 
			{
				check[newdata.now] = newdata.t;
				record[newdata.now] = data.now;
				q.push(newdata);
			}
		}

	}

	for(int i=0; i<=s_cnt+1; i++) {
		cout << record[i] << " ";
	}

}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	init();
	if (totalD <= maxD) cout << 0;
	else BFS();
	return 0;
}
#endif