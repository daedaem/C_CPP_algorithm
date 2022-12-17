#include<iostream>
using namespace std;

int N, M;
int arr[10];
void DFS(int dep, int start){
	if (dep == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i=start; i<=N;i++){
		arr[dep] = i;
		DFS(dep + 1, i);
	}
}
int main(void) {
	cin >> N >> M;
	DFS(1, 1);
	
	return 0;
}
//#include <iostream>
//using namespace std;
//char arr[7];
//int visit[7];
//void DFS(int dep) {
//	if (dep == 4) {
//		for (int i = 1; i <= 3; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << '\n';
//		return;
//	}
//	for (int i = 1; i <= 3; i++) {
//		if (visit[i])continue;
//		visit[i] = 1;
//		arr[dep] = 'A'-1+i;
//		DFS(dep + 1);
//		visit[i] = 0;
//	}
//}
//int main(void) {
//	DFS(1);
//	return 0;
//}
//
////AAAAA EEEEE
////하나라도 같으면 안되는 1->5까지 숫자 세자리 조합
////하나라도 같으면 안되는 1->6까지 숫자 3자리 순열
//
