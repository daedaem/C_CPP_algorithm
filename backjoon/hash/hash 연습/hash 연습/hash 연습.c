#define _CRT_SECURE_NO_WARNINGS

// ---------------------------------------------------------------
// 1764 - 듣보잡 
// ------------------------------------------------------------
#if 0
#include <stdio.h>
int main(void) 
{
	int N, M;
	int len;
	int No_Listen[500000+10][22];
	int No_Seen[500000 + 10][22];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
	{
		scanf("%s", &No_Listen[i][22]);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", &No_Seen[i][22]);
	}
	//출력


	return 0;
}

#endif

// ---------------------------------------------------------------
// 11478 - 서로 다른 부분 문자열의 개수
// ------------------------------------------------------------
#if 1
#include <stdio.h>
#include <string.h>
int main(void)
{
	char words[1000+10];
	scanf("%s", words);
	for (int i = 0; i < strlen(words); i++) 
	{
		printf("%c ", words[i]);
	}
	return 0;
}

#endif