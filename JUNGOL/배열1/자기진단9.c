#include <stdio.h>

int main(){
    int a[10], idx,idx2,temp;
    for (idx = 0; idx<10; idx++){
        scanf("%d", &a[idx]);
    }
    for (idx = 0; idx < 10-1; idx++){
        for (idx2 =0;idx2<10-1-idx;idx2++){
            if (a[idx2]<= a[idx2+1]){
                temp = a[idx2];
                a[idx2] = a[idx2 + 1];
                a[idx2 + 1] = temp;
            }
        }
    }
    for (idx = 0; idx < 10; idx++){
        printf("%d ", a[idx]);
    }
        
    return 0;
}