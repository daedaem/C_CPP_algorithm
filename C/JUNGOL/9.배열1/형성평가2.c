#include <stdio.h>

int main(){
    int a[5],i, sum=0;
    for (i = 0; i < 5;i++){
        scanf("%d", &a[i]);
    }
    sum += a[0] + a[2] + a[4];
    printf("%d", sum);
    return 0;
}