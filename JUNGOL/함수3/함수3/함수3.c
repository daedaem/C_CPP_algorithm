#define _CRT_SECURE_NO_WARNINGS
//----------------------------------------------------
// 예제1.
//----------------------------------------------------
#if 0
#include <stdio.h>
void print_rep(int n);
void main(void)
{
	int n = 10;
	print_rep(n);
}
void print_rep(int n)
{
	if (n == 0) return;
	print_rep(n - 1);
	printf("%s\n", "조해성");
}
#endif
//----------------------------------------------------
// 자가진단1.
//----------------------------------------------------
#if 0
#include <stdio.h>
void print(int N);
void main(void)
{
	int n;
	scanf("%d", &n);
	print(n);
}
void print(int N) 
{
	if (N < 1) return;
	print(N - 1);
	printf("recursive\n");
}
#endif

//----------------------------------------------------
// 자가진단2.
//----------------------------------------------------
#if 0
#include <stdio.h>
void recursive(int N);
int main(void)
{
	int N;
	scanf("%d", &N);
	recursive(N);
	return 0;
}
void recursive(int N) 
{
	if (N < 1) return;
	printf("%d ", N);
	recursive(N - 1);
}
#endif

//----------------------------------------------------
// 자가진단3.
//----------------------------------------------------
#if 0
#include <stdio.h>
int recursive(int n);
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", recursive(n));
	return 0;
}
int recursive(int n) 
{
	if (n < 1) return n;
	return n+recursive(n - 1);
}
#endif

//----------------------------------------------------
// 자가진단4.
//----------------------------------------------------
#if 0
#include <stdio.h>
int pow(int n);
int main(void) 
{
	int n;
	scanf("%d", &n);
	printf("%d", pow(n));
	return 0;
}
int pow(int n) 
{
	if (n < 1) return (n%10)*(n%10);
	return (n % 10)*(n % 10) + pow(n / 10);
}
#endif

//----------------------------------------------------
// 예제5
//----------------------------------------------------
#if 0
#include <stdio.h>
int record[10000];
int N = 3;

int dice(int);
void print(void);
int main(void)
{
	
	//scanf("%d", &N);
	int visit[10] = { 0 };
	dice(0);
	return 0;
}
int dice(int th)
{
	if (th >= N) 
	{
		print();
		return;
	}
	for (int r = 0; r < 6; r++) 
	{
		record[th] = r+1;
		dice(th + 1);
	}
}
void print(void)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", record[i]);
	}
	printf("\n");
}
#endif
//----------------------------------------------------
// 자가진단5.
//----------------------------------------------------
#if 0
#include <stdio.h>

int N, arr[101];

void output()
{
	int i;
	for (i = 1; i <= N; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void dice(int level)
{
	int i;

	if (level > N) {
		output();
		return;
	}

	for (i = arr[level - 1]; i <= 6; i++) {
		arr[level] = i;
		dice(level + 1);
	}
}

int main()
{
	scanf("%d", &N);
	arr[0] = 1;

	dice(1);
	return 0;
}
#endif


#if 0
#include <stdio.h>
int dfs(int );
void printout(void);
int visited[10] = { 0 };
int arr[10000];
int N;

int main(void) 
{
	scanf("%d", &N);
	{
		dfs(0);
	}
	return 0;
}
int dfs(int step) 
{
	if (step >= N) 
	{
		printout();
		return;
	}
	for (int i = 0; i < 6; i++) 
	{
			//visited[i] = 1;
			arr[step] = i+1;
			dfs(step + 1);
			//visited[i] = 0;
	}
}
void printout(void) 
{
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return;
	}
	for (int i = 0; i < N; i++) 
	{
		printf("%d ", arr[i]);
	}	
	printf("\n");
	return;
}
#endif

//----------------------------------------------------
// 자가진단6.
//----------------------------------------------------
#if 0
#include <stdio.h>
int pibo(int n);
int arr[10000] = { 0 };
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", pibo(n));
	return 0;
}
int pibo(int n) 
{
	if (n == 1) return 1;
	return pibo(n / 2) + pibo(n - 1);
}
#endif
#if 0
#include <stdio.h>
int pibo(int n);
int arr[10000] = { 0 };
int main(void) 
{
	int N;
	
	scanf("%d", &N);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 2; i <= N; i++) 
	{
		arr[i] = pibo(i);
	}
	printf("%d", arr[N]);
	return 0;
}
int pibo(int n) 
{
	if (n < 3) 
	{
		return arr[n];
	}
	else 
	{
		if (arr[n])
		{
			return arr[n];
		}
		else 
		{
			return pibo((n / 2)) + pibo((n - 1));
		}
	}
	/*if (arr[n - 2] && arr[n - 1])
	{
		arr[n] = arr[n - 2] + arr[n - 1];
		return arr[n];
	}
	else 
	{ 
		arr[n] = pibo(n - 2) + pibo(n - 1); 
		return arr[n];
	}*/
}
#endif


//----------------------------------------------------
// 형성평가1.
//----------------------------------------------------
#if 0
#include <stdio.h>
void pibo(int);
int main(void) 
{
	int N;
	scanf("%d", &N);
	pibo(N);
}
void pibo(int n) 
{
	if (n == 1) 
	{
		printf("%d ", n);
		return;
	}
	else 
	{
		pibo(n/2);
		printf("%d ", n);
	}
	return;
}
#endif

//----------------------------------------------------
// 형성평가2.
//----------------------------------------------------
#if 0
#include <stdio.h>
void recur(int n);
int main(void) 
{
	int N;
	scanf("%d", &N);
	recur(N);
	return 0;
}
void recur(int n) 
{
	if (n % 2)
	{
		if (n == 1) 
		{
			printf("%d ", 1);
			return;
		}
		else 
		{
			recur(n - 2);
			printf("%d ", n);
		}
	}
	else 
	{
		if (n == 2)
		{
			printf("%d ", 2);
			return;
		}
		else
		{
			recur(n - 2);
			printf("%d ", n);
		}
	}
}
#endif

//----------------------------------------------------
// 형성평가3.
//----------------------------------------------------
#if 1
#include <stdio.h>
#endif

//----------------------------------------------------
// 형성평가4.
//----------------------------------------------------
#if 0
#endif

//----------------------------------------------------
// 형성평가5.
//----------------------------------------------------
#if 0
#endif

//----------------------------------------------------
// 형성평가6.
//----------------------------------------------------
#if 0
#endif