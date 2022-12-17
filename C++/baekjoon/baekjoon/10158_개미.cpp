
#include <iostream>
using namespace std;
int W, H, w,h, T;
void solve() {
	int dx = T + w;
	int dy = T + h;
	
	if (dx > W) {
		int moc = dx / W;
		int nam = dx % W;
		if (moc % 2) dx = W - nam;
		else dx = nam;
	}
	if (dy > H) {
		int moc = dy / H;
		int nam = dy % H;
		if (moc % 2) dy = H - nam;
		else dy = nam;
	}
	cout << dx << " " << dy;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> W >> H >> w >> h >> T;
	solve();
	return 0;
}