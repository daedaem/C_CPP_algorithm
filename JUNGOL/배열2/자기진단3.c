#include <stdio.h>

int main(){
    int a[100],n,idx;
    a[0] = 100;
    scanf("%d", &n);
    a[1] = n;
    while(1){
        for (n = 2;;n++){
            a[n] = a[n - 2]-  a[n - 1];
            if (a[n]<0){
                for (idx=0; idx<=n; idx++){
                    printf("%d ", a[idx]);
                }
                break;
            }
        }break;
    }
    return 0;
}
