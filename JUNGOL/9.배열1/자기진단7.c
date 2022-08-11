#include <stdio.h>

int main(){
    int a[10], idx, maxx=1,minn=10000, maxcnt=0, mincnt=0;
    for (idx = 0; idx < 10; idx++){
        scanf("%d", &a[idx]);
        }
    for (idx = 0; idx < 10; idx++){
        if(a[idx]<100 & a[idx]>maxx){
            maxx = a[idx];
            maxcnt++;
        }
        if(a[idx]>=100 && a[idx]<minn){
            minn = a[idx];
            mincnt++;
        }
    }
    if(maxcnt==0){
        maxx = 100;
    }
    if(mincnt==0){
        minn = 100;
    }
    printf("%d %d", maxx, minn);
}