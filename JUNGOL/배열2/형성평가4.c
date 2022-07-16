#include <stdio.h>

int main(){
    int arr[4][3]={{3,5,9}, {2,11,5}, {8,30,10},{22,5,1}}, r,c, sum=0;
    for (r = 0; r < 4;r++){
        for (c = 0; c < 3;c++){
            printf("%d ",arr[r][c]);
            sum += arr[r][c];
        }
        printf("\n");
        printf("%d", sum);
        }
    return 0;
}