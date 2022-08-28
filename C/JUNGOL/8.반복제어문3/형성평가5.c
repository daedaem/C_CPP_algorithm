#include <stdio.h>

int main(){
    int n,r,space,c;
    scanf("%d", &n);
    for (r = 1; r <= n;r++){
        for (space = 1; space <= (n-r)*2; space++){
            printf(" ");
        }
        for (c = 1; c <= r * 2 - 1; c++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
