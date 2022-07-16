#include <stdio.h>

int main(){
    int a[100],idx, count;
    for (idx = 0; idx < 100; idx++){
        scanf("%d", &a[idx]);
        if (a[idx]==0){
            break;
        }
    }
    count = idx-1;
    for (idx = count; idx >=0;idx--){
        printf("%d ",a[idx]);
    }
    return 0;
}