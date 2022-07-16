#include <stdio.h>

int main(){
    int n, r, c, num=1;
    int arr[10][10] = {0};
    scanf("%d", &n);
    arr[n-1][0] = 1;
    arr[n - 2][0] = 1;
    arr[n - 2][1] = 1;
    for (r = n-1; r >=0;r--){
        for (c = 0; c < n-r; c++){
            if (r+1<n){
                if (c-1>=0){
                    arr[r][c] = arr[r+1][c]+arr[r+1][c-1];
                }
                else{
                    arr[r][c] = arr[r + 1][c];
                }
            }
        }
    }
    for (r = 0; r < n; r++){
        for (c = 0; c < n;c++){
            if (arr[r][c]!=0){
            printf("%d ", arr[r][c]);
            }
        }
        printf("\n");
    }
    return 0;
}