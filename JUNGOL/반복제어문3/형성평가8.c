#include <stdio.h>

int main(){
    int n,r, space,c, num=1;
    scanf("%d", &n);
    for (r = 0; r < n;r++){
        for (space = 1; space <= r;space++){
            printf("  ");
        }
        for (c = 1; c <= n-r;c++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
