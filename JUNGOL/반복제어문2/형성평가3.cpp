#include <stdio.h>

int main(){
    int n,idx, sum=0;
    scanf("%d", &n);
    for (idx=1; idx<=n; idx++){
        if(idx%5==0){
            sum+=idx;
        }
    }
    printf("%d", sum);
    return 0;
}