#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int totalN;
struct CF {
	int idx, time;
};
vector<CF> cof;
vector<int> answer;
bool COMP(const CF &a, const CF &b) {
	if (a.time == b.time) return a.idx < b.idx;
	return a.time < b.time;
}
vector<CF> checkNew() {
	vector<CF>newCof;
	for (int i = 0; i < cof.size(); i++) {
		if (cof[i].time) {
			cof[i].time--;
		}
		if (cof[i].time) newCof.push_back(cof[i]);
		else answer.push_back(cof[i].idx+1);
	}
	return newCof;
	//copy(newCof.begin(),newCof.end(),cof.begin());
}
vector<int> solution(int N, vector<int> coffee_times) {
	totalN = N;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (coffee_times.size() < i) break;
		cof.push_back({ i,coffee_times[i] });
		idx++;
	}
	sort(cof.begin(), cof.end(), COMP);
	while (answer.size() != coffee_times.size()) {

		cof = checkNew();
		if (cof.size() < N) {
			while (idx < coffee_times.size() && cof.size() < N) {
				cof.push_back({ idx,coffee_times[idx] });
				idx++;
			}
			sort(cof.begin(), cof.end(), COMP);
		}
	}
	return answer;
}
int main() {
	int N;
	vector<int> coffee_times = {100,1,50,1,1 };
	N = 1;
	solution(N, coffee_times);
	return 0;
}