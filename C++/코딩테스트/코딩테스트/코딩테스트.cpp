#if 1
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int sr, sc, er, ec, totalcnt;
int H, W;
string result;
char D[5] = { 'u','r','d','l' };

void DFS(int nowR, int nowC, string nowS, int cnt)
{
	static int dr[] = { -1,0,1,0 };
	static int dc[] = { 0,1,0,-1 };
	if (cnt > totalcnt) return;
	int ans = string{ result }.compare(string{ nowS });
	if (ans == -1 && (nowS.size() > 1)) return;
	if (nowR == er && nowC == ec && cnt == totalcnt)
	{
		// cout <<nowS <<'\n';
		if (result.size() != 0)
		{
			int ans = string{ result }.compare(string{ nowS });
			if (ans > 0)
			{
				result = nowS;
			}
		}
		else result = nowS;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int dy = nowR + dr[i];
		int dx = nowC + dc[i];
		if (dy<1 || dx<1 || dy>H || dx>W) continue;
		DFS(dy, dx, nowS + D[i], cnt + 1);
	}
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";
	W = m; H = n;
	sc = y; sr = x; er = r; ec = c; totalcnt = k;
	//DFS(x,y,"",0);
	//init(n,m,x,y,r,c);   
	DFS(y, x, "", 0);
	if (result == "") answer = "impossible";
	else answer = result;
	return answer;
}
#endif