#include <stdio.h>

int main(){
    int a[10], idx, oddsum = 0, oddcnt = 0, evensum = 0, evencnt = 0;
    // double avg;
    for (idx = 0; idx < 10; idx++){
        scanf("%d", &a[idx]);
    }
    for (idx = 0; idx < 10; idx++){
        if(idx%2==0){
            oddsum += a[idx];
            oddcnt++;
        }
        else{
            evensum += a[idx];
        }
    }
    printf("sum : %d\navg : %.1f", evensum, (double)oddsum / oddcnt);
    return 0;
}
