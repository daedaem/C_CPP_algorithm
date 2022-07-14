#include <stdio.h>

int main(){
    int row,idx, idx2, n, numb=1, charc='A';
    scanf("%d", &n);
    for (row = 1; row <= n; row++){
        for (idx = 1; idx <= n + 1 - row; idx++)
        {
            printf("%d ", numb);
            numb++;
        }
        for (idx2 = 1; idx2 <= row; idx2++){
            printf("%c ", charc);
            charc++;
        }
        printf("\n");
    }
    return 0;
}
