#include <stdio.h>

int main(){
    int arr[5][5]={{1,1,1,1,1}},r,c;
    for (r=0; r<5; r++){
        arr[r][0]=1;
    }
    for (r = 1; r <= 4;r++){
        for (c = 1; c <= 4;c++){
            arr[r][c] = arr[r-1][c]+arr[r][c-1];
        }
    }
    for (r = 0; r < 5;r++){
        for (c = 0; c < 5;c++){
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
    return 0;
}
