#if 1
#include <iostream>
using namespace std;
#define MAX_N (100000)
int ground[MAX_N + 1];
int arr[MAX_N+ 1];
int N, M;
void input(void)
{
	cin >> N >> M;
		cin >> ground[i];
	}
}
void simulation()
{
	for (int i = 0; i < M; i++) {
		int a, b, k; cin >> a >> b >> k;
		arr[a] += k;
		arr[b + 1] -= k;
	}
	for (int i = 1; i <= N; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		ground[i] += arr[i];
		cout << ground[i] << " ";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();

	simulation();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int>ground;
int N, M;
void input(void) 
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		ground.insert({ i,k });
	}
}
void simulation() 
{
	for (int i = 0; i < M; i++) {
		int a, b, k; cin >> a >> b >> k;
		while (a != b+1) {
			auto it = ground.find(a);
			if (it != ground.end()) {
				if (k < 0) {
					it->second -= abs(k);
				}
				else {
					it->second += k;
				}
			}
			else {
				ground.insert({ a, k });
			}
			a++;
		}
	}
}
void print() 
{
	for (auto it : ground) {
		cout << it.second << " ";
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();

	simulation();
	print();
	return 0;
}
#endif