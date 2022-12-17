#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct ST {
	string nword;
	string ord;
	int num;
};
string orders = "DSLR";
queue<ST> q;
int N, B;
string A;
set<int> s;
void init() {
	q = {};
	s.clear();
}
void input() {
	cin >> A >> B;
}
string BFS() {
	q = {};
	string aa;
	aa.clear();
	q.push({ {A}, {aa}, stoi(A) });
	while (!q.empty()) {
		ST data = q.front(); q.pop();
		if (data.num == B) return data.ord;

		for (int i = 0; i < 4; i++) {
			ST newdata = data;
			newdata.ord.push_back(orders[i]);
			if (i == 0) {
				newdata.num = newdata.num * 2 % 10000;
				newdata.nword = to_string(newdata.num);
			}
			else if (i == 1) {
				if (!newdata.num) {
					newdata.num = 9999;
					newdata.nword = to_string(newdata.num);
				}
				else {
					newdata.num -= 1;
					newdata.nword = to_string(newdata.num);
				}
			}
			else if (i == 2) {
				if (newdata.nword.size() < 4) {
					newdata.nword += '0';
					newdata.num = stoi(newdata.nword);
				}
				else {
					char a = newdata.nword.front();
					newdata.nword[0] = '0';
					newdata.nword += a;
					newdata.num = stoi(newdata.nword);
					newdata.nword = to_string(newdata.num);
				}
			}
			else if (i == 3) {
				if (newdata.nword.size() == 1) {
					newdata.nword = "000" + newdata.nword;
				}
				else if (newdata.nword.size() == 2) {
					newdata.nword = "00" + newdata.nword;
				}
				else if (newdata.nword.size() == 3) {
					newdata.nword = '0' + newdata.nword;
				}
				char ba = newdata.nword.back();
				newdata.nword = ba + newdata.nword;
				newdata.nword.pop_back();
				newdata.num = stoi(newdata.nword);
				newdata.nword = to_string(newdata.num);
			}
			if (s.find(newdata.num) != s.end()) continue;
			else s.insert(newdata.num);
			q.push(newdata);
		}
	}
}
void solve() {
	cout << BFS() << '\n';
}
int main(void) {
	freopen("mathgamefestival.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		init();
		input();
		solve();
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

//deque<int> numb;
int N, B;
string A;
vector<int> comb;
set<int>s;
void init() {
	comb.clear();
	s.clear();
}
int makenumber() {
	string a = A;
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == 0) {
			//doub();
			a = to_string((stoi(a) * 2) % 10000);
			//cout << "D : " << a << '\n';
		}
		else if (comb[i] == 1) {
			//subs();
			int nn = stoi(a);
			if (!nn) {
				nn = 9999;
			}
			else nn -= 1;
			a = to_string(nn);
		//	cout << "S : " << a << '\n';
		}
		else if (comb[i] == 2) {
			//if (a.size() < 4) {
			//	while (a.size() != 4) {
			//		a =  a+"0";
			//	}
			//}
			if (a.size() == 4) {
				char cc = a.front();
				a[0] = '0';
				a += cc;
				a = to_string(stoi(a));
			}
			else if (a.size() <= 3) {
				a =  a+ "0";
			}
			/*else if (a.size() == 2) {
				a = a+ "00" ;
			}
			else if (a.size() == 1) {
				a = a+ "000";
			}*/
	//		cout << "before\n";
//			cout << a << '\n';

	//		cout << "after\n";
	//		cout << a << '\n';
		//	cout << "L : " << a << '\n';

		}
		else if (comb[i] == 3) {
			/*if (a.size() < 4) {

				while (a.size() != 4) {
					a = "0" + a;
				}
			}*/
			if (a.size() == 3) {
				a = "0"+a;
			}
			else if (a.size() == 2) {
				a = "00"+a;
			}
			else if (a.size() == 1) {
				a = "000"+a;
			}
			a = a.back() + a;
			a.pop_back();
			a = to_string(stoi(a));
	//		cout << "R : " << a << '\n';
		}
	}
	//cout << "val : "<< a << '\n';
	int result = stoi(a);
	if ( result== B) {
		auto it = s.begin();
		while (it != s.end()) {
			if (*it == result) break;
			it++;
		}
		if (it != s.end()) return 0;
		else return 1;
	}
	return 0;
}
int DFS(int dep, int lim) {
	if (dep== lim) {
		//cout << "#Comb\n";
	//		cout << '\n';
		int ret = makenumber();
	//	cout << '\n';
		if (ret) {
			for (int i = 0; i < dep; i++) {
				if (comb[i] == 0) cout << "D";
				else if (comb[i] == 1) cout << "S";
				else if (comb[i] == 2) cout << "L";
				else if (comb[i] == 3) cout << "R";
			}
			cout << '\n';
			return 1;
		}
		else return 0;
	}
	/*else if (dep == lim) {
		return 0;
	}*/
	for (int i = 0; i < 4; i++) {
		comb.push_back(i);
		int rret = DFS(dep + 1, lim);
		if(rret) return 1;
		comb.pop_back();
	}
	return 0;
}
void input() {
	cin >> A >> B;
}
int solve() {
	for (int lim = 1; ;lim++) {
		comb.clear();
		int ret = DFS(0, lim);
		if (ret) return 1;
	}
}
int main(void) {
	freopen("mathgamefestival.txt","r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		init();
		input();
		solve();
		
	}
	return 0;
}
#endif

