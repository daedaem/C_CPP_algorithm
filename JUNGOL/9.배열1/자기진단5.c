#include <stdio.h>

int main(){
    double classs[6] = {85.6, 79.5, 83.1, 80.0, 78.2, 75.0};
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.1f", (double)(classs[a-1]+classs[b-1]));
    return 0;
}
