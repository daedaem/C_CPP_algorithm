#include <stdio.h>

int main(){
    int a[10],idx,mins=1000;
    for(idx=0; idx<10; idx++){
        scanf("%d", &a[idx]);
    }
    for(idx=0; idx<10; idx++){
        if(a[idx] < mins){
            mins=a[idx];
        }
    }
    printf("%d", mins);
    return 0;
}