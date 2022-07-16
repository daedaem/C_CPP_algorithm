#include <stdio.h>

int main(){
    int a[100],i, maxx=-10000,minn=10000;
    for (i = 0; i < 100; i++){
        scanf("%d", &a[i]);
        if (a[i]==999){
            printf("max : %d\nmin : %d", maxx, minn);
            break;
        }else{
            if (a[i]>maxx){
                maxx = a[i];
            }
            if(a[i]<minn){
                minn = a[i];
            }
        }
    }
    return 0;
}