#include <stdio.h>
int main(){
    int a[100], idx, cnt,temp;
    for (idx = 0; idx < 100; idx++){
        scanf("%d", &a[idx]);
        if(a[idx]== -1){
            cnt = idx - 1;
            if(cnt<3){
                for (temp = 0; temp < cnt;temp++){
                    printf("%d ", a[temp]);
                }
                break;
            }
            else{
                printf("%d %d %d", a[cnt - 2], a[cnt - 1], a[cnt]);
                break;
            }
        }
    }
    return 0;
}