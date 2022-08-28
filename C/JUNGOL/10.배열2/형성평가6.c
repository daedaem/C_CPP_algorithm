#include <stdio.h>

int main(){
    int arr[5][5]={0}, r,c;
    arr[0][0]=1, arr[0][2]=1, arr[0][4] = 1;
    for (r = 1; r < 5; r++){
        for (c = 0; c < 5; c++){
            if (c-1<0){
                arr[r][c] = arr[r-1][c+1];
            }
            else if (c+1>4){
                arr[r][c] = arr[r - 1][c-1];
            }
            else{
                arr[r][c] = arr[r - 1][c-1] + arr[r-1][c+1];
            }
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
