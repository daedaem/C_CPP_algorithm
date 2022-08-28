#include <stdio.h>
int main(){
    int a[100],idx,cnt;
    for (idx = 0; idx < 100; idx++){
        scanf("%d", &a[idx]);
        if (a[idx]==0){
            cnt = idx;
            break;
        }
    }
    printf("%d\n", cnt);
    for (idx = 0; idx < cnt; idx++){
        if (a[idx]%2==1){
            printf("%d ", a[idx] * 2);
        }else{
            printf("%d ", a[idx] / 2);
        }
    }
    return 0;
}
