#include <stdio.h>

int main(void) {
	int pay, mods;
	int namer;
	int fives, hund;
	int minn = namer/100+1;
	int hunds, fives;
	int hundsrecord, fivesrecord
	scanf("%d %d", &pay, &mods);
	namer = pay - mods;
	for (hunds = 0; ; hunds++) {
		for (fives = 0; fives++) {
			if ((hunds * 100 + fives * 500) >namer) {
				continue
			}
			else if ((hunds * 100 + fives * 500) < namer) {
				continue
			}
			else if (hunds * 100 + fives * 500 == namer) {
				if (minn < hunds + fives;) {
					minn = hunds + fives;
					hundsrecord = hunds;
					fivesrecord = fives;
				}
			}
		}
	}
	printf("%d\n%d\n%d", namer, hundsrecord, fivesrecord);
}
}