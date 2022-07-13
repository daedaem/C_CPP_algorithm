#include <stdio.h>

int main(){
    int n,idx, num,sum=0;
    double avg;
    scanf("%d",&n);
    for (idx=1; idx<=n; idx++){
        scanf("%d",&num);
        sum+=num;
    }
    avg = (double)sum / n;
    printf("%.2f", avg);
    //printf("%.2f", (double)sum/)
    return 0;
}
