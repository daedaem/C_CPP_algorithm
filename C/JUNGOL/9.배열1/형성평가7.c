#if 1
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
#endif
#if 0
#include <stdio.h>

int main(){
    int arr[100], idx, a,maxx=0,minn=1000;
    for (idx = 0; idx < 100; idx++){
        scanf("%d", &arr[idx]);
        if (arr[idx]==999){
            break;

        }
    }
    for (a = 0; a < idx;a++){
            if (arr[a]>maxx){
                maxx = arr[a];
            }
            if (arr[a]<minn){
                minn = arr[a];
            }
    }
    printf("max : %d\nmin : %d", maxx, minn);
}
#end if