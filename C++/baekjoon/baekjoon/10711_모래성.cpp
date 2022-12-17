#if 1
#include <iostream>
#include <vector>
#include <queue>
#define MAX_HW (1000)
using namespace std;

struct POS {
	int r, c;
};
int H, W;
int maps[MAX_HW + 2][MAX_HW + 2];
queue<POS>q;
int times;
void input() {
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char cc; cin >> cc;
			if (cc == '.') {
				maps[r][c] = 0;
				q.push({ r,c });
			}
			else maps[r][c] = cc - '0';
		}
	}
}
int simulation() {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	POS data;
	while (!q.empty()) {
		int len = q.size(); //
		for (int i = 0; i < len; i++) {
			data = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				POS newdata = data;
				newdata.r += dr[i];
				newdata.c += dc[i];
				if (newdata.r < 0 || newdata.c < 0 || newdata.r >= H || newdata.c >= W) continue;
				if (maps[newdata.r][newdata.c]) {
					maps[newdata.r][newdata.c] -= 1;
					if (maps[newdata.r][newdata.c] == 0) {
						q.push(newdata);
					}
				}
			}
		}
		if (q.empty()) return times; // 만약 더이상 깎일 새로운 모래가 없으면
		times++; // 

	}
	return	times;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#define MAX_HW (1000)
using namespace std;

struct POS {
	int r, c, times;
};
int H, W;
int maps[MAX_HW + 2][MAX_HW + 2];
queue<POS>q;
void input() {
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for(int c=0; c<W;c++){
			char cc; cin >> cc;
			if (cc == '.') {
				maps[r][c] = 0;
				q.push({ r,c,0 });
			}
			else maps[r][c] = cc - '0';
		}
	}
}
int simulation() {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	POS data;
	while (!q.empty()) {
		data = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			POS newdata = data;
			newdata.r += dr[i];
			newdata.c += dc[i];
			if (newdata.r < 0 || newdata.c < 0 || newdata.r >= H || newdata.c >= W) continue;
			if (maps[newdata.r][newdata.c]) {
				maps[newdata.r][newdata.c] -= 1;
				if (maps[newdata.r][newdata.c] == 0) {
					newdata.times += 1;
					q.push(newdata);
				}
			}
		}
	}
	return data.times;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}
#endif
#if 0 // 시간초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define MAX_HW (1000)

struct SAND {
	int r, c, total;
};
struct POS {
	int idx, r, c;
};
int maps[MAX_HW + 2][MAX_HW + 2];
int H, W;
map<int, SAND> sands; // 총 모래
deque<POS> eraselist; //지워야할 모래번호들
void input() {
	cin >> H >> W;
	int sandidx = 1;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char cc; cin >> cc;
			if (cc == '.') {
				maps[r][c] = 0;
			}
			else {
				maps[r][c] = sandidx;
				sands.insert({ sandidx, {r,c,  cc - '0'} });
				sandidx++;
			}
		}
	}
}
void print() {
	cout << "orign" << '\n';
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cout << maps[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int recordEraseSand(SAND nowsand) {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	int r = nowsand.r;
	int c = nowsand.c;
	int sandcnt = nowsand.total;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue;
		if (!maps[dy][dx]) cnt++;
		if (cnt >= sandcnt) return 0;// 지우자
	}
	return 1;

}
void init() {
	auto it = sands.begin();
	while (it != sands.end()) {
		if (it->second.total == 9) {
			it++;
			continue;
		}
		int ret = recordEraseSand(it->second);
		if (!ret) eraselist.push_back({it->first, it->second.r, it->second.c}); // 지워야하는 모래번호 입력
		it++;
	}
	//지우기
	for (int i = 0; i < eraselist.size(); i++) {
		int sandidx = eraselist[i].idx;
		int r = sands.find(sandidx)->second.r;
		int c = sands.find(sandidx)->second.c;
		maps[r][c] = 0;
	}
}
int recordsand(int nr, int nc, int idx) {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	int r = nr;
	int c = nc;
	int sandcnt = sands[idx].total;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue;
		if (!maps[dy][dx]) cnt++;
		if (cnt >= sandcnt) return 0;// 지우자
	}
	return 1;
}
int simulation() {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	init();
	for (int times = 0; ;times++) {
		int lens = eraselist.size();
		if (lens == 0) return times;
		// 파도로 없어진 부분 8방향 체크해서 부수기
		for (int i = 0; i < lens; i++) {
			POS data = eraselist.front(); eraselist.pop_front();
			
			for (int i = 0; i < 8; i++) { // 파도에의해 없어진 모래 8방향 체크
				int dy = data.r + dr[i];
				int dx = data.c + dc[i];
				if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue;
				if(!maps[dy][dx]) continue;
				
				int ret = recordsand(dy, dx, maps[dy][dx]); // 해당 공간에 모래가 있으면 그곳이 지워질 새로운 녀석인지 체크
				if (!ret) eraselist.push_back({ maps[dy][dx], dy,dx });// 지워야하는 녀석이면 새 wave니까 추가
			}
		}
		for (int i = 0; i < eraselist.size(); i++) {
			int r = eraselist[i].r;
			int c = eraselist[i].c;
			//sands.erase(maps[r][c]);
			maps[r][c] = 0;
		}
	}
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}
#endif
#if 0 //시간초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX_HW (1000)

struct SAND{
	int r,c, total;
};
struct POS {
	int r, c;
};
int maps[MAX_HW + 2][MAX_HW + 2];
int H, W;
map<int, SAND> sands; // 총 모래
vector<int>eraselist; //지워야할 모래번호들
void input() {
	cin >> H >> W;
	int sandidx = 1;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char cc; cin >> cc;
			if (cc == '.') {
				maps[r][c] = 0; 
			} 
			else {
				maps[r][c] = sandidx++;
				sands.insert({ sandidx, {r,c,  cc - '0'} });
			}
		}
	}
}
void print() {
	cout << "orign" << '\n';
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
int recordEraseSand(SAND nowsand){
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	int r = nowsand.r;
	int c = nowsand.c;
	int sandcnt = nowsand.total;
	int cnt = 0;
	for(int i=0; i<8;i++){
		int dy = r + dr[i];
		int dx = c + dc[i];
		if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue;
		if (!maps[dy][dx]) cnt++;
		if (cnt >= sandcnt) return 0;// 지우자
	}
	return 1;

}
int simulation() {
	int times = 0;
	while (1) {
		auto it = sands.begin();
		while (it != sands.end()) {
			if (it->second.total == 9) {
				it++;
				continue;
			}
			int ret = recordEraseSand(it->second);
			if (!ret) eraselist.push_back(it->first); // 지워야하는 모래번호 입력
			it++;
		}
		//지우기
		int flag = 0;
		for (int i = 0; i < eraselist.size(); i++) {
			int sandidx = eraselist[i];
			int r = sands.find(sandidx)->second.r;
			int c = sands.find(sandidx)->second.c;
			maps[r][c] = 0;
			sands.erase(sandidx);
			flag = 1;
		}
		if (!flag) return times;
		times ++;
	}
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}
#endif

#if 0//시간초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_HW (1000)

struct POS {
	int r, c;
};
char maps[MAX_HW + 2][MAX_HW + 2];
char backupMaps[MAX_HW + 2][MAX_HW + 2];
vector<POS> eraseSand;
int H, W;
void input(){
	cin >> H >> W;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cin >> maps[r][c];
		}
	}
}
void print() {
	cout << "orign" << '\n';
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cout << maps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "backup" << '\n';
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cout << backupMaps[r][c];
		}
		cout << '\n';
	}
	cout << '\n';
}
int checksame() {
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			if (maps[r][c] != backupMaps[r][c]) return 0;
		}
	}
	return 1;
}
int add_erase_sand(int nr, int nc) {
	static int dr[] = { -1,-1,0,1,1,1,0,-1 };
	static int dc[] = { 0,1,1,1,0,-1,-1,-1 };
	int numb = maps[nr][nc]-'0';
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int dy = nr + dr[i];
		int dx = nc + dc[i];
		if (dy<0 || dx<0 || dy>=H || dx>=W) continue;
		if (maps[dy][dx] == '.') cnt++;
		if (numb <= cnt) return 0; // 무너져야함
	}
	return 1;
}
void breakSand() {
	for(int i=0; i<eraseSand.size();i++){
		//cout << eraseSand[i].r << " " << eraseSand[i].c << '\n';
		maps[eraseSand[i].r][eraseSand[i].c] = '.';
	}
}
int simulation(){
	//print();
	int times = 0;
	while (1) {
		copy(&maps[0][0], &maps[MAX_HW + 1][MAX_HW + 2], &backupMaps[0][0]);// 이전 상태 백업
	//	cout << "#time "<<times << '\n';
		//cout << "#before "<< '\n';
		//print();
		//무너질 격자 파악
		for (int r = 0; r < H; r++) { 
			for (int c = 0; c < W; c++) {
				if (maps[r][c]=='.') continue;
				if (maps[r][c] = '9') continue; // 안해봐도 알자나
				int ret = add_erase_sand(r,c);
				if (!ret) eraseSand.push_back({ r,c });
			}
		}
		breakSand();
//		cout << "#after " << '\n';
		//print();
		int ret = checksame();
		if (ret) {
			return times;
		}
		times++;	
	}
	
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	cout << simulation() << '\n';
	return 0;
}
#endif