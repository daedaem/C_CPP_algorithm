//================================================================================================================
//14249 - 점프 점프
//================================================================================================================
#if 0
#include<iostream>
using namespace std;
int n, s;
int arr[100'000];

void input_data(void) 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
	}
	cin >> s;
}
int main(void) 
{
	input_data();
	solve();
	return 0;
}
#endif

//================================================================================================================
//1679 - 숨바꼭질
//================================================================================================================
#if 0
#include <iostream>
#include <queue>
using namespace std;
int N, K;
int arr[200000 + 10];
int X[] = {-1,1};
int visited[200000 + 10];
struct POS
{
	int pos;
	int time;
};
queue<POS> Q;
void input(void) 
{
	cin >> N >> K;
};
int BFS(void) 
{
	if (N == K) return 0;
	Q.push({ N,0 });
	while (!Q.empty()) 
	{
		POS now = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++) 
		{
			POS temp;
			if (i < 2) 
			{
				temp.pos = now.pos + X[i];
			}
			else 
			{
				temp.pos = now.pos * 2;
			}
			temp.time= now.time + 1;
			if (temp.pos < 0)continue;
			if (temp.pos >100000) continue;
			if (visited[temp.pos]) continue;
			if (temp.pos == K) return temp.time;
			Q.push(temp);
			visited[temp.pos] = 1;
			//cout << temp.pos <<'\n';
		}
	}
	return -1;
}
int main(void) 
{
	input();
	int ans = BFS();
	cout << ans;
}
#endif

//================================================================================================================
//2206 - 벽 부수고 이동하기
//================================================================================================================
//더풀어봐야
#if 0
#include <iostream>
#include <queue>
using namespace std;
int N, M;
struct POS 
{
	int r, c;
	int dis;
	bool bk = false;
};
int Y[] = { -1,0,1,0 };
int X[] = { 0, 1,0,-1 };
char arr[1000 + 10][1000 + 10];
bool check[1000 + 10][1000 + 10][2];
queue<POS> Q;
void input(void) 
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
	{
		for (int h = 1; h <= M; h++) 
		{
			cin >> arr[i][h];
		}
	}
}
int BFS(void) 
{
	check[1][1] = true;
	Q.push({ 1,1,1, false });
	while (!Q.empty()) 
	{
		POS now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) 
		{
			POS temp;
			temp.r = now.r + Y[i];
			temp.c = now.c + X[i];
			temp.dis = now.dis+1;
			if (temp.r == N && temp.c == M) return temp.dis;
			if (temp.r<1 || temp.c<1 || temp.r>N || temp.c>M) continue;
			if (arr[temp.r][temp.c] == '0')
			{
			//	check[temp.r][temp.c] = +1;
				Q.push(temp);
			}
			if (arr[temp.r][temp.c] == '1') 
			{
				if (now.bk) continue;
				temp.bk = true;
				//check[temp.r][temp.c] += 1;
				Q.push(temp);
			}
			//if (check[temp.r][temp.c]) continue;
		}
	}
	return -1;
}
int main(void) 
{
	input();
	int ans = BFS();
	cout << ans;
	return 0;
}
#endif

//================================================================================================================
//14248 점프 점프
//================================================================================================================
#if 0
#include <iostream>
#include <queue>
#define MAXD (100000)
using namespace std;
int N, S;
queue<int>Q;
int pos[] = { -1,1 };
int arr[MAXD + 10];
int record[MAXD + 10];
int result = 1;
void input(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> S;
}
void BFS(void)
{
	Q.push(S);
	while (!Q.empty())
	{
		if (result == N) break;
		int start = Q.front(); Q.pop();

		for (int c = 0; c <= 1; c++)
		{
			int nd = start + (arr[start] * (pos[c]));
			if (nd > N || nd < 1) continue;
			if (record[nd]) continue;
			record[nd] = 1;
			result++;
			Q.push(nd);
		}
		record[start] = 1;
	}
	cout << result;
}
int main(void)
{
	input();
	BFS();
	return 0;
}
#endif

//================================================================================================================
//10472 - 십자 뒤집기
//================================================================================================================
#if 1
#include <iostream>
#include <queue>
using namespace std;
int P;
char arr[3+2][3+2];
char papper[3 + 2][3 + 2];
int Y[] = { -1,0,1,0 };
int X[] = { 0,1,0,-1 };
int visit[3 + 2][3 + 2];
int initrecord[50 + 1];

struct STATUS
{
	int nowy;
	int nowx;
	int recordidx;
	//deque<int> x_record;
	//deque<int> y_record;
	int X_record[50 + 1] = {0};
	int y_record[50 + 1] = { 0 };
};
queue<STATUS> Q;
void inputData(void) 
{
	//init
	fill(&arr[0][0], &arr[5][5], 0);
	//입력
	for (int i = 1; i <= 3; i++) 
	{
		for (int c = 1; c <= 3; c++) 
		{
			cin >> arr[i][c];
		}
	}
}
int checkSame() 
{
	for (int i = 1; i <= 3; i++) 
	{
		for (int j = 1; j <= 3; j++) 
		{
			if (papper[i][j] != arr[i][j]) return 0;
		}
	}
	return 1;
}
int BFS(int row, int col) 
{
	//방문배열 초기화

	fill(&visit[0][0], &visit[3 + 2][3 + 2], 0);

	//첫번째 선택
	STATUS first;
	first.nowy = row;
	first.nowx = col;
	first.recordidx = 1;
	copy(initrecord, initrecord + 50 + 1, first.X_record);
	for (int i = 0; i < 4; i++) 
	{
		int dy = row + Y[i];
		int dx = col + X[i];
		if (dy < 1 || dx < 1 || dy>3 || dx>3) continue;
		//papper[dy][dx] = '*';
	}
	visit[row][col] = 1;
	//papper[row][col] = '*';
	Q.push({ row, col, 0,  });
	//바꾸자마자 같으면 최소 값1
	int temp = checkSame();
	if (temp) return 1;
	// 아니면
	while (!Q.empty()) 
	{
		STATUS DATA = Q.front(); Q.pop();
		//if (DATA.y < 1 || DATA.x < 1 || DATA.y > 3 || DATA.x > 3) continue;
		if (visit[DATA.y][DATA.x]) continue;
		// 해당 위치 변경
		if (papper[DATA.y][DATA.x] == '*') papper[DATA.y][DATA.x] = '.';
		if (papper[DATA.y][DATA.x] == '.') papper[DATA.y][DATA.x] = '*';
		for (int i = 0; i < 4; i++)
		{
			int dy = DATA.y + Y[i];
			int dx = DATA.x + X[i];
			if (dy < 1 || dx < 1 || dy>3 || dx>3) continue;
			STATUS newdata;
			newdata.y = dy;
			newdata.x = dx;
		/*	if (papper[dy][dx] == '*') 	newdata.cc = '.';
			if (papper[dy][dx] == '.') newdata.cc = '*';

			if (papper[dy][dx] == '*') papper[dy][dx] = '.';
			if (papper[dy][dx] == '.') papper[dy][dx] = '*';*/
		}
		//for (int i = 0; i < 4; i++) 
		//{
		//	int dy = DATA.y + Y[i];
		//	int dx = DATA.x + X[i];
		//	if (dy < 1 || dx < 1 || dy>3 || dx>3) continue;
		//	
		//	if (papper[dy][dx] == '*') papper[dy][dx] = '.';
		//	if (papper[dy][dx] == '.') papper[dy][dx] = '*';
		//}
		Q.push({})

	}
}
void solve(void) 
{
	for (int r = 1; r <= 3; r++) 
	{
		for (int c = 1; c <= 3; c++) 
		{
			// papper새로 만들어줘야됨.해당위치부터 눌러봐야하니까.
			fill(&papper[0][0], &papper[3 + 2][3 + 2], '.');
			int ans = BFS(r, c);
			if (ans) cout << ans << "\n";
		}
	}
}
int main(void) 
{
	cin >> P;
	for (int i = 0; i < P; i++) 
	{
		inputData();
		solve();
	}
	
	return 0;
}
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif