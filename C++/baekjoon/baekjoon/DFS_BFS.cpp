//===================DFS/BFS 문제 연습============================================/
//------------------------------------------------------------------------------
// 1260 - DFS와 BFS
//------------------------------------------------------------------------------

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
int N, M, V;
std::vector<std::vector<int>> arr(1000 + 10, std::vector<int>(1000 + 10));
//std::vector<std::vector<int>> arr(1000+10);
std::vector<int> visit(1000 + 10, 0);
std::queue<int> q;
void input(void)
{
	std::cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int start, from;
		std::cin >> start >> from;
		arr[start][from] = 1;
		arr[from][start] = 1;
	}
}
void DFS(int start)
{
	if (start == V)
	{
		visit[start] = 1;
		printf("%d ", V);
	}
	for (int i = 1; i <= N; i++)
	{
		if (!(visit[i]) && arr[start][i] == 1)
		{
			int now = i;
			visit[now] = 1;
			printf("%d ", now);
			DFS(now);
		}
	}
}
void init(void)
{
	for (int i = 1; i <= N; i++)
	{
		visit[i] = 0;
	}
}
void BFS(int start)
{
	visit[start] = 1;
	printf("%d ", start);
	q.push(start);
	while (!(q.empty()))
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (arr[now][i] == 1 && !(visit[i]))
			{
				printf("%d ", i);
				visit[i] = 1;
				q.push(i);
			}
		}

	}
}
void solve(void)
{
	DFS(V);
	printf("\n");
	init();
	BFS(V);
}
int main()
{
	input();
	solve();
}
#endif

//======================================================================================================
//10819 차이를 최대로 - 백준
//======================================================================================================
#if 0
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
int X[] = { -1,1 };
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
			temp.time = now.time + 1;
			if (temp.pos < 0)continue;
			if (temp.pos > 100000) continue;
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
//다시 풀어보자
#if 0
#include <iostream>
#include <queue>
using namespace std;
int N, M;
struct POS
{
	int r, c;
	int dis;
	bool bk;
};
int Y[] = { -1,0,1,0 };
int X[] = { 0, 1,0,-1 };
char arr[1000 + 10][1000 + 10];
bool check[2][1000 + 10][1000 + 10];
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
	if (N == 1 && M == 1) return 1;

	check[0][1][1] = true;
	check[1][1][1] = true;
	Q.push({ 1,1,1,0});
	int maxx = 1e9;
	while (!Q.empty())
	{
		POS now = Q.front(); Q.pop();
		if (now.r == N && now.c == M)
		{
			return now.dis;
		}
		for (int i = 0; i < 4; i++)
		{
			POS temp;
			temp.r = now.r + Y[i]; 
  			temp.c = now.c + X[i];
			temp.dis = now.dis + 1;
			temp.bk = now.bk;

			if (temp.r<1 || temp.c<1 || temp.r>N || temp.c>M) continue;
			//벽이면
			if (arr[temp.r][temp.c] == '1' && temp.bk==false)
			{
				temp.bk = true;
				if (check[1][temp.r][temp.c]) continue;
				check[1][temp.r][temp.c] = 1; 
				Q.push(temp);
			}
			// 벽 아니면
			if (arr[temp.r][temp.c] == '0')
			{
				if (temp.bk == false) 
				{
					if (check[0][temp.r][temp.c]) continue;
					check[0][temp.r][temp.c] = 1;
				}
				else 
				{
					if (check[1][temp.r][temp.c]) continue;
					check[1][temp.r][temp.c] = 1;
				}
				Q.push(temp);
			}

 		}
	}
	return maxx;
}
int main(void)
{
	input();
	int ans = BFS();
	if (ans == 1e9) cout << -1;
	else { cout << ans; }
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
// 도저히 안된다
#if 0
#include <iostream>
#include <vector>
#include <string>
//#include <queue>
using namespace std;
int P;
string board;
string whitepapper = "000000000";
string answers = "000000000";
int numbers[9];
vector<vector<pair<int, int>>> arr;
int maxx;
void inputData() 
{
	board = "000000000";
	whitepapper = "000000000";
	for (int i = 0; i < 9; i++)
	{	
		char cc; cin >> cc;
		if (cc == '.') board[i] = '0';
		else board[i] = '1';
	}
	maxx = 0xf777777;
}
int check() 
{
	answers = "000000000";
	int cnt = 0;
	static int dr[] = { -1,0,1,0 };
	static int dc[] = { 0,1,0,-1 };
	for (int i = 0; i < 9; i++)
	{
		if (whitepapper[i] == '1') 
		{
			cnt++;
			int y = i / 3;
			int x = i % 3;
			if (answers[y * 3 + x] == '0')  answers[y * 3 + x] = '1';
			else if (answers[y * 3 + x] == '1')  answers[y * 3 + x] = '0';
			for (int r = 0; r < 4; r++)
			{
				int dy = y + dr[r];
				int dx = x + dc[r];
				if (dy < 0 || dx < 0 || dy > 2 || dx > 2) continue;
				if (answers[dy * 3 + dx] == '0')  answers[dy * 3 + dx] = '1';
				else if (answers[dy * 3 + dx] == '1')  answers[dy * 3 + dx] = '0';
			}
		}
	}
	//cout << answers << " == " << board<<"\n";
	if (answers == board) return cnt;
	return 0;
}
void dfs(int dep) 
{
	if (dep == 9) 
	{
		//cout << whitepapper << "\n";
		int ans = check();
		//cout << ans<< '\n'; 
		if (ans && maxx > ans) maxx = ans;
		return;
	}
	for (int i = 0; i < 2; i++) 
	{
		whitepapper[dep] = '0'+ i;
		dfs(dep + 1);
		whitepapper[dep] = '0';
	}
}
int solve() 
{
	if (board == whitepapper) return 0;
	dfs(0);
	return maxx;
}
int main(void) 
{
	cin >> P;
	for (int i = 0; i < P; i++) 
	{
		inputData();
		int ans = solve();
		cout << ans;
	}
	return 0;

}

#endif
#if 0
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int P;
int arr[3 + 2][3 + 2];
int papper[3 + 2][3 + 2];
int Y[] = { -1,0,1,0 };
int X[] = { 0,1,0,-1 };
struct ST
{
	int y;
	int x;
};
queue<vector<ST>> Q;
void inputData(void)
{
	//init
	fill(&arr[0][0], &arr[5][5], 0);
	//입력
	for (int i = 1; i <= 3; i++)
	{
		for (int c = 1; c <= 3; c++)
		{
			char ccc; cin >> ccc;
			if (ccc == '.') arr[i][c] = 0;
			else arr[i][c] = 1;
		}
	}
}
int checkSame(vector<ST> nowdata)
{
	fill(&papper[0][0], &papper[5][5], 0);
	//기록
	for (int i = 0; i < nowdata.size(); i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (j == 0)
			{
				if (nowdata[i].y < 1 || nowdata[i].x < 1 || nowdata[i].y >3 || nowdata[i].x >3) continue;
				if (papper[nowdata[i].y][nowdata[i].x]) papper[nowdata[i].y][nowdata[i].x] = 0;
				else papper[nowdata[i].y][nowdata[i].x] = 1;
				continue;
			}
			int dy = nowdata[i].y + Y[j - 1];
			int dx = nowdata[i].x + X[j - 1];
			if (dy < 1 || dx < 1 || dy > 3 || dx > 3) continue;

			if (papper[dy][dx]) papper[dy][dx] = 0;
			else papper[dy][dx] = 1;
		}
	}
	//같은 여부 확인
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (papper[i][j] != arr[i][j]) return 0;
		}
	}
	return 1;
}
int BFS()
{
	vector<ST> nowdata;
	if (checkSame(nowdata)) return 0;
	queue<vector<ST>> Q;
	int maxx = 0xf777777;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			ST temp;
			temp.y = i;
			temp.x = j;
			vector<ST> a;
			a.push_back(temp);
			Q.push(a);
		}
	}
	while (!Q.empty())
	{
		vector<ST> temp = Q.front(); Q.pop();
		int lens = temp.size();
		//if (lens > 3 * 3) return lens;
		if (checkSame(temp))  return lens;

		// 해당 위치 변경
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{				
				vector<ST> copytemp = temp;
				ST a;
				a.y = i;
				a.x = j;
				copytemp.push_back(a);
				Q.push(copytemp);
			}
		}
	}
	return maxx;
}
void solve(void)
{
	int ans = BFS();
	int maxx = 0xf777777;
	if (ans < maxx)
	{
		maxx = ans;
	}
	cout << maxx << "\n";

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

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int P;
int arr[3 + 1][3 + 1];
int Y[] = { -1,0,1,0 };
int X[] = { 0,1,0,-1 };
struct ST
{
	int y;
	int x;
	int papper[3 + 1][3 + 1];
	//int visit[3 + 1][3 + 1];
	int idx;
};
queue<ST> Q;
void inputData(void)
{
	//init
	fill(&arr[0][0], &arr[3+1][3+1], 0);
	//입력
	for (int i = 1; i <= 3; i++)
	{
		for (int c = 1; c <= 3; c++)
		{
			char ccc; cin >> ccc;
			if (ccc == '.') arr[i][c] = 0;
			else arr[i][c] = 1;
		}
	}
}
int checkSame(ST nowdata)
{
	for (int r = 1; r <= 3; r++) 
	{
		for (int c = 1; c <= 3; c++)
		{
			if (arr[r][c] != nowdata.papper[r][c]) return 0;
		}
	}
	return 1;
}
ST paint(ST nowdata)
{
	if (nowdata.papper[nowdata.y][nowdata.x])nowdata.papper[nowdata.y][nowdata.x] = 0;
	else nowdata.papper[nowdata.y][nowdata.x] = 1;
	for (int r = 1; r <= 3; r++) 
	{
		for (int c = 0; c < 4; c++)
		{
			int dy = nowdata.y + Y[c];
			int dx = nowdata.x + X[c];
			if (dy < 1 || dx < 1 || dy>3 || dx>3) continue;
			if (nowdata.papper[dy][dx]) nowdata.papper[dy][dx] = 0;
			else nowdata.papper[dy][dx] = 1;
		}
	}
	return nowdata;
}
int BFS() 
{
	/*struct ST
		int y, x,  papper[3 + 1][3 + 1];, visit[3 * 3 + 1], idx;
	*/
	
	ST first;
	first.y;
	first.x;
	fill(&first.papper[0][0], &first.papper[3 + 1][3 + 1], 0);
	first.idx = 0;

	if (checkSame(first)) return 0;

	for (int r = 1; r <= 3; r++)
	{
		for (int c = 1; c <= 3; c++)
		{
			ST firstData;
			//fill(&firstData, &firstData+16, 0);
			
			firstData.y = r;
			firstData.x = c;
			// 밑에 fill이나 memset이나 전부 위에 for문 인덱스 c를 0으로 자꾸 바꿈
			//copy(&whitep[0][0], &whitep[3 + 1][3 + 1], &firstData.papper[3+1][3+1]);
			//fill(&firstData.papper[0][0], &firstData.papper[3 + 1][3 + 1], 0);
			for (int i = 0; i <= 3; i++) 
			{
				for (int z = 0; z <= 3; z++) 
				{
					firstData.papper[i][z] = 0;
				}
			}
			firstData.idx = 1;
			Q.push(firstData);
		}
	}
	// Q. 대체 여기서 왜 오류가 나는지
	while (!Q.empty()) 
	{
		ST DATA = Q.front(); Q.pop();
		if (DATA.y < 1 || DATA.x < 1 || DATA.y>3 || DATA.x>3) continue;
		if (checkSame(DATA)) return DATA.idx;
		for (int r = 1; r <= 3; r++)
		{
			for (int c = 1; c <= 3; c++)
			{
				ST NEWDATA = DATA;
				NEWDATA.y = r;
				NEWDATA.x = c;
				NEWDATA = paint(NEWDATA);
				NEWDATA.idx = DATA.idx + 1;
				Q.push(NEWDATA);
			}
		}
	}
	return 0;
}
void solve(void)
{
	int ans = BFS();
	int maxx = 0xf777777;
	if (ans < maxx)
	{
		maxx = ans;
	}
	cout << maxx << "\n";

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

#if 0
#include <iostream>
#include <queue>
using namespace std;
int P;
int arr[3 + 2][3 + 2];
int papper[3 + 2][3 + 2];
int Y[] = { -1,0,1,0 };
int X[] = { 0,1,0,-1 };
int visit[2][3 + 2][3 + 2];
int initrecord[50 + 1];

struct STATUS
{
	int nowy;
	int nowx;
	int recordidx;
	//deque<int> x_record;
	//deque<int> y_record;
	int X_record[1000 + 1] = { 0 };
	int Y_record[1000 + 1] = { 0 };
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
			char ccc; cin >> ccc;
			if (ccc == '.') arr[i][c] = 0;
			else arr[i][c] = 1;
		}
	}
}
int checkSame(STATUS nowdata)
{
	fill(&papper[0][0], &papper[5][5], 0);
	//기록
	for (int i = 1; i <= nowdata.recordidx; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (j == 0)
			{
				if (nowdata.Y_record[i] < 1 || nowdata.X_record[i] < 1 || nowdata.Y_record[i] >3 || nowdata.X_record[i] >3) continue;
				if (papper[nowdata.Y_record[i]][nowdata.X_record[i]]) papper[nowdata.Y_record[i]][nowdata.X_record[i]] = 0;
				else papper[nowdata.Y_record[i]][nowdata.X_record[i]] = 1;
				continue;
			}
			int dy = nowdata.Y_record[i] + Y[j - 1];
			int dx = nowdata.X_record[i] + X[j - 1];
			if (dy < 1 || dx < 1 || dy > 3 || dx > 3) continue;

			if (papper[dy][dx]) papper[dy][dx] = 0;
			else papper[dy][dx] = 1;
		}
	}
	//같은 여부 확인
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

	//fill(&visit[0][0], &visit[3 + 2][3 + 2], 0);
	queue<STATUS> Q;
	//첫번째 선택
	STATUS first;
	first.nowy = row;
	first.nowx = col;
	first.recordidx = 1;
	copy(initrecord, initrecord + 1000 + 1, first.X_record);
	copy(initrecord, initrecord + 1000 + 1, first.Y_record);
	first.Y_record[1] = row;
	first.X_record[1] = col;
	Q.push(first);
	//visit[row][col] = 1;
	//바꾸자마자 같으면 최소 값1
	int maxx = 0xf777777;
	while (!Q.empty())
	{
		STATUS DATA = Q.front(); Q.pop();
		if (checkSame(DATA)) return DATA.recordidx;
		//if (DATA.nowy < 1 || DATA.nowx < 1 || DATA.nowy > 3 || DATA.nowx > 3) continue;
		//if (visit[DATA.nowy][DATA.nowx]) continue;
		// 해당 위치 변경
		for (int i = 0; i < 4; i++)
		{
			int dy = DATA.nowy + Y[i];
			int dx = DATA.nowx + X[i];
			if (dy < 1 || dx < 1 || dy>3 || dx>3) continue;
			STATUS newdata;
			newdata.nowy = dy;
			newdata.nowx = dx;
			newdata.recordidx = DATA.recordidx + 1;
			for (int z = 1; z <= DATA.recordidx; z++)
			{
				newdata.X_record[z] = DATA.X_record[z];
				newdata.Y_record[z] = DATA.Y_record[z];
			}
			newdata.Y_record[newdata.recordidx] = dy;
			newdata.X_record[newdata.recordidx] = dx;
			//visit[newdata.nowy][newdata.nowx] = 1;
			Q.push(newdata);
		}
		//visit[DATA.nowy][DATA.nowx] = 1;
	}
	return maxx;
}
void solve(void)
{
	int maxx = 0xf777777;
	for (int r = 1; r <= 3; r++)
	{
		for (int c = 1; c <= 3; c++)
		{
			int ans = BFS(r, c);
			cout << "r : " << r << '\n' << "c : " << c << " = " << ans << '\n' << '\n';
			if (ans < maxx)
			{
				maxx = ans;
			}
		}
	}
	cout << maxx << "\n";

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
//14442 벽부수고 이동하기2
//================================================================================================================
#if 0
#include <iostream>
#include <queue>
#define MAX_NM (1000)

using namespace std;
int N, M, K;
char arr[MAX_NM + 2][MAX_NM + 2];
int visit[10 + 1][MAX_NM + 2][MAX_NM + 2];
struct ST 
{
	int r, c, breaker, dis;
};
queue<ST> Q;
void inputData(void) 
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) 
	{
		for (int c = 1; c <= M; c++)
		{
			cin >> arr[i][c];
		}
	}
}
int BFS() 
{
	int Y[] = { -1,0,1,0 };
	int X[] = { 0,1,0,-1 };

	int maxx = 0xf777777;

	if (N == 1 && M == 1) return 1;
	
	Q.push({ 1,1,0,1 });
	for (int i = 0; i <= K; i++) 
	{
		visit[i][1][1] = 1;
	}
	
	while (!Q.empty()) 
	{
		ST temp = Q.front(); Q.pop();

		// 혹시나 마지막 지점으로 도착했다면
		if ((temp.r == N) && (temp.c == M)) return temp.dis;
		for (int i = 0; i < 4; i++) 
		{
			ST newdata;
			newdata.r = temp.r + Y[i];
			newdata.c = temp.c + X[i];
			if (newdata.r < 1 || newdata.c < 1 || newdata.r > N || newdata.c > M) continue;


			newdata.breaker = temp.breaker;
			newdata.dis = temp.dis + 1;
			
			//벽이면
			if (arr[newdata.r][newdata.c] == '1') 
			{
				if (newdata.breaker >= K) continue;
				else 
				{
					newdata.breaker++;
					if (visit[newdata.breaker][newdata.r][newdata.c]) continue;
					visit[newdata.breaker][newdata.r][newdata.c] = 1;
					Q.push(newdata);
				}
			}
			// 벽아니면
			else 
			{
				//쓴적 있으면
				if (newdata.breaker!=0) 
				{
					if (visit[newdata.breaker][newdata.r][newdata.c]) continue;
					visit[newdata.breaker][newdata.r][newdata.c] = 1;
					Q.push(newdata);
				}
				else 
				{
					if (visit[0][newdata.r][newdata.c]) continue;
					visit[0][newdata.r][newdata.c] = 1;
					Q.push(newdata);
				}

			}
		}
	}return 0;
}
int main(void) 
{
	inputData();
	int ans = BFS();
	if (ans)  cout << ans;
	else cout << -1;
	return 0;
}
#endif

//================================================================================================================
//문제 [1815] A8: [TST] 로봇
//================================================================================================================
#if 0
#include <iostream>
#include <queue>
int M, N;
int arr[100 + 2][100 + 2];
using namespace std;
int s_y, s_x, s_p;
int e_y, e_x, e_p;
int Y[] = { 0, 0, 0, 1, -1 };
int X[] = { 0, 1, -1 , 0, 0 };
int visit[5][100 + 2][100 + 2];
struct ST
{
	int r, c, direc, cnt;
};
queue<ST> Q;
void input()
{
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int c = 1; c <= N; c++)
		{
			cin >> arr[i][c];
		}
	}
	cin >> s_y >> s_x >> s_p;
	cin >> e_y >> e_x >> e_p;
}
int directCalc(int turndi, int n_d)
{
	if (n_d == 1)
	{
		if (!turndi) return 4;
		return 3;
	}
	else if (n_d == 2)
	{
		if (!turndi) return 3;
		return 4;
	}
	else if (n_d == 3)
	{
		if (!turndi) return 1;
		return 2;
	}
	else
	{
		if (!turndi) return 2;
		return 1;
	}
}
int BFS()
{
	Q.push({ s_y,s_x,s_p, 0 });

	visit[s_p][s_y][s_x] = 1;
	while (!Q.empty())
	{
		ST NOW = Q.front(); Q.pop();
		//명령 1
		for (int rep = 1; rep <= 3; rep++)
		{
			ST NEWPOS = NOW;
			NEWPOS.r += rep * Y[NEWPOS.direc];
			NEWPOS.c += rep * X[NEWPOS.direc];
			NEWPOS.cnt += 1;

			// 궤도가 없다면
			if (NEWPOS.r <1 || NEWPOS.r >M || NEWPOS.c < 1 || NEWPOS.c > N) break;
			if (arr[NEWPOS.r][NEWPOS.c] == 1) break;
			if (visit[NEWPOS.direc][NEWPOS.r][NEWPOS.c]) continue;
			if ((NEWPOS.r == e_y) && (NEWPOS.c == e_x) && (NEWPOS.direc == e_p))
			{
				return NEWPOS.cnt;
			}
			visit[NEWPOS.direc][NEWPOS.r][NEWPOS.c] = 1;
			Q.push(NEWPOS);
		}
		// 명령 2. i가 0이면 왼쪽 1이면 오른쪽
		for (int i = 0; i < 2; i++)
		{
			ST NEWPOS = NOW;
			NEWPOS.direc = directCalc(i, NEWPOS.direc);
			NEWPOS.cnt += 1;
			if (visit[NEWPOS.direc][NEWPOS.r][NEWPOS.c]) continue;
			if ((NEWPOS.r == e_y) && (NEWPOS.c == e_x) && (NEWPOS.direc == e_p))
			{
				return NEWPOS.cnt;
			}
			visit[NEWPOS.direc][NEWPOS.r][NEWPOS.c] = 1;
			Q.push(NEWPOS);
		}
	}
	return 0;
}
int main()
{
	input();
	int ans = BFS();
	cout << ans;
	return 0;
}
#endif
#if 0
#include <iostream>
#include <queue>
int M, N;
int arr[100 + 2][100 + 2];
using namespace std;
int s_y, s_x, s_p;
int e_y, e_x, e_p;
int Y[] = {0, 0, 0, 1, -1};
int X[] = {0, 1, -1 , 0, 0 };
int visit[4][100 + 2][100 + 2];
struct ST 
{
	int r, c, direc, cnt;
};
queue<ST> Q;
void input() 
{
	cin >> M >> N;

	for (int i = 1; i <= M; i++) 
	{
		for (int c = 1; c <= N; c++) 
		{
			cin >> arr[i][c];
		}
	}
	cin>> s_y >> s_x >>s_p;
	cin >> e_y >> e_x >> e_p;
}
int directCalc(int o_d, int n_d) 
{
	if (o_d == n_d) return 0;
	if (o_d == 1) 
	{
		if (n_d == 3 || n_d==4) return 1;
		return 2;
	}
	else if (o_d == 2)
	{
		if (n_d == 3 || n_d == 4) return 1;
		return 2;
	}
	else if (o_d == 3)
	{
		if (n_d == 1 || n_d == 2) return 1;
		return 2;
	}
	else 
	{
		if (n_d == 1 || n_d == 2) return 1;
		return 2;
	}
}
int BFS() 
{
	Q.push({ s_y,s_x,s_p, 0 });
	visit[1][s_y][s_x] = 1;
	visit[2][s_y][s_x] = 1;
	visit[3][s_y][s_x] = 1;
	for (int i = 1; i <= 3; i++) 
	{
		for (int j = 1; j <= M ; j++) 
		{
			for (int c = 1; c <= N; c++) 
			{
				visit[i][j][c] = 0xf777777;
			}
		}
	}
	int maxx = 0xf777777;
	while (!Q.empty()) 
	{
		ST NOW = Q.front(); Q.pop();
		//명령 1
		// 방향 이동
		if ((NOW.r == e_y) && (NOW.c == e_x))
		{
			int tempvalue = directCalc(NOW.direc, e_p);
			return NOW.cnt + tempvalue;
			/*if (maxx > NOW.cnt + tempvalue) maxx = NOW.cnt + tempvalue;
			continue;*/
		}
		for (int rep = 1; rep <= 3; rep++) 
		{
			for (int i = 1; i <= 4; i++)
			{
				ST NEWPOS;
				int temprep = rep;
				int flag = 0;
				NEWPOS.r = NOW.r;
				NEWPOS.c = NOW.c;
				while (temprep) 
				{
					NEWPOS.r+= Y[i];
					NEWPOS.c+= X[i];
					// 궤도가 없다면
					if (arr[NEWPOS.r][NEWPOS.c] == 1) 
					{
						flag = 1;
						break;
					} 
					temprep--;
				}
				if (flag) continue;
				NEWPOS.direc = NOW.direc;
				//범위 벗어났다면 
				if (NEWPOS.r<1 || NEWPOS.c<1 || NEWPOS.r>M || NEWPOS.c>N) continue;
				// 궤도가 없다면
				if (arr[NEWPOS.r][NEWPOS.c]==1) continue;
				// 이미 방문했다면
				//if (visit[rep][NEWPOS.r][NEWPOS.c]!= 0xf777777) continue;
				//방향 계산
				int dc = directCalc(NEWPOS.direc, i);
				NEWPOS.direc = i;
				// 명령 2와 1값 +
				NEWPOS.cnt = NOW.cnt + dc + 1;
				
				// 혹시나 끝지점까지 왔다면
				//if ((NEWPOS.r == e_y) && (NEWPOS.c == e_x)) 
				//{
				//	int tempvalue = directCalc(NEWPOS.direc, e_p);
				//	return NEWPOS.cnt + tempvalue;
				//}
				if (visit[rep][NEWPOS.r][NEWPOS.c] > NEWPOS.cnt) visit[rep][NEWPOS.r][NEWPOS.c]=NEWPOS.cnt;
				Q.push(NEWPOS);
			}
		}
	}
	return maxx;
}
int main() 
{
	input();
	int ans =BFS();
	cout << ans;
	return 0;
}
#endif

//================================================================================================================
//5107 마니또
//================================================================================================================
#if 0
#include <iostream>
#include <string>
#include <map>
using namespace std;
int N;
map<string, string> names;
map<string, int> visit;
int inputData() 
{
	cin >> N;
	if (!N) return 0;
	names.clear();
	for (int i = 0; i < N; i++) 
	{
		string from;
		string to;
		cin >> from >> to;
		names.insert({ from, to });
		visit.insert({ from, 0 });
	}
	return 1;
}
int DFS(string nowKey, string starter) 
{
	// 이미 방문한 사람이면 return
	if (visit.find(nowKey)->second) return 0;

	//방문처리
	visit.find(nowKey)->second = 1;
	//마니또를 받는 사람이 처음 연결고리의 시작이면 return 1;
	if ((names.find(nowKey)->second) == starter) return 1;
	
	// 연결고리가 되는 거면 DFS 끝내기;
	if (DFS(names.find(nowKey)->second, starter)) return 1;
	return 0;
}
int solve() 
{
	int cnt = 0;
	for (auto iter : names) 
	{
		string starter = iter.first;
		if (DFS(starter, starter)) cnt++;
	}
	return cnt;
}
int main(void) 
{
	int idx = 1;
	while (inputData()) 
	{
		cout<< idx << " " << solve() <<"\n";
		idx++;
	}
	return 0;
}
#endif

//================================================================================================================
//12761 돌다리
//================================================================================================================
#if 1
#include <iostream>
#include <queue>
using namespace std;
struct ST 
{
	int pos, cnt;
};

queue<ST> Q;
int A, B, N, M;
int visited[100000+1];
int BFS()
{
	if (N == M) return 0;
	Q.push({ N,0 });
	while (!Q.empty()) 
	{
		ST NOW = Q.front(); Q.pop();
		for (int i = 0; i < 8; i++) 
		{
			ST TEMP = NOW;
			TEMP.cnt += 1;
			switch (i)
			{
				case 0:	TEMP.pos += -1;	break;
				case 1:	TEMP.pos += 1;	break;
				case 2:	TEMP.pos += A;	break;
				case 3:	TEMP.pos -= A;	break;
				case 4:	TEMP.pos += B;	break;
				case 5:	TEMP.pos -= B;	break;
				case 6:	TEMP.pos *= A;	break;
				case 7:	TEMP.pos *= B;	break;
			}
			if (TEMP.pos < 0 || TEMP.pos>100000) continue;
			if (TEMP.pos == M) return TEMP.cnt;
			if (visited[TEMP.pos]) continue;
			visited[TEMP.pos] = 1;
			Q.push(TEMP);
		}
	}
}
int main(void) 
{
	cin >> A >> B >> N >> M;
	int ans = BFS();
	cout << ans << '\n';
	return 0;
}
#endif

//================================================================================================================
//
//================================================================================================================
#if 0
#endif