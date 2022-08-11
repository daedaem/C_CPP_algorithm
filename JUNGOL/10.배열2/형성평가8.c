#include <stdio.h>

int main(){
    int arr[4][2], r, c,num, rsum,csum,tsum=0;
    for (r = 0; r < 4; r++){
        for (c = 0; c < 2;c++){
            scanf("%d", &arr[r][c]);
            tsum += arr[r][c];
        }
    }
    for (r = 0; r < 4; r++){
        csum = 0;
        for (c = 0; c < 2;c++){
            csum += arr[r][c];
        }printf("%d ", csum/2);
    }
    printf("\n");
    for (c = 0; c < 2;c++){
        rsum = 0;
        for (r = 0; r < 4; r++){
            rsum += arr[c][r];
        }printf("%d ", rsum/4);
    }
    printf("\n");
    printf("%d", tsum / 8);
    return 0;
}
