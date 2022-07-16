#include <stdio.h>

int main(){
    int a[7]={0}, idx,num;
    for (idx = 1; idx <= 10;idx++){
        scanf("%d", &num);
        a[num]++;
    }
    for (idx = 1; idx < 7;idx++){
        printf("%d : %d\n", idx, a[idx]);
    }
    return 0;
}