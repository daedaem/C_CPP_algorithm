#include <stdio.h>

int main(){
    int idx, stdNum, num;
    int scores[5]={0};
    for (idx = 1; idx < 5;idx++){
        printf("%dclass? ", idx);
        for (stdNum = 0; stdNum < 3; stdNum++){
            scanf("%d", &num);
            scores[idx]+= num;
        }
    }
    for (idx=1; idx<5;idx++){
        printf("%dclass : %d\n", idx, scores[idx]);
    }
    return 0;
}
