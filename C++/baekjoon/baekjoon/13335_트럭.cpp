#include <iostream>
#include <queue>
using namespace std;

#define MAX_N (1000)
#define MAX_W (100)

deque<int> trucks;
int bridge[MAX_W+1];
int N, W, L;

void input() 
{
	cin >> N >> W >> L;

	for (int i = 0; i < N; i++) {
		int tt; cin >> tt;
		trucks.push_back(tt);
	}
}
int bridge_moving() 
{
	int temp = 0;
	bridge[0] = 0;
	for (int i = 0; i < W; i++) {
		bridge[i] = bridge[i + 1];
		temp += bridge[i];
	}
	return L-temp;
}
int simulation() 
{
	int time = 1;
	for (;;) {
		// �ٸ��� �ϳ��� ���� �긮������ ���� ��
		int thistruck;
		int remain_weight = bridge_moving();
		if (!trucks.size() && remain_weight == L) return time; //�ٸ����ƹ��� ���� ����Ʈ���� ������
		if (trucks.size()) { // Ʈ���� ������ ������
			 thistruck = trucks.front();
			 if (!bridge[W - 1] && remain_weight >= thistruck) { 
				 //�ٸ� ���� �ƹ��� ���� ���� ���Ժ��� �۴ٸ�
				 bridge[W - 1] = thistruck;
				 trucks.pop_front();
			 }
		}
		time++;
	}
}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';

	return 0;
}