#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> estimates, int k) {
	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (i >= estimates.size()) break;
		answer += estimates[i];
		cnt += estimates[i];
	}
	for (int i = 0; i < estimates.size() - k; i++) {
		cnt = cnt - estimates[i] + estimates[i + k];
		if (answer < cnt) answer = cnt;
	}

	return answer;
}
////2번
//SELECT SUM(PRICE) AS 판매액
//FROM SELLINGS
//WHERE CREATED_AT LIKE '2016-11%'


