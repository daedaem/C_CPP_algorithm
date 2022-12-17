#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
int n = 6;
vector<int> arr[20000 + 1];
int visit[20000 + 1];
void DFS(int start, int d) {
	if (arr[start].size() == 0) {
		return;
	}

	for (int i = 0; i < arr[start].size(); i++) {
		//if (visit[arr[start][i]] && visit[arr[start][i]] < d) {
		//if (visit[arr[start][i]]) continue;
		//else {
		if (visit[arr[start][i]] > d + 1) {
			visit[arr[start][i]] = d + 1;
			DFS(arr[start][i], d + 1);
		}

		//}
	//	}
		//else if (!visit[arr[start][i]]) {
		//	DFS(arr[start][i], d + 1);
		//	visit[arr[start][i]] = d;
		//}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int s = 0; s < (int)edge.size(); s++) {
		int n1 = edge[s][0];
		int n2 = edge[s][1];
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}
	fill(visit, visit + 20000, 0xf777777);
	DFS(1, 0);
	visit[1] = 0;
	sort(visit + 1, visit + n + 1, greater<int>());

	int maxx = 0;
	int score = 0;
	for (int i = 1; i <= n; i++) {
		if (maxx < visit[i]) {
			maxx = visit[i];
			score = 1;
		}
		else if (maxx == visit[i]) {
			score++;
		}
	}
	answer = score;
	return answer;
}