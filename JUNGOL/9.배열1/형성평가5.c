#include <stdio.h>

int main(){
    double a[6], sum = 0;
    int  i;
    for (i = 0; i < 6;i++){
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    printf("%.1f", (double)sum / 6);
    return 0;
}