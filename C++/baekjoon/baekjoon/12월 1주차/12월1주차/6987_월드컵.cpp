#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[6 + 1][3];
vector<int> problem[4][7];
struct TM {
	int o, r;
};
vector<TM> match;
vector<int>result;
//int result[] = {};
int visit[7];
vector<int> ans(4);
void input() {
	for (int i = 0; i < 4; i++) {
		for (int r = 1; r <= 6; r++) {
			for (int c = 0; c < 3; c++) {
				int res; cin >> res;
				problem[i][r].push_back(res);
			}
		}
	}
}
void makeverse() {
	for (int i = 1; i <= 5; i++) {
		for (int c = i + 1; c <= 6; c++) {
			match.push_back({ i,c });
		}
	}
}
void makearr() {
	fill(&arr[0][0], &arr[6][3], 0);
	for (int i = 0; i < match.size(); i++) {
		int ateam = match[i].o;
		int bteam = match[i].r;
		if (result[i] == 0) {
			arr[ateam][0] += 1;
			arr[bteam][2] += 1;
		}
		else if (result[i] == 1) {
			arr[ateam][2] += 1;
			arr[bteam][0] += 1;
		}
		else if (result[i]==2){
			arr[ateam][1] += 1;
			arr[bteam][1] += 1;
		}
	}
}
int compare(int idx) {
	for (int r = 1; r <= 6; r++) {
		for (int c = 0; c < 3; c++) {
			//cout << arr[r][c] << " ";
			
			if (arr[r][c] != problem[idx][r][c]) return 0;
		}
		//cout <<	"	";
		//for (int c = 0; c < 3; c++) {
		//	cout << problem[idx][r][c]<<" ";
		//}
		//cout << '\n';
	}
	return 1;
}
void print() {
	for (int r = 1; r <= 6; r++) {
		for (int c = 0; c < 3; c++) {
			cout << arr[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
void makeresult(int dep) {
	if (dep == match.size()) {
		//makearr();
		for (int i = 0; i < 4; i++) {
			if (ans[i]) continue;
			int ret = compare(i);
			ans[i] = ret;
			//cout << ret << " ";
		}
		//cout << '\n';
		return;
	}
	int ateam = match[dep].o;
	int bteam = match[dep].r;

	arr[ateam][0] ++;
	arr[bteam][2] ++;
	makeresult(dep + 1);
	arr[ateam][0] --;
	arr[bteam][2] --;

	arr[ateam][1] ++;
	arr[bteam][1] ++;
	makeresult(dep + 1);
	arr[ateam][1] --;
	arr[bteam][1] --;

	arr[ateam][2] ++;
	arr[bteam][0] ++;
	makeresult(dep + 1);
	arr[ateam][2] --;
	arr[bteam][0] --;
	
	//for (int i = 0; i < 3; i++) {
	//	result.push_back(i);
	//	makeresult(dep + 1);
	//	result.pop_back();
	//}
}
void solve() {
	makeverse();
	makeresult(0);
}
int main(void){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	for (int i = 0; i < 4; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

int a[4][6][3];
int result[6][3];
int ans[4];

void dfs(int game) {
	// 모든 경기를 마쳤다면
	if (game == 15) {
		for (int t = 0; t < 4; t++) {
			// 이미 존재하는 경우로 판별됐다면
			if (ans[t] == 1) continue;

			bool flag = true;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					if (a[t][i][j] != result[i][j]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}

			// 경기결과가 일치한다면
			if (flag) {
				ans[t] = 1;
				return;
			}
		}

		return;
	}

	int t1 = team1[game];
	int t2 = team2[game];

	// t1 win, t2 lose
	result[t1][0]++;
	result[t2][2]++;
	dfs(game + 1);
	result[t1][0]--;
	result[t2][2]--;

	// t1 draw, t2 draw
	result[t1][1]++;
	result[t2][1]++;
	dfs(game + 1);
	result[t1][1]--;
	result[t2][1]--;

	// t1 lose, t2 win
	result[t1][2]++;
	result[t2][0]++;
	dfs(game + 1);
	result[t1][2]--;
	result[t2][0]--;
}

int main(int argc, const char * argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[t][i][j];
			}
		}
	}

	dfs(0);

	for (int i = 0; i < 4; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}
#endif