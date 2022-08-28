#include <stdio.h>

int main(){
    int idx, n, sums=0, cnt=0;
    scanf("%d", &n);
    for (idx = 1;;idx+=2){
        sums += idx;
        cnt++;
        if(sums>=n){
            printf("%d %d", cnt, sums);
            break;
        }
    }
        return 0;
}
