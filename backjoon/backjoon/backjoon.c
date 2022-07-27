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
#if 0
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
// 2445 - 별 찍기 - 8
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

void MakeStar(int n) 
{
	int i,j;
	for (i = 1; i <= 2 * n; i++) {
		if (i <= n) {
		for (j = 1; j <= 2 * n; j++) {
			
				if ((j <= i) || (j >= (2 * n +1 - i))) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		printf("\n");
		}
		else 
		{
			for (j = 1; j <= 2 * n; j++) {
				if ((j <= 2*n-i) || (j > i)) {
					printf("*");
				}
				else printf(" ");
			}
			printf("\n");
		}	
	}
	/*for (i = 0; i <= 2*n-1; i++) {
		for (j = 0; j <= 2 * n - 1; j++) 
		{
			if (j <= i||j>=((2*n-1)-i)) {
				printf("*");
			}
			else {
				printf(" ");
			}*/
			
}
int main(void) {
	int n;
	scanf("%d", &n);
	MakeStar(n);
	return 0;
}
#endif

//================================
// 2446 - 별찍기 9
//================================
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

void MakeStar(int n)
{
	int r, c;
	for (r = 1; r <= n; r++)
	{
		for (c = 1; c <= 2 * n -1 -(r-1);c++) 
		{
			if (c < r) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	for (r = n + 1; r <= 2 * n - 1; r++)
	{
		for (c = 1; c <= r; c++)
		{
			if (c <= (2 * n - 1) - r)
			{
				printf(" ");
			}
			else printf("*");
		}
		printf("\n");
	}
}
int main(int n) {
	scanf("%d", &n);
	MakeStar(n);
}
//	int r, c;
//	for (r = 1; r <= 2 * n - 1; r++)
//	{
//		if (r <= n)
//		{
//			for (c = 1; c <= 2 * n - 1; c++)
//			{
//				if ((c >= r) && (c <= 2 * n - r)) printf("*");
//				else printf(" ");
//			}
//			printf("\n");
//		}
//		// 중간단계부터 
//		else
//		{
//			//6 7 8 9
//			for (c = 1; c <= 2 * n - 1; c++)
//			{
//				if ((c <= r) && (c >= (2*n)-r))
//				{
//					printf("*");
//				}
//				else printf(" ");				
//			}
//			printf("\n");
//		}
//	}
//}

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
// 1676 - 팩토리얼 0의 개수
//================================
#if 0
#include <stdio.h>
void check(int n) 
{
	int idx, tcnt=0,fcnt=0;
	for (idx = 0; idx <= n; idx++) 
	{
		if (!(idx % 2)) tcnt++;
		if (!(idx % 5)) fcnt++;
		if (!(idx % 10)) 
		{
			printf()
		}

	}
}
int main(void) 
{
	int n;
	scanf("%d", n&);
	check(n);
}
#endif


//================================
//4673 - 셀프넘버
//================================
//1. 1부터 그 해당수까지 숫자들의셀프넘버를 구하기 위한 계산
//2. 생성자들 다 false 처리 - 내가 선택
#if 0
#include <stdio.h>
//int check(int i) 
//{
//	int start, sum=0;
//	for (start = 1; start <= i; start++) 
//	{
//		sum = 0;
//		int j;
//		j = start;
//		sum += j;
//		while(j>0)
//		{
//			sum += j % 10;
//			j /= 10;
//		}
//		if (sum == i) return 0;
//	}
//	return 1;
//}
//
//int main(void) 
//{
//	int i, result;
//	for (i=1; i <= 10000; i++) 
//	{
//		result = check(i);
//		if (result) 
//		{
//			printf("%d\n", i);
//		}
//	}
//}

int makenumber(int n) 
{
	int sum=0;
	sum += n;
	while (n > 0)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}
int main(void)
{
	int idx,j=1;
	unsigned long long int visited[10001] = { 0 };
	unsigned long long int arr[10001] = {0};
	for (idx = 1; idx <= 10000; idx++)
	{
 		if (arr[idx] == 0)
		{
			printf("%d\n", idx);
		}
		j = makenumber(idx);
		if (j > 10000) continue;
		if (arr[j] == 1)continue;
		arr[j] = 1;
		while (j<=10000) 
		{
			j = makenumber(j);
			if (j >= 10000) break;
			if (arr[j] == 1) continue;
			else arr[j] = 1;
		}
	}
}
#endif

//================================
//1929 - 소수구하기
//================================
#if 1
#include <stdio.h>
int arr[1000001] = {0};

void check(int m, int n)
{
	if (m <= 2) printf("%d\n", 2);
	arr[1]=1;
	int idx, j;
	for (idx = 2; idx <= n; idx++)
	{
		if ((idx >= 3) &&(idx>=m)&&(!arr[idx])) printf("%d\n", idx);
		for (j = 1; ; j++) {
			if (idx*j > n) break;
			if (arr[idx*j]==0)
			{
				arr[idx*j] = 1;
			}
		}
	}
}
int main(void)
{
	int m, n, temp;
	scanf("%d %d", &m, &n);
	if (m > n)
	{
		temp = m;
		m = n;
		n = temp;
	}
	check(m, n);
	return 0;
}

//int prime(int );
//void check(int , int);
//int main(void)
//{
//	int m, n,temp;
//	scanf("%d %d", &m, &n);
//	if (m > n) 
//	{
//		temp = m;
//		m = n;
//		n = temp;
//	}
//	check(m,n);
//}
//
//int prime(int n) 
//{
//	if (n == 2) return 1;
//	for (int i=2; i <= n / 2 + 1; i++)
//	{
//		if (!(n%i)) return 0;
//	}
//	return 1;
//}
//void check(int m, int n)
//{
//	for (m; m <= n; m++) 
//	{
//		if (prime(m)) printf("%d\n", m);
//	}
//}
#endif
