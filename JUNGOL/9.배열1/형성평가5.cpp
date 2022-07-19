#include <stdio.h>

int main(){
    double arr[6], sum = 0;
    int idx;
    for (idx = 0; idx < 6;idx++){
        scanf("%lf", &arr[idx]);
        sum += arr[idx];
    }
    printf("%.1f", (double) sum / 6);
}