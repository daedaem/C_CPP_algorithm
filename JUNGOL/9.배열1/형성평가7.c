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