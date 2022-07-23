#define _CRT_SECURE_NO_WARNINGS
//================================
// 2439 - 별찍기1
//================================
#if 0
#include <stdio.h>
int main(void) {
	int n, r, c;
	scanf("%d", &n);
	for (r = 1; r <= n; r++) {
		for (c = 0; c < r; c++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 2439 - 별찍기2
//================================
#if 0
#include <stdio.h>

int main(void) {
	int n, r, c;
	scanf("%d", &n);
	for (r = 1; r <= n; r++) {
		for (c = 1; c <=n;c++) {
			if (c <= (n - r)) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 2440 - 별찍기3
//================================

#if 0
#include <stdio.h>

int main(void)
{
	int n, r, c;
	scanf("%d", &n);
	for (r = 0; r < n; r++) {
		for (c = n; c > r; c--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 2441 - 별찍기4
//================================
#if 0
#include <stdio.h>

int main(void)
{
	int n, r, c;
	scanf("%d", &n);
	for (r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			if (c < r) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 2442 - 별 찍기 - 5
//================================
#if 0
#include <stdio.h>
int main(void) 
{
	int r, left, c, n;
	scanf("%d", &n);
	for (r = 1; r <= n; r++) {
		for (left = n - r; left > 0; left--) {
			printf(" ");
		}
		for(c = 1; c <= (2 * r) - 1; c++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//int main(void) {
//	int r, c, n, total;
//	scanf("%d", &n);
//	total = (2 * n) - 1;
//	for (r = n; r >= 1; r--) {
//		for (c = 1; c <= total; c++) {
//			if ((c <= (r - 1)) || (c > total - (r - 1))) {
//				printf(" ");
//			}
//			else {
//				printf("*");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
#endif
	
//================================
// 2443 - 별 찍기 - 6
//================================
#if 0
#include <stdio.h>

int main(void) 
{
	int n, space,r, c;
	scanf("%d", &n);
	for (r = 0; r < n; r++) {
		for (space = 0; space < r; space++) {
			printf(" ");
		}
		for (c = 1; c <= (2*(n-r))-1 ; c++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 2444 - 별 찍기 - 7
//================================
#if 1
#include <stdio.h>

int main(void) 
{
	int n, space, sideR,sideC, center;
	scanf("%d", &n);
	for (sideR = 1; sideR <= n-1; sideR++) {
		for (space = n - 1; space >= sideR; space--) {
			printf(" ");
		}
		for (sideC = 1; sideC <= (2 * (sideR)) - 1; sideC++) {
			printf("*");
		}
		printf("\n");
	}

	for (center = 1; center <= (2*n)-1; center++) {
		printf("*");
	}
	printf("\n");

	for (sideR = 1; sideR <= n - 1; sideR++) {
		for (space = 1; space <= sideR; space++) {
			printf(" ");
		} 
		for (sideC = 2*(n - sideR)-1; sideC >= 1; sideC--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif

//================================
// 0000 - SCS
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void) {

	return 0;
}
#endif