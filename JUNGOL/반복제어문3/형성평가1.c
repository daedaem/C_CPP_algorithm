#include <stdio.h>

int main(){
    int n,idx, sum=0, cnt=0;
    for (idx=1; idx<=20; idx++){
        scanf("%d", &n);
        if(n==0){
            printf("%d %d", sum, sum/cnt);
            break;
        }else{
            sum+=n;
            cnt++;
            if(cnt==20){
            }
        }
    } return 0;
}