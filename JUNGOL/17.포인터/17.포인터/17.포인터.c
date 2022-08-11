#define _CRT_SECURE_NO_WARNINGS
//----------------------------------------------------
// 예제
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif
//----------------------------------------------------
// 619 : 포인터 - 자가진단1 Special Judge
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void) 
{
	int n;
	int *adn;
	
	scanf("%d", &n);
	adn = &n;
	printf("%#p %d", adn, n);
	return 0;
}

#endif

//----------------------------------------------------
//  620 : 포인터 - 자가진단2
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	int n;
	int *adn = &n;
	scanf("%d", &n);
	printf("%d...%d", *adn / 10, *adn % 10);
	return 0;
}
#endif

//----------------------------------------------------
//  621 : 포인터 - 자가진단3
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	int a, b;
	int *ad = &a;
	int *ab =&b;
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", *ad, *ab, *ad + *ab);
	printf("%d - %d = %d\n", *ad, *ab, *ad - *ab);
	printf("%d * %d = %d\n", *ad, *ab, *ad * *ab);
	printf("%d / %d = %d\n", *ad, *ab, *ad / *ab);
	return 0;
}
#endif

//----------------------------------------------------
//  622 : 포인터 - 자가진단4
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	int arr[5];
	int* ad = arr;
	for (int i = 0; i < 5; i++) 
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		if (!(i % 2))
		{
			printf("%d ", *(ad+i));
		}
		
	}
	return 0;
}
#endif

//----------------------------------------------------
// 623 : 포인터 - 자가진단5
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	double arr[5];
	double* ad = arr;
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &arr[i]);
	}
	for (int i = 0; i < 5; i++)
	{	
		printf("%.1f ", *(ad + i));
	}
	return 0;
}
#endif

//----------------------------------------------------
// 624 : 포인터 - 자가진단6
//----------------------------------------------------
#if 0
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	double *a = (double*)malloc(sizeof(double)*n);
	double sum=0;

	for (int i = 0; i < n; i++) 
	{
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%.2f ", a[i]);
		sum += a[i];
	}
	printf("\n");
	printf("hap : %.2f\n", sum);
	printf("avg : %.2f\n", sum/n);
	free(a);

	return 0;
}
#endif

//----------------------------------------------------
// 625 : 포인터 - 자가진단7
//----------------------------------------------------
#if 1
#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
int main(void)
{
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i+1; j < n; j++) 
		{
			if (arr[i] < arr[j]) 
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
void swap(int *a, int *b) 
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif

//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif


//----------------------------------------------------
// 
//----------------------------------------------------
#if 0
#include <stdio.h>
int main(void)
{
	return 0;
}
#endif