#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[5];
    int idx, sum=0;
    for (idx = 0; idx < 5;idx++){
        scanf("%d", &arr[idx]);
        sum += abs(arr[idx]);
    }
    printf("%d", sum);
}
