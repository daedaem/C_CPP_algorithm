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
// 10871 - x보다 작은수
//================================
#if 0
#include <stdio.h>

int main(void) {
	int N, X;
	int a;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a < X) printf("%d ", a);
	}
	return 0;
}
#endif

//================================
// 10817 - 세 수
//================================
#if 0
#include <stdio.h>

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A < B)
	{
		if (B > C) 
		{
			if (A < C) 
			{
				printf("%d", C);
			}
			else 
			{
				printf("%d", A);
			}
		}
		else 
		{
			printf("%d", B);
		}
	}
	else 
	{
		if (C > A) printf("%d", A);
		else 
		{
			if (B < C) printf("%d", C);
			else printf("%d", B);
		}
	}

	return 0;
}
#endif

//================================
// 11654 - 아스키 코드
//================================
#if 0
#include <stdio.h>

int main(void) {
	char a;
	scanf(" %c", &a);
	printf("%d", a);
	return 0;
}
#endif

//================================
// 11720 - 숫자의 합
//================================
//다시보자 이문자 어렵더라
#if 0
#include <stdio.h>
char number[101];

int main(void) {
	int N, sum=0;
	
	scanf("%d", &N);
	for (int i = 0; i<N; i++) 
	{
		scanf(" %c", &number[i]);
		sum += (number[i] - '0');
	}
	printf("%d", sum);
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
#if 0
#include <stdio.h>
int arr[1000001] = {0};
void check(int m, int n)
{
	arr[1] = 1;
	for (int i = 2; i <= n; i++) 
	{
		for (int j = i + i; j <= n; j += i) 
		{
			if (!(arr[j])) arr[j] = 1;
		}
	}
	for (int i = m; i <= n; i++) 
	{
		if (!(arr[i])) printf("%d\n", i);
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
	//if (m <= 2) printf("%d\n", 2);
	//arr[1]=1;
	//int idx, j;
	//for (idx = 2; idx <= n; idx++)
	//{
	//	if ((idx >= 3) &&(idx>=m)&&(!arr[idx])) printf("%d\n", idx);
	//	for (j = 1; ; j++) {
	//		if (idx*j > n) break;
	//		if (arr[idx*j]==0)
	//		{
	//			arr[idx*j] = 1;
	//		}
	//	}
	//}


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

//================================
//1978 - 소수 찾기
//================================
#if 0
#include <stdio.h>
int PrimeNumber(int n)
{
	if (n < 2) return 0;
	for (int idx = 2; idx < n; idx++)
	{
		if (!(n%idx)) return 0;
	}
	return 1;
}
int main(void)
{
	int n;
	int number, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &number);
		if (PrimeNumber(number)) sum++;
	}
	printf("%d", sum);
}
#endif

//================================
//2839- 설탕 배달
//================================
#if 0
#include <stdio.h>

int main(void)
{
	unsigned long long int min=5000/3;
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= N / 3; i++) 
	{
		for (int j = 0; j <= N / 5; j++) 
		{
			if ((i * 3 + j * 5) > N) break;
			else if ((i * 3 + j * 5) == N) 
			{
				if ((i + j) < min) min = i + j;
			}
		}
	}
	if (min == 5000 / 3) 
	{
		printf("%d", -1);
	}
	else printf("%d", min);
}

#endif

//================================
//11721 - 열 개씩 끊어 출력하기
//================================
#if 0
#include <stdio.h>
char N[101];

int main(void)
{

	for (int i = 1;; i++)
	{
		scanf("%c", &N[i]);
		if (N[i] == '\n')
		{
			break;
		}
		printf("%c", N[i]);
		if (!(i %= 10)) printf("\n");
	}
}

#endif

//================================
//9093 - 단어 뒤집기
//================================
#if 0
#include <stdio.h>
#include <string.h>

void changeWords(char temp[], int len);
int main(void)
{
	int T;
	int cnt = 0;
	int len;
	char arr[1010];
	char temp[30];
	scanf("%d ", &T);
	for (int i = 0; i < T; i++)
	{
		arr[1010];
		temp[30];
		gets(arr);
		len = strlen(arr);

		for (int j = 0; j <= len; j++)
		{
			if ((arr[j] == ' ') || (j == len))
			{
				changeWords(temp, cnt);
				cnt = 0;
			}
			else
			{
				temp[cnt] = arr[j];
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}
void changeWords(char temp[], int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%c", temp[i]);
		temp[i] = 0;
	}
	printf(" ");
}
#endif
//================================
//17413 - 단어 뒤집기2
//================================
#if 0
#include <stdio.h>
int main(void)
{
	
}
#endif

//================================
//10809 - 알파벳 찾기
//================================
//다시풀자 오래걸렸다
//우선 인덱스를 받아줄 record 배열을 -1로 다 초기화
//하나 받고 그 알파벳 위치에다가 인덱스 넣어주고

#if 0
#include <stdio.h>
#define SIZE(a) sizeof(a)/sizeof(a[0])

char alph[] = { "abcdefghizklmnopqrstuvwxyz" };

int main(void)
{
	char record['z'-'a'+1];
	char word;
	int lengths;
	for (int i = 0; i < SIZE(record); i++) 
	{
		record[i] = -1;
	}

	for (int i = 0;; i++)
	{
		scanf("%c", &word);
		if (word == '\n') 
		{ 
			lengths = i;
			break;
		}
		if (record[word - 'a'] == -1)
			record[word - 'a'] = i;
	}
	for (int i = 0; i < SIZE(record); i++)
	{
		printf("%d ", record[i]);
	}
}
#endif

//================================
//2675 - 문자열 반복
//================================
//string.h strlen 함수 기억하자
// string으로 받을 수 있다는것 잊지말자
#if 0
#include <stdio.h>
#include <string.h>
int main(void)
{
	int T;
	int n;
	char word[20];
	scanf("%d", &T);
	for (int i=0; i < T; i++) 
	{
		scanf("%d %s", &n, &word);
		for (int start = 0; start < strlen(word); start++) 
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c", word[start]);
			}
		}
		printf("\n");
	}
	//for (int i = 0; i < len; i++) 
	//{
	//	for (int j = 0; j < n; j++) 
	//	{
	//		printf("%c",words[])
	//	}
	//}

}
#endif

//================================
//2675 - 문자열 반복
//================================
#if 0
#include <stdio.h>
#include <string.h>
void changeword(char [], int);

int main(void)
{
	int T;
	char text[1001];
	char temp;
	char word[20];
	int cnt=0;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) 
	{
		gets(text);
		//마지막 글자 확인 꼭
		for (int j = 0; j < strlen(text) - 1; j++) 
		{
			if ((text[j + 1] == ' ')) 
			{
				changeword(word, cnt);
				cnt = 0;
				word[20];
				continue;
			}
			if (text[j] ==' ') printf(" ");
			else 
			{	
				word[cnt] = text[j];
				cnt++;
			}
		}	
	}
}
void changeword(char word[], int len)
{
	for (int i = len; i >= 0; i--)
	{
		printf("%c", word[i]);
	}	
}
#endif
//================================
//1157 - 단어 공부
//================================
#if 0
#include <stdio.h>
#include <string.h>
int alph[('z'-'a')+10];
int main(void)
{
	char array[1000010];
	char word;
	int maxx = 0;
	int cnt = 1;
	scanf("%s", array);
	int len = strlen(array);
	for (int i = 0; i < len; i++)
	{
		int index;
		//만약 대문자면
		if ((array[i] >= 'A') && (array[i] <= 'Z'))
		{
			index = array[i] - 'A';
			alph[index] += 1;
		}
		// 소문자면
		if (((array[i] >= 'a') && (array[i] <= 'z')))
		{
			index = array[i] - 'a';
			alph[index] += 1;
		}
		// 만약에
		if (maxx == alph[index])
		{
			cnt++;
		}
		if (maxx < alph[index])
		{
			cnt = 1;
			word = 'A'+index;
			maxx = alph[index];
		}
	}
	if (cnt >= 2) printf("?");
	else
	{
		if ((word >= 'a') && (word <= 'z'))
		{
			printf("%c", word + ('a' - 'A'));
		}
		else printf("%c", word);
	}
	return 0;
}
#endif

//================================
//1152 - 단어의 개수
//================================
// 진짜 그지같은 문제 fgets로 못 풀겠음
#if 0
#include <stdio.h>
#include <string.h>
int func(char word)
{
	if ((word >= 'a') && (word <= 'z')) return 1;
	if ((word >= 'A') && (word <= 'Z')) return 1;
	return 0;
}
int main()
{
	char words[1000010];
	int sum = 0;
	int len;
	int cnt = 0;
	gets(words);
	len = strlen(words);
	for (int i = 0; i < len; i++)
	{
		//맨 앞에가 공백인 경우
		// 숫자세야할 때,
		if ((func(words[i])) && ((words[i + 1] == ' ') || (words[i + 1] == '\0')))
			sum++;
	}
	printf("%d", sum);

	return 0;
}
#endif

//---------------------------------------------------------------------
//10870 - 피보나치 수 5
//---------------------------------------------------------------------
#if 0
#include <stdio.h>
int pibonacci(int n);

int pibo[20 + 10] = { 0,1,1, };

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) 
	{
		pibo[i] = pibonacci(i);
	}
	printf("%d", pibo[n]);
	return 0;
}
int pibonacci(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return pibonacci(n-1) + pibonacci(n - 2);
}
#endif


//---------------------------------------------------------------------
//17478 - 재귀함수가 뭔가요?
//---------------------------------------------------------------------
#if 0
#include <stdio.h>
int main(void) 
{
	
	// - * 4배수, 재귀함수가 뭔가요? 부터 선비에게 찾아와서 물었어 부분 n만큼 반복
	return 0;
	//라고 답변했지.
	//n부분에는

}
#endif
